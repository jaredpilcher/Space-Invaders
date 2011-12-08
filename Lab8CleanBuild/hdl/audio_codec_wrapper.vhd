-------------------------------------------------------------------------------
-- audio_codec_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb_ac97_v2_00_a;
use opb_ac97_v2_00_a.All;

entity audio_codec_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_DBus : in std_logic_vector(0 to 31);
    Sln_DBus : out std_logic_vector(0 to 31);
    Sln_errAck : out std_logic;
    Sln_retry : out std_logic;
    Sln_toutSup : out std_logic;
    Sln_xferAck : out std_logic;
    Interrupt : out std_logic;
    AC97Reset_n : out std_logic;
    Bit_Clk : in std_logic;
    Sync : out std_logic;
    SData_Out : out std_logic;
    SData_In : in std_logic
  );
end audio_codec_wrapper;

architecture STRUCTURE of audio_codec_wrapper is

  component opb_ac97 is
    generic (
      C_OPB_DWIDTH : INTEGER;
      C_OPB_AWIDTH : INTEGER;
      C_BASEADDR : STD_LOGIC_VECTOR;
      C_HIGHADDR : STD_LOGIC_VECTOR;
      C_PLAYBACK : INTEGER;
      C_RECORD : INTEGER;
      C_INTR_LEVEL : INTEGER;
      C_USE_BRAM : INTEGER
    );
    port (
      OPB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      OPB_ABus : in std_logic_vector(0 to 31);
      OPB_BE : in std_logic_vector(0 to 3);
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_DBus : in std_logic_vector(0 to 31);
      Sln_DBus : out std_logic_vector(0 to 31);
      Sln_errAck : out std_logic;
      Sln_retry : out std_logic;
      Sln_toutSup : out std_logic;
      Sln_xferAck : out std_logic;
      Interrupt : out std_logic;
      AC97Reset_n : out std_logic;
      Bit_Clk : in std_logic;
      Sync : out std_logic;
      SData_Out : out std_logic;
      SData_In : in std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb_ac97 : component is "opb_ac97_v2_00_a";

begin

  audio_codec : opb_ac97
    generic map (
      C_OPB_DWIDTH => 32,
      C_OPB_AWIDTH => 32,
      C_BASEADDR => X"7f400000",
      C_HIGHADDR => X"7f40ffff",
      C_PLAYBACK => 1,
      C_RECORD => 1,
      C_INTR_LEVEL => 1,
      C_USE_BRAM => 1
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      OPB_DBus => OPB_DBus,
      Sln_DBus => Sln_DBus,
      Sln_errAck => Sln_errAck,
      Sln_retry => Sln_retry,
      Sln_toutSup => Sln_toutSup,
      Sln_xferAck => Sln_xferAck,
      Interrupt => Interrupt,
      AC97Reset_n => AC97Reset_n,
      Bit_Clk => Bit_Clk,
      Sync => Sync,
      SData_Out => SData_Out,
      SData_In => SData_In
    );

end architecture STRUCTURE;

