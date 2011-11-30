library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.numeric_std.all;		

entity opb_master is
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
	OPB_xferAck: in  std_logic;
	OPB_MGrant: in std_logic;
	M_ABus   : out std_logic_vector(0 to 31);
    M_BE     : out std_logic_vector(0 to 3);
--    M_busLock: out std_logic;
    M_DBus   : out std_logic_vector(0 to 31);
    M_request: out std_logic;
    M_RNW    : out std_logic;
    M_select : out std_logic
--    M_seqAddr: out std_logic;
  );
end entity opb_master;

architecture opbm of opb_master is
	type state_type is (idle, retry, request, address_select, acknowledged);
	signal next_state, current_state: state_type := idle;
	signal data_out_reg, data_out_reg_next : std_logic_vector(0 to 31);
	signal master_request: std_logic;
	signal master_select: std_logic;
	signal master_address: std_logic_vector(0 to 31);
	signal master_data: std_logic_vector(0 to 31);
	signal counter, counter_next : unsigned(0 to 31);
	signal idle_sig: std_logic;
begin
	process(clk)
	begin
		if(clk'event and clk='1') then
			current_state <= next_state;
			data_out_reg  <= data_out_reg_next;
			counter <= counter_next;
        end if;
    end process;
	
	process(enable,current_state, OPB_xferAck, OPB_MGrant,rnw, counter)
	begin
		next_state <= current_state;
		master_data <= X"00000000";
		master_address <= X"00000000";
		idle_sig <= '0';
		master_select <= '0';
		data_out_reg_next <= data_out_reg;
		counter_next <= counter + 1;
		case current_state is
			when idle =>
				idle_sig <= '1';
				if enable = '1' then
					next_state <= request;
				end if;
			when retry =>
				next_state <= request;
			when request =>
				master_request <= '1';
				if OPB_MGrant = '1' then
					next_state <= address_select;
					counter_next <= (others => '0');
				end if;
			when address_select =>
				master_request <= '0';
				master_select <= '1';
				master_address <= address;
				if OPB_xferAck = '1' then
					next_state <= acknowledged;
					data_out_reg_next <= OPB_DBus;
				end if;
				if rnw = '0' then
					master_data <= data;
				end if;
				if counter = 500 then
					next_state <= retry;
				end if;
			when acknowledged =>
				next_state <= idle;
			when others =>
		end case;
	end process;
	M_RNW <= rnw;
	data_out <= data_out_reg;
	idle_out <= idle_sig;
	M_ABus   <= master_address;
    M_BE     <= "0000";
    M_DBus   <= master_data;
    M_request<= master_request;
    M_select <= master_select;
end opbm;