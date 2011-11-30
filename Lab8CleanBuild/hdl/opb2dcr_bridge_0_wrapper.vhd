-------------------------------------------------------------------------------
-- opb2dcr_bridge_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb2dcr_bridge_v1_00_a;
use opb2dcr_bridge_v1_00_a.All;

entity opb2dcr_bridge_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    OPB_dcrClk : out std_logic;
    OPB_dcrRst : out std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_DBus : in std_logic_vector(0 to 31);
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_xferAck : in std_logic;
    OPB_errAck : in std_logic;
    OPB_retry : in std_logic;
    OPB_timeout : in std_logic;
    Sln_DBus : out std_logic_vector(0 to 31);
    Sln_ErrAck : out std_logic;
    Sln_Retry : out std_logic;
    Sln_ToutSup : out std_logic;
    Sln_XferAck : out std_logic;
    DCR_opbAck : in std_logic;
    DCR_opbDBusIn : in std_logic_vector(0 to 31);
    OPB_dcrRead : out std_logic;
    OPB_dcrWrite : out std_logic;
    OPB_dcrABus : out std_logic_vector(0 to 9);
    OPB_dcrDBusOut : out std_logic_vector(0 to 31)
  );
end opb2dcr_bridge_0_wrapper;

architecture STRUCTURE of opb2dcr_bridge_0_wrapper is

  component opb2dcr_bridge is
    generic (
      C_BASEADDR : std_logic_vector;
      C_HIGHADDR : std_logic_vector;
      C_OPB_AWIDTH : integer;
      C_OPB_DWIDTH : integer;
      C_FAMILY : string
    );
    port (
      OPB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      OPB_dcrClk : out std_logic;
      OPB_dcrRst : out std_logic;
      OPB_ABus : in std_logic_vector(0 to C_OPB_AWIDTH-1);
      OPB_BE : in std_logic_vector(0 to C_OPB_DWIDTH/8-1);
      OPB_DBus : in std_logic_vector(0 to C_OPB_DWIDTH-1);
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_xferAck : in std_logic;
      OPB_errAck : in std_logic;
      OPB_retry : in std_logic;
      OPB_timeout : in std_logic;
      Sln_DBus : out std_logic_vector(0 to C_OPB_DWIDTH-1);
      Sln_ErrAck : out std_logic;
      Sln_Retry : out std_logic;
      Sln_ToutSup : out std_logic;
      Sln_XferAck : out std_logic;
      DCR_opbAck : in std_logic;
      DCR_opbDBusIn : in std_logic_vector(0 to 31);
      OPB_dcrRead : out std_logic;
      OPB_dcrWrite : out std_logic;
      OPB_dcrABus : out std_logic_vector(0 to 9);
      OPB_dcrDBusOut : out std_logic_vector(0 to 31)
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb2dcr_bridge : component is "opb2dcr_bridge_v1_00_a";

begin

  opb2dcr_bridge_0 : opb2dcr_bridge
    generic map (
      C_BASEADDR => X"41218000",
      C_HIGHADDR => X"41218fff",
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_FAMILY => "virtex2p"
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      OPB_dcrClk => OPB_dcrClk,
      OPB_dcrRst => OPB_dcrRst,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_DBus => OPB_DBus,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      OPB_xferAck => OPB_xferAck,
      OPB_errAck => OPB_errAck,
      OPB_retry => OPB_retry,
      OPB_timeout => OPB_timeout,
      Sln_DBus => Sln_DBus,
      Sln_ErrAck => Sln_ErrAck,
      Sln_Retry => Sln_Retry,
      Sln_ToutSup => Sln_ToutSup,
      Sln_XferAck => Sln_XferAck,
      DCR_opbAck => DCR_opbAck,
      DCR_opbDBusIn => DCR_opbDBusIn,
      OPB_dcrRead => OPB_dcrRead,
      OPB_dcrWrite => OPB_dcrWrite,
      OPB_dcrABus => OPB_dcrABus,
      OPB_dcrDBusOut => OPB_dcrDBusOut
    );

end architecture STRUCTURE;

