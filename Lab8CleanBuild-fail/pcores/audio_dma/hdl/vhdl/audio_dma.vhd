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
    OPB_ABus                       : in  std_logic_vector(0 to C_OPB_AWIDTH-1);
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
	type state_type is (idle, request, address_select, acknowledged);
	signal next_state, current_state: state_type := request;
	signal master_request, master_select, rnw : std_logic;
	signal master_address : std_logic_vector(0 to C_OPB_AWIDTH-1);
	signal master_data : std_logic_vector(0 to C_OPB_DWIDTH-1);
	
begin

	process(OPB_Clk)
	begin
		if(OPB_Clk'event and OPB_Clk='1') then
		current_state<=next_state;
        end if;
    end process;
	
	process(current_state, OPB_MGrant, OPB_xferAck)
	begin
		next_state <= current_state;
		case current_state is
			when idle =>
				next_state <= request;
			when request =>
				master_request <= '1';
				if OPB_MGrant = '1' then
					next_state <= address_select;
				end if;
			when address_select =>
				master_request <= '0';
				master_select <= '1';
				rnw <= '0';
				master_address <= X"40600004";
				master_data <= X"23";
				if OPB_xferAck = '1' then
					next_state <= acknowledged;
				end if;
			when acknowledged =>
				next_state <= idle;
			when others =>
		end case;
	end process;
	
	M_request <= master_request;
	M_ABus <= master_address;
    M_BE <= (others => '0');
    M_busLock <= '0';
    M_DBus <= master_data;
    M_RNW <= rnw;
    M_select <= master_select;
    M_seqAddr <= '0';
	
    Sl_DBus <= (others => '0');
    Sl_errAck <='0';
    Sl_retry <='0';
    Sl_toutSup <='0';
    Sl_xferAck <='0';
	
end dma;
