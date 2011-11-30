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
    Sl_DBus                        : out std_logic_vector(0 to 31);
    Sl_errAck                      : out std_logic;
    Sl_retry                       : out std_logic;
    Sl_toutSup                     : out std_logic;
    Sl_xferAck                     : out std_logic;
    OPB_ABus                       : in  std_logic_vector(0 to 31);
    OPB_BE                         : in  std_logic_vector(0 to C_OPB_DWIDTH/8-1);
    OPB_DBus                       : in  std_logic_vector(0 to 31);
    OPB_RNW                        : in  std_logic;
    OPB_select                     : in  std_logic;
    OPB_seqAddr                    : in  std_logic;
    interruptRequest               : out std_logic;

    -- These are the pins that go to the DIO1 board.
    -- J5 Connections
	
	exp_io_37_s : in std_logic;
	exp_io_38_s : in std_logic;
	exp_io_35_s : out std_logic;
	exp_io_36_s : out std_logic;
	exp_io_33_s : out std_logic;
	exp_io_34_s : in std_logic;
	exp_io_31_s : out std_logic;
	exp_io_32_s : out std_logic;
	exp_io_29_s : out std_logic;
	exp_io_30_s : out std_logic;
	exp_io_27_s : out std_logic;
	exp_io_28_s : out std_logic;
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
	signal our_value, our_value_next: std_logic_vector(0 to 31) := "10101010101010101010101010101010";
	signal interrupt_enable, interrupt_enable_next: std_logic := '0';
	signal interrupts_acknowledged, interrupts_acknowledged_next : std_logic := '1';
	signal output: std_logic_vector(0 to 31);
	signal nIRQ, sdo, sdi, sck, nSel, ffit: std_logic;
	signal spiClk, spiClk_next: std_logic_vector(0 to 21);
begin

	process(OPB_Clk)
	begin
		if(OPB_Clk'event and OPB_Clk='1') then
			spiClk<=spiClk_next
			our_value <= our_value_next;
			interrupts_acknowledged <= interrupts_acknowledged_next;
			interrupt_enable <= interrupt_enable_next;
        end if;
    end process;

	
	process(OPB_select, OPB_RNW, OPB_ABus, OPB_DBus, OPB_Clk)
	begin
		SL_DBusEn <= '0';
		Sl_xferAck <= '0';
		our_value_next <= our_value;
		interrupts_acknowledged_next <= interrupts_acknowledged;
		interrupt_enable_next <= interrupt_enable;
		if SOMETHING then 
			interrupts_acknowledged_next <= '0';
		end if;
		if OPB_select = '1' then
			if OPB_ABus >= C_BASEADDR and OPB_ABus <= C_HIGHADDR then
				if OPB_RNW = '1' then
					SL_DBusEn <= '1';
					Sl_xferAck <= '1';
				else
					case OPB_ABus is
						when C_BASEADDR =>
							
						when C_BASEADDR + 12 =>
							interrupts_acknowledged_next <= '1';
						when C_BASEADDR + 16 =>
							interrupt_enable_next <= OPB_DBus(31);
						when others =>
							our_value_next <= OPB_DBus;
					end case;
					Sl_xferAck <= '1';
				end if;
			end if;
		end if;
	end process;
	
	output <= 	(0 to 30 => '0') & interrupts_acknowledged when OPB_ABus = C_BASEADDR + 12 else
				(0 to 30 => '0') & interrupt_enable when OPB_ABus = C_BASEADDR + 16 else
				(others => '0');
	
	Sl_DBus <= 	output when SL_DBusEn = '1' else 
				(others => '0');

    Sl_errAck <= '0';
    Sl_retry <= '0';
    Sl_toutSup <= '0';
    interruptRequest <= '1' when interrupts_acknowledged = '0' and interrupt_enable = '1' else
						'0';

   
	exp_io_37_s <= nIRQ;
	exp_io_38_s <= sdo;
	exp_io_35_s <= sdi;
	exp_io_36_s <= sck;
	
	exp_io_33_s <= nSel;
	exp_io_34_s <= ffit;
	-- exp_io_31_s <= our_value(25);
	-- exp_io_32_s <= our_value(24);
	
	-- exp_io_29_s <= our_value(23);
	-- exp_io_30_s <= our_value(22);
	-- exp_io_27_s <= our_value(21);
	-- exp_io_28_s <= OPB_Clk;
	
	 -- These are the pins that go to the DIO1 board.
    -- J5 Connections
	
    -- exp_io_41_s <= segments(1);
    -- exp_io_43_s <= segments(0);
	
    -- -- J6 Connections
    -- exp_io_48_s <= leds(31);
    -- exp_io_50_s <= leds(30);
    -- exp_io_52_s <= leds(29);
    -- exp_io_53_s <= an_out(3);
    -- exp_io_54_s <= leds(28);
    -- exp_io_55_s <= an_out(2);
    -- exp_io_56_s <= leds(27);
    -- exp_io_57_s <= an_out(1);
    -- exp_io_58_s <= leds(26);
    -- exp_io_59_s <= an_out(0);
    -- exp_io_60_s <= leds(25);
    -- exp_io_62_s <= leds(24);
    -- exp_io_65_s <= '1';
    -- exp_io_67_s <= segments(6);
    -- exp_io_69_s <= segments(5);
    -- exp_io_71_s <= segments(4);
    -- exp_io_73_s <= segments(3);
    -- exp_io_75_s <= segments(2);
	
	
	
end DI01;

