------------------------------------------------------------------------------
-- lab3_slave.vhd
--
------------------------------------------------------------------------------
-- Filename:          lab3_slave.vhd
-- Version:           1.00.a
-- Description:       Lab #3 slave I/O core
-- Date               10/31/2007
--
-- By Brad Hutchings
--
------------------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;

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

entity lab3_slave is
  generic
  (
    -- Bus protocol parameters, do not add to or delete
    C_BASEADDR                     : std_logic_vector(0 to 31)     := X"40080000";
    C_HIGHADDR                     : std_logic_vector(0 to 31)     := X"4008FFFF";
    C_OPB_AWIDTH                   : integer              := 32;
    C_OPB_DWIDTH                   : integer              := 32;
    C_FAMILY                       : string               := "virtex2p"
  );
  port
  (
    -- Bus protocol ports, do not add to or delete
    OPB_Clk                        : in  std_logic;
    OPB_Rst                        : in  std_logic;
    Sl_DBus                        : out std_logic_vector(0 to C_OPB_DWIDTH-1);
    Sl_errAck                      : out std_logic;
    Sl_retry                       : out std_logic;
    Sl_toutSup                     : out std_logic;
    Sl_xferAck                     : out std_logic;
    OPB_ABus                       : in  std_logic_vector(0 to C_OPB_AWIDTH-1);
    OPB_BE                         : in  std_logic_vector(0 to C_OPB_DWIDTH/8-1);
    OPB_DBus                       : in  std_logic_vector(0 to C_OPB_DWIDTH-1);
    OPB_RNW                        : in  std_logic;
    OPB_select                     : in  std_logic;
    OPB_seqAddr                    : in  std_logic;
    interruptRequest               : out std_logic;

    -- These are the pins that go to the DIO1 board.
    -- J5 Connections
    exp_io_40_s : in std_logic;
    exp_io_41_s : out std_logic;
    exp_io_42_s : in std_logic;
    exp_io_43_s : out std_logic;
    exp_io_44_s : in std_logic;
    exp_io_45_s : in std_logic;
    -- J6 Connections
    exp_io_48_s : out std_logic;
    exp_io_50_s : out std_logic;
    exp_io_52_s : out std_logic;
    exp_io_53_s : out std_logic;
    exp_io_54_s : out std_logic;
    exp_io_55_s : out std_logic;
    exp_io_56_s : out std_logic;
    exp_io_57_s : out std_logic;
    exp_io_58_s : out std_logic;
    exp_io_59_s : out std_logic;
    exp_io_60_s : out std_logic;
    exp_io_61_s : in std_logic;
    exp_io_62_s : out std_logic;
    exp_io_63_s : in std_logic;
    exp_io_64_s : in std_logic;
    exp_io_65_s : out std_logic;
    exp_io_66_s : in std_logic;
    exp_io_67_s : out std_logic;
    exp_io_68_s : in std_logic;
    exp_io_69_s : out std_logic;
    exp_io_70_s : in std_logic;
    exp_io_71_s : out std_logic;
    exp_io_72_s : in std_logic;
    exp_io_73_s : out std_logic;
    exp_io_74_s : in std_logic;
    exp_io_75_s : out std_logic;
    exp_io_76_s : in std_logic
  );

  attribute SIGIS : string;
  attribute SIGIS of OPB_Clk       : signal is "Clk";
  attribute SIGIS of OPB_Rst       : signal is "Rst";

end entity lab3_slave;

architecture DI01 of lab3_slave is

	type state_type is (Idle, R, W);
	signal next_state, current_state: state_type;
	signal SL_DBusEn: std_logic := '0';
	signal our_value, our_value_next: std_logic_vector(31 downto 0) := "10101010101010101010101010101010";
	signal interrupt_enable, interrupt_enable_next: std_logic := '0';
	signal interrupts_acknowledged : std_logic := '1';
	signal score, lives, aliens_left: std_logic_vector(31 downto 0) := (others => '0');
	
begin
	registers: process(OPB_Clk)
	begin
		if(OPB_Clk'event and OPB_Clk='1') then
			our_value <= our_value_next;
		end if;
	end process;
	
	logic: process(OPB_select, OPB_RNW, OPB_ABus, OPB_DBus)
	begin
		SL_DBusEn <= '0';
		Sl_xferAck <= '0';
		our_value_next <= our_value;
		if OPB_select = '1' then
			if OPB_ABus >= C_BASEADDR and OPB_ABus <= C_HIGHADDR then
				if OPB_RNW = '1' then
					SL_DBusEn <= '1';
					Sl_xferAck <= '1';
				else
					our_value_next <= OPB_DBus;
				end if;
			end if;
		end if;
	end process;
	
	Sl_DBus <= 	our_value when SL_DBusEn = '1' else
				(others => '0');
	
	--unused out ports
    Sl_errAck <= '0';
    Sl_retry <= '0';
    Sl_toutSup <= '0';
    interruptRequest <= '0';

    -- These are the pins that go to the DIO1 board.
    -- J5 Connections
    exp_io_41_s <= '0';
    exp_io_43_s <= '0';
	
    -- J6 Connections
    exp_io_48_s <= '0';
    exp_io_50_s <= '0';
    exp_io_52_s <= '0';
    exp_io_53_s <= '0';
    exp_io_54_s <= '0';
    exp_io_55_s <= '0';
    exp_io_56_s <= '0';
    exp_io_57_s <= '0';
    exp_io_58_s <= '0';
    exp_io_59_s <= '0';
    exp_io_60_s <= '0';
    exp_io_62_s <= '0';
    exp_io_65_s <= '0';
    exp_io_67_s <= '0';
    exp_io_69_s <= '0';
    exp_io_71_s <= '0';
    exp_io_73_s <= '0';
    exp_io_75_s <= '0';
	
end DI01;

