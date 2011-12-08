-------------------------------------------------------------------------------
-- chipscope_icon_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library chipscope_icon_v1_01_a;
use chipscope_icon_v1_01_a.All;

entity chipscope_icon_0_wrapper is
  port (
    control0 : out std_logic_vector(35 downto 0);
    control1 : out std_logic_vector(35 downto 0);
    control2 : out std_logic_vector(35 downto 0);
    control3 : out std_logic_vector(35 downto 0);
    control4 : out std_logic_vector(35 downto 0);
    control5 : out std_logic_vector(35 downto 0);
    control6 : out std_logic_vector(35 downto 0);
    control7 : out std_logic_vector(35 downto 0);
    control8 : out std_logic_vector(35 downto 0);
    control9 : out std_logic_vector(35 downto 0);
    control10 : out std_logic_vector(35 downto 0);
    control11 : out std_logic_vector(35 downto 0);
    control12 : out std_logic_vector(35 downto 0);
    control13 : out std_logic_vector(35 downto 0);
    control14 : out std_logic_vector(35 downto 0);
    control15 : out std_logic_vector(35 downto 0);
    tdi_in : in std_logic;
    reset_in : in std_logic;
    shift_in : in std_logic;
    update_in : in std_logic;
    sel_in : in std_logic;
    drck_in : in std_logic;
    tdo_out : out std_logic
  );
end chipscope_icon_0_wrapper;

architecture STRUCTURE of chipscope_icon_0_wrapper is

  component chipscope_icon is
    generic (
      C_FAMILY : string;
      C_NUM_CONTROL_PORTS : integer;
      C_SYSTEM_CONTAINS_MDM : integer;
      C_DISABLE_JTAG_CLOCK_BUFG_INSERTION : integer;
      C_FORCE_BSCAN_USER_PORT : integer
    );
    port (
      control0 : out std_logic_vector(35 downto 0);
      control1 : out std_logic_vector(35 downto 0);
      control2 : out std_logic_vector(35 downto 0);
      control3 : out std_logic_vector(35 downto 0);
      control4 : out std_logic_vector(35 downto 0);
      control5 : out std_logic_vector(35 downto 0);
      control6 : out std_logic_vector(35 downto 0);
      control7 : out std_logic_vector(35 downto 0);
      control8 : out std_logic_vector(35 downto 0);
      control9 : out std_logic_vector(35 downto 0);
      control10 : out std_logic_vector(35 downto 0);
      control11 : out std_logic_vector(35 downto 0);
      control12 : out std_logic_vector(35 downto 0);
      control13 : out std_logic_vector(35 downto 0);
      control14 : out std_logic_vector(35 downto 0);
      control15 : out std_logic_vector(35 downto 0);
      tdi_in : in std_logic;
      reset_in : in std_logic;
      shift_in : in std_logic;
      update_in : in std_logic;
      sel_in : in std_logic;
      drck_in : in std_logic;
      tdo_out : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of chipscope_icon : component is "chipscope_icon_v1_01_a";

begin

  chipscope_icon_0 : chipscope_icon
    generic map (
      C_FAMILY => "virtex2p",
      C_NUM_CONTROL_PORTS => 1,
      C_SYSTEM_CONTAINS_MDM => 0,
      C_DISABLE_JTAG_CLOCK_BUFG_INSERTION => 0,
      C_FORCE_BSCAN_USER_PORT => 1
    )
    port map (
      control0 => control0,
      control1 => control1,
      control2 => control2,
      control3 => control3,
      control4 => control4,
      control5 => control5,
      control6 => control6,
      control7 => control7,
      control8 => control8,
      control9 => control9,
      control10 => control10,
      control11 => control11,
      control12 => control12,
      control13 => control13,
      control14 => control14,
      control15 => control15,
      tdi_in => tdi_in,
      reset_in => reset_in,
      shift_in => shift_in,
      update_in => update_in,
      sel_in => sel_in,
      drck_in => drck_in,
      tdo_out => tdo_out
    );

end architecture STRUCTURE;

