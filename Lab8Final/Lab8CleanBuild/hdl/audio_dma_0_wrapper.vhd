-------------------------------------------------------------------------------
-- audio_dma_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library audio_dma;
use audio_dma.All;

entity audio_dma_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    OPB_DBus : in std_logic_vector(0 to 31);
    OPB_errAck : in std_logic;
    OPB_MGrant : in std_logic;
    OPB_retry : in std_logic;
    OPB_timeout : in std_logic;
    OPB_xferAck : in std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic;
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    M_ABus : out std_logic_vector(0 to 31);
    M_BE : out std_logic_vector(0 to 3);
    M_busLock : out std_logic;
    M_DBus : out std_logic_vector(0 to 31);
    M_request : out std_logic;
    M_RNW : out std_logic;
    M_select : out std_logic;
    M_seqAddr : out std_logic;
    Sl_DBus : out std_logic_vector(0 to 31);
    Sl_errAck : out std_logic;
    Sl_retry : out std_logic;
    Sl_toutSup : out std_logic;
    Sl_xferAck : out std_logic;
    AC97Int : in std_logic
  );
end audio_dma_0_wrapper;

architecture STRUCTURE of audio_dma_0_wrapper is

  component audio_dma is
    generic (
      C_BASEADDR : std_logic_vector(0 to 31);
      C_HIGHADDR : std_logic_vector(0 to 31);
      C_OPB_AWIDTH : INTEGER;
      C_OPB_DWIDTH : INTEGER;
      C_FAMILY : STRING
    );
    port (
      OPB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      OPB_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH-1));
      OPB_errAck : in std_logic;
      OPB_MGrant : in std_logic;
      OPB_retry : in std_logic;
      OPB_timeout : in std_logic;
      OPB_xferAck : in std_logic;
      OPB_ABus : in std_logic_vector(0 to (C_OPB_AWIDTH-1));
      OPB_BE : in std_logic;
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      M_ABus : out std_logic_vector(0 to (C_OPB_AWIDTH-1));
      M_BE : out std_logic_vector(0 to ((C_OPB_DWIDTH/8)-1));
      M_busLock : out std_logic;
      M_DBus : out std_logic_vector(0 to (C_OPB_DWIDTH-1));
      M_request : out std_logic;
      M_RNW : out std_logic;
      M_select : out std_logic;
      M_seqAddr : out std_logic;
      Sl_DBus : out std_logic_vector(0 to (C_OPB_DWIDTH-1));
      Sl_errAck : out std_logic;
      Sl_retry : out std_logic;
      Sl_toutSup : out std_logic;
      Sl_xferAck : out std_logic;
      AC97Int : in std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of audio_dma : component is "audio_dma_v";

begin

  audio_dma_0 : audio_dma
    generic map (
      C_BASEADDR => X"40090000",
      C_HIGHADDR => X"4009ffff",
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_FAMILY => "virtex2p"
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      OPB_DBus => OPB_DBus,
      OPB_errAck => OPB_errAck,
      OPB_MGrant => OPB_MGrant,
      OPB_retry => OPB_retry,
      OPB_timeout => OPB_timeout,
      OPB_xferAck => OPB_xferAck,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      M_ABus => M_ABus,
      M_BE => M_BE,
      M_busLock => M_busLock,
      M_DBus => M_DBus,
      M_request => M_request,
      M_RNW => M_RNW,
      M_select => M_select,
      M_seqAddr => M_seqAddr,
      Sl_DBus => Sl_DBus,
      Sl_errAck => Sl_errAck,
      Sl_retry => Sl_retry,
      Sl_toutSup => Sl_toutSup,
      Sl_xferAck => Sl_xferAck,
      AC97Int => AC97Int
    );

end architecture STRUCTURE;

