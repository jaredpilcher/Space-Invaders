-------------------------------------------------------------------------------
-- opb_intc_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb_intc_v1_00_c;
use opb_intc_v1_00_c.All;

entity opb_intc_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    Intr : in std_logic_vector(0 downto 0);
    OPB_Rst : in std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_DBus : in std_logic_vector(0 to 31);
    IntC_DBus : out std_logic_vector(0 to 31);
    IntC_errAck : out std_logic;
    IntC_retry : out std_logic;
    IntC_toutSup : out std_logic;
    IntC_xferAck : out std_logic;
    Irq : out std_logic
  );
end opb_intc_0_wrapper;

architecture STRUCTURE of opb_intc_0_wrapper is

  component opb_intc is
    generic (
      C_FAMILY : string;
      C_Y : integer;
      C_X : integer;
      C_U_SET : string;
      C_OPB_AWIDTH : integer;
      C_OPB_DWIDTH : integer;
      C_BASEADDR : std_logic_vector;
      C_HIGHADDR : std_logic_vector;
      C_NUM_INTR_INPUTS : integer;
      C_KIND_OF_INTR : std_logic_vector;
      C_KIND_OF_EDGE : std_logic_vector;
      C_KIND_OF_LVL : std_logic_vector;
      C_HAS_IPR : integer;
      C_HAS_SIE : integer;
      C_HAS_CIE : integer;
      C_HAS_IVR : integer;
      C_IRQ_IS_LEVEL : integer;
      C_IRQ_ACTIVE : std_logic
    );
    port (
      OPB_Clk : in std_logic;
      Intr : in std_logic_vector(C_NUM_INTR_INPUTS-1 downto 0);
      OPB_Rst : in std_logic;
      OPB_ABus : in std_logic_vector(0 to 31);
      OPB_BE : in std_logic_vector(0 to 3);
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_DBus : in std_logic_vector(0 to 31);
      IntC_DBus : out std_logic_vector(0 to 31);
      IntC_errAck : out std_logic;
      IntC_retry : out std_logic;
      IntC_toutSup : out std_logic;
      IntC_xferAck : out std_logic;
      Irq : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb_intc : component is "opb_intc_v1_00_c";

begin

  opb_intc_0 : opb_intc
    generic map (
      C_FAMILY => "virtex2p",
      C_Y => 0,
      C_X => 0,
      C_U_SET => "intc",
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_BASEADDR => X"41200000",
      C_HIGHADDR => X"4120ffff",
      C_NUM_INTR_INPUTS => 1,
      C_KIND_OF_INTR => B"00000000000000000000000000000000",
      C_KIND_OF_EDGE => B"00000000000000000000000000000000",
      C_KIND_OF_LVL => B"00000000000000000000000000000001",
      C_HAS_IPR => 1,
      C_HAS_SIE => 1,
      C_HAS_CIE => 1,
      C_HAS_IVR => 1,
      C_IRQ_IS_LEVEL => 1,
      C_IRQ_ACTIVE => '1'
    )
    port map (
      OPB_Clk => OPB_Clk,
      Intr => Intr,
      OPB_Rst => OPB_Rst,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      OPB_DBus => OPB_DBus,
      IntC_DBus => IntC_DBus,
      IntC_errAck => IntC_errAck,
      IntC_retry => IntC_retry,
      IntC_toutSup => IntC_toutSup,
      IntC_xferAck => IntC_xferAck,
      Irq => Irq
    );

end architecture STRUCTURE;

