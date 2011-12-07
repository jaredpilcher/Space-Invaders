------------------------------------------------------------------------------
-- audioDMA.vhd
--
------------------------------------------------------------------------------
-- Filename:          audioDMA.vhd
-- Version:           1.00.c
-- Description:       Lab #8 master/slave I/O core
-- Date               12/05/2007
--
-- By Matt Diehl & Eric Nielsen
--
------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;		
--use ieee.std_logic_arith.all;

------------------------------------------------------------------------------
-- Entity section
------------------------------------------------------------------------------
-- Definition of Generics:
--   C_BASEADDR                   -- User logic base address
--   C_HIGHADDR                   -- User logic high address
--   C_OPB_AWIDTH                 -- OPB address bus width
--   C_OPB_DWIDTH                 -- OPB data bus width
--   C_FAMILY                     -- Target FPGA architecture
--
-- Definition of Ports:
--   OPB_Clk                      -- OPB Clock
--   OPB_Rst                      -- OPB Reset
--   Sl_DBus                      -- Slave data bus
--   Sl_errAck                    -- Slave error acknowledge
--   Sl_retry                     -- Slave retry
--   Sl_toutSup                   -- Slave timeout suppress
--   Sl_xferAck                   -- Slave transfer acknowledge
--   OPB_ABus                     -- OPB address bus
--   OPB_BE                       -- OPB byte enable
--   OPB_DBus                     -- OPB data bus
--   OPB_RNW                      -- OPB read/not write
--   OPB_select                   -- OPB select
--   OPB_seqAddr                  -- OPB sequential address
------------------------------------------------------------------------------

entity audio_dma is
  generic
  (
    -- Bus protocol parameters, do not add to or delete
    C_BASEADDR                     : std_logic_vector(0 to 31)     := X"40090000";
    C_HIGHADDR                     : std_logic_vector(0 to 31)     := X"4009FFFF";
    C_OPB_AWIDTH                   : integer              := 32;
    C_OPB_DWIDTH                   : integer              := 32;
    C_FAMILY                       : string               := "virtex2p"
  );
  port
  (
    -- Bus protocol ports, do not add to or delete
    OPB_Clk                        : in  std_logic;
    OPB_Rst                        : in  std_logic;
    OPB_DBus                       : in  std_logic_vector(0 to C_OPB_DWIDTH-1);
    OPB_errAck                     : in  std_logic;
    OPB_MGrant                     : in  std_logic;
    OPB_retry                      : in  std_logic;
    OPB_timeout                    : in  std_logic;
    OPB_xferAck                    : in  std_logic;
    OPB_ABus                       : in  std_logic_vector(0 to 31);
    OPB_BE                         : in  std_logic;
    OPB_RNW                        : in  std_logic;
    OPB_select                     : in  std_logic;
    OPB_seqAddr                    : in  std_logic;
    M_ABus                         : out std_logic_vector(0 to C_OPB_AWIDTH-1);
    M_BE                           : out std_logic_vector(0 to C_OPB_DWIDTH/8-1);
    M_busLock                      : out std_logic;
    M_DBus                         : out std_logic_vector(0 to C_OPB_DWIDTH-1);
    M_request                      : out std_logic;
    M_RNW                          : out std_logic;
    M_select                       : out std_logic;
    M_seqAddr                      : out std_logic;
    Sl_DBus                        : out std_logic_vector(0 to C_OPB_DWIDTH-1);
    Sl_errAck                      : out std_logic;
    Sl_retry                       : out std_logic;
    Sl_toutSup                     : out std_logic;
    Sl_xferAck                     : out std_logic;
    AC97Int                        : in  std_logic
  );

  attribute SIGIS : string;
  attribute SIGIS of OPB_Clk       : signal is "Clk";
  attribute SIGIS of OPB_Rst       : signal is "Rst";

end entity audio_dma;

architecture dma of audio_dma is
	type state_type is (idle, read_audio, arbitrary_write_step, write_audio, write_silence);
	signal next_state, current_state: state_type := idle;
	
	--Used when write to an address that isn't set up yet
	signal our_value, our_value_next: std_logic_vector(0 to 31) := "10101010101010101010101010101010";
	
	--Signals for opb_master
	signal enable_reg : std_logic;
	signal control_reg, control_reg_next : std_logic_vector(0 to 31);
	signal master_enable : std_logic := '0';
	signal master_rnw_reg, master_rnw_reg_next, master_idle_out: std_logic := '0';
	signal master_address_reg, master_address_reg_next, master_data_reg, master_data_reg_next, master_data_out: std_logic_vector(0 to 31);
	signal data_out: std_logic_vector(0 to 31);
	signal destination, destination_next: std_logic_vector(0 to 31);
	signal cur_index, next_index: std_logic_vector(0 to 31);
	signal channel_addr_we, channel_length_we: std_logic;
	signal channel_data, channel_addr_out, channel_length_out: std_logic_vector(0 to 31);
	signal channel_select: std_logic_vector(0 to 2);
	signal interrupt: std_logic;
	signal global_enable: std_logic;
	signal looping: std_logic;
	signal arbitrary_write_next, arbitrary_write: std_logic;
	signal arbitrary_address_next, arbitrary_address, arbitrary_data_next, arbitrary_data: std_logic_vector(0 to 31);
	
	
	component opb_master is
     port
	  (
		clk      : in std_logic;
		enable 	 : in std_logic;
		address	 : in std_logic_vector(0 to 31);
		rnw		 : in std_logic;
		data	 : in std_logic_vector(0 to 31);
		data_out : out std_logic_vector(0 to 31);
		idle_out : out std_logic;
		
		OPB_DBus : in  std_logic_vector(0 to 31);
		OPB_MGrant: in std_logic;
		OPB_xferAck : in  std_logic;
		M_ABus   : out std_logic_vector(0 to 31);
		M_BE     : out std_logic_vector(0 to 3);
		--    M_busLock: out std_logic;
		OPB_errAck                     : in  std_logic;
		OPB_retry                      : in  std_logic;
		OPB_timeout                    : in  std_logic;
		M_DBus   : out std_logic_vector(0 to 31);
		M_request: out std_logic;
		M_RNW    : out std_logic;
		M_select : out std_logic
	--    M_seqAddr: out std_logic;
	
	  );
	end component opb_master;

	component channel_bank is
	  port
	  (
		clk      : in std_logic;
		chan_sel_in : in std_logic_vector(0 to 2);
		addr_we	 : in std_logic;
		length_we: in std_logic;
		data_in  : in std_logic_vector(0 to 31);
		addr_out : out std_logic_vector(0 to 31);
		length_out:out std_logic_vector(0 to 31)
	  );
	  
	end component channel_bank;  
	
begin

	process(OPB_Clk)
	begin
		if(OPB_Clk'event and OPB_Clk='1') then
			current_state<=next_state;
			our_value <= our_value_next;
			control_reg <= control_reg_next;
			destination <= destination_next;
			master_address_reg <= master_address_reg_next;
			master_data_reg <= master_data_reg_next;
			master_rnw_reg <= master_rnw_reg_next;
			cur_index <= next_index;
			arbitrary_write <= arbitrary_write_next;
			arbitrary_address <= arbitrary_address_next;
			arbitrary_data <= arbitrary_data_next;
        end if;
    end process;
	
	process(current_state, OPB_MGrant, OPB_xferAck,OPB_select, OPB_RNW, OPB_ABus, OPB_DBus, OPB_Clk, master_idle_out)
	begin
		next_state <= current_state;
		next_index <= cur_index;
		master_address_reg_next <= master_address_reg;
		master_data_reg_next <= master_data_reg;
		master_rnw_reg_next <= master_rnw_reg;
		destination_next <= destination;
		Sl_xferAck <= '0';
		our_value_next <= our_value;
		master_enable <= '0';
		data_out <= X"00000000";
		channel_addr_we <= '0';
		channel_length_we <= '0';
		control_reg_next <= control_reg;
		arbitrary_write_next <= arbitrary_write;
		arbitrary_address_next <= arbitrary_address;
		arbitrary_data_next <= arbitrary_data;
		case current_state is
			when idle =>
				-- if arbitrary_write = '1' then
					-- next_state <= arbitrary_write_step;
				if global_enable = '1' and interrupt = '1' and master_idle_out = '1' then
					if enable_reg = '1' and (cur_index /= channel_length_out) then
						next_state <= read_audio;
					else
						next_state <= write_silence;
					end if;
				end if;
			-- when arbitrary_write_step =>
				-- if master_idle_out = '1' then
					-- master_enable <= '1';
					-- master_address_reg_next <= arbitrary_address;
					-- master_data_reg_next <= arbitrary_data;
					-- master_rnw_reg_next <= '0';
					-- arbitrary_write_next <= '0';
					-- next_state <= idle;
				-- end if;
			when read_audio =>
				if master_idle_out = '1' then
					master_enable <= '1';
					master_address_reg_next <= channel_addr_out + cur_index;
					--next_index <= cur_index + unsigned(4);
					--next_index <= cur_index + 4;
					--master_data_reg_next <= master_data_out;
					master_rnw_reg_next <= '1';
					next_state <= write_audio;
					--next_state <= idle;
				end if;
			when write_silence =>
				if master_idle_out = '1' then
					master_enable <= '1';
					master_address_reg_next <= destination;
					master_data_reg_next <= (others => '0');
					master_rnw_reg_next <= '0';
					next_state <= idle;
				end if;
				next_state <= idle;
			when write_audio =>
				if master_idle_out = '1' then
					master_enable <= '1';
					master_address_reg_next <= destination;
					master_data_reg_next <= master_data_out;
					master_rnw_reg_next <= '0';
					next_state <= idle;
					next_index <= cur_index + 4;
					if (looping = '1') and (next_index = channel_length_out) then
						next_index <= (others => '0');
					end if;
				end if;
			when others =>
				next_state <= idle;
		end case;
		
		if OPB_select = '1' then
			if OPB_ABus >= C_BASEADDR and OPB_ABus <= C_HIGHADDR then
				if OPB_RNW = '1' then
					case OPB_ABus is
						when C_BASEADDR =>
							data_out <= control_reg;
						when C_BASEADDR + 4 =>
							data_out <= channel_addr_out;
						when C_BASEADDR + 8 =>
							data_out <= channel_length_out;
						when C_BASEADDR + 12 =>
							data_out <= master_data_out;
						when C_BASEADDR + 16 =>
							data_out <= X"0000000" & "000" & arbitrary_write;
						when others =>
							data_out <= X"00000000";
					end case;
					Sl_xferAck <= '1';
				else
					case OPB_ABus is
						when C_BASEADDR =>
							control_reg_next <= OPB_DBus;
							if (control_reg_next(29 to 31) /= control_reg(29 to 31)) or control_reg_next(26) = '1' then
								next_index <= (others => '0');
							end if;
						when C_BASEADDR + 4 =>
							channel_data <= OPB_DBus;
							channel_addr_we <= '1';
						when C_BASEADDR + 8 =>
							channel_data <= OPB_DBus;
							channel_length_we <= '1';
						when C_BASEADDR + 12 =>
							destination_next <= OPB_DBus;
						when C_BASEADDR + 16 =>
							arbitrary_address_next <= OPB_DBus;
						when C_BASEADDR + 20 =>
							arbitrary_data_next <= OPB_DBus;
							arbitrary_write_next <= '1';
						when others =>
					end case;
					Sl_xferAck <= '1';
				end if;
			end if;
		end if;
	end process;
	
	interrupt <= AC97Int;
	enable_reg <= control_reg(28);
	global_enable <= control_reg(27);
	looping <= control_reg(25); 
    M_busLock <= '0';
    M_seqAddr <= '0';
	
	Sl_DBus <= 	data_out;

    Sl_errAck <= '0';
    Sl_retry <= '0';
    Sl_toutSup <= '0';
	
	master : opb_master port map ( 
        clk => OPB_Clk,
		enable => master_enable,
		address	=> master_address_reg,
		rnw => master_rnw_reg,
		data => master_data_reg,
		data_out => master_data_out,
		idle_out => master_idle_out,
		OPB_DBus => OPB_DBus,
		OPB_MGrant => OPB_MGrant,
		OPB_xferAck => OPB_xferAck,
		OPB_errAck => OPB_errAck,
		OPB_retry => OPB_retry,
		OPB_timeout => OPB_timeout,
		M_ABus => M_ABus,
		M_BE => M_BE,
		--    M_busLock: out std_logic;
		M_DBus => M_DBus, 
		M_request => M_request,
		M_RNW => M_RNW,
		M_select => M_select
	);
	
	channels: channel_bank port map (
		clk => OPB_Clk,
		chan_sel_in => control_reg(29 to 31), 
		addr_we => channel_addr_we,
		length_we => channel_length_we,
		data_in => channel_data,
		addr_out => channel_addr_out,
		length_out => channel_length_out
	);
end dma;
