-------------------------------------------------------------------------------
-- dcr_v29_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library dcr_v29_v1_00_a;
use dcr_v29_v1_00_a.All;

entity dcr_v29_0_wrapper is
  port (
    M_dcrABus : in std_logic_vector(0 to 9);
    M_dcrDBus : in std_logic_vector(0 to 31);
    M_dcrRead : in std_logic;
    M_dcrWrite : in std_logic;
    DCR_M_DBus : out std_logic_vector(0 to 31);
    DCR_Ack : out std_logic;
    DCR_ABus : out std_logic_vector(0 to 9);
    DCR_Sl_DBus : out std_logic_vector(0 to 31);
    DCR_Read : out std_logic_vector(0 to 0);
    DCR_Write : out std_logic_vector(0 to 0);
    Sl_dcrDBus : in std_logic_vector(0 to 31);
    Sl_dcrAck : in std_logic_vector(0 to 0)
  );
end dcr_v29_0_wrapper;

architecture STRUCTURE of dcr_v29_0_wrapper is

  component dcr_v29 is
    generic (
      C_DCR_NUM_SLAVES : integer;
      C_DCR_AWIDTH : integer;
      C_DCR_DWIDTH : integer;
      C_USE_LUT_OR : integer
    );
    port (
      M_dcrABus : in std_logic_vector(0 to C_DCR_AWIDTH-1);
      M_dcrDBus : in std_logic_vector(0 to C_DCR_DWIDTH-1);
      M_dcrRead : in std_logic;
      M_dcrWrite : in std_logic;
      DCR_M_DBus : out std_logic_vector(0 to C_DCR_DWIDTH-1);
      DCR_Ack : out std_logic;
      DCR_ABus : out std_logic_vector(0 to C_DCR_AWIDTH*C_DCR_NUM_SLAVES-1);
      DCR_Sl_DBus : out std_logic_vector(0 to C_DCR_DWIDTH*C_DCR_NUM_SLAVES-1);
      DCR_Read : out std_logic_vector(0 to C_DCR_NUM_SLAVES-1);
      DCR_Write : out std_logic_vector(0 to C_DCR_NUM_SLAVES-1);
      Sl_dcrDBus : in std_logic_vector(0 to C_DCR_DWIDTH*C_DCR_NUM_SLAVES-1);
      Sl_dcrAck : in std_logic_vector(0 to C_DCR_NUM_SLAVES-1)
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of dcr_v29 : component is "dcr_v29_v1_00_a";

begin

  dcr_v29_0 : dcr_v29
    generic map (
      C_DCR_NUM_SLAVES => 1,
      C_DCR_AWIDTH => 10,
      C_DCR_DWIDTH => 32,
      C_USE_LUT_OR => 1
    )
    port map (
      M_dcrABus => M_dcrABus,
      M_dcrDBus => M_dcrDBus,
      M_dcrRead => M_dcrRead,
      M_dcrWrite => M_dcrWrite,
      DCR_M_DBus => DCR_M_DBus,
      DCR_Ack => DCR_Ack,
      DCR_ABus => DCR_ABus,
      DCR_Sl_DBus => DCR_Sl_DBus,
      DCR_Read => DCR_Read,
      DCR_Write => DCR_Write,
      Sl_dcrDBus => Sl_dcrDBus,
      Sl_dcrAck => Sl_dcrAck
    );

end architecture STRUCTURE;

