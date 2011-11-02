-------------------------------------------------------------------------------
-- sysace_compactflash_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb_sysace_v1_00_c;
use opb_sysace_v1_00_c.All;

entity sysace_compactflash_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_DBus : in std_logic_vector(0 to 31);
    Sln_DBus : out std_logic_vector(0 to 31);
    OPB_select : in std_logic;
    OPB_RNW : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_BE : in std_logic_vector(0 to 3);
    Sln_xferAck : out std_logic;
    Sln_errAck : out std_logic;
    Sln_toutSup : out std_logic;
    Sln_retry : out std_logic;
    SysACE_MPA : out std_logic_vector(6 downto 0);
    SysACE_CLK : in std_logic;
    SysACE_MPIRQ : in std_logic;
    SysACE_MPD_I : in std_logic_vector(15 downto 0);
    SysACE_MPD_O : out std_logic_vector(15 downto 0);
    SysACE_MPD_T : out std_logic_vector(15 downto 0);
    SysACE_CEN : out std_logic;
    SysACE_OEN : out std_logic;
    SysACE_WEN : out std_logic;
    SysACE_IRQ : out std_logic
  );
end sysace_compactflash_wrapper;

architecture STRUCTURE of sysace_compactflash_wrapper is

  component opb_sysace is
    generic (
      C_BASEADDR : std_logic_vector;
      C_HIGHADDR : std_logic_vector;
      C_MEM_WIDTH : INTEGER;
      C_OPB_DWIDTH : INTEGER;
      C_OPB_AWIDTH : INTEGER
    );
    port (
      OPB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      OPB_ABus : in std_logic_vector(0 to (C_OPB_AWIDTH-1));
      OPB_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH-1));
      Sln_DBus : out std_logic_vector(0 to (C_OPB_DWIDTH-1));
      OPB_select : in std_logic;
      OPB_RNW : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_BE : in std_logic_vector(0 to ((C_OPB_DWIDTH/8)-1));
      Sln_xferAck : out std_logic;
      Sln_errAck : out std_logic;
      Sln_toutSup : out std_logic;
      Sln_retry : out std_logic;
      SysACE_MPA : out std_logic_vector(6 downto 0);
      SysACE_CLK : in std_logic;
      SysACE_MPIRQ : in std_logic;
      SysACE_MPD_I : in std_logic_vector((C_MEM_WIDTH-1) downto 0);
      SysACE_MPD_O : out std_logic_vector((C_MEM_WIDTH-1) downto 0);
      SysACE_MPD_T : out std_logic_vector((C_MEM_WIDTH-1) downto 0);
      SysACE_CEN : out std_logic;
      SysACE_OEN : out std_logic;
      SysACE_WEN : out std_logic;
      SysACE_IRQ : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb_sysace : component is "opb_sysace_v1_00_c";

begin

  sysace_compactflash : opb_sysace
    generic map (
      C_BASEADDR => X"41800000",
      C_HIGHADDR => X"4180ffff",
      C_MEM_WIDTH => 16,
      C_OPB_DWIDTH => 32,
      C_OPB_AWIDTH => 32
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      OPB_ABus => OPB_ABus,
      OPB_DBus => OPB_DBus,
      Sln_DBus => Sln_DBus,
      OPB_select => OPB_select,
      OPB_RNW => OPB_RNW,
      OPB_seqAddr => OPB_seqAddr,
      OPB_BE => OPB_BE,
      Sln_xferAck => Sln_xferAck,
      Sln_errAck => Sln_errAck,
      Sln_toutSup => Sln_toutSup,
      Sln_retry => Sln_retry,
      SysACE_MPA => SysACE_MPA,
      SysACE_CLK => SysACE_CLK,
      SysACE_MPIRQ => SysACE_MPIRQ,
      SysACE_MPD_I => SysACE_MPD_I,
      SysACE_MPD_O => SysACE_MPD_O,
      SysACE_MPD_T => SysACE_MPD_T,
      SysACE_CEN => SysACE_CEN,
      SysACE_OEN => SysACE_OEN,
      SysACE_WEN => SysACE_WEN,
      SysACE_IRQ => SysACE_IRQ
    );

end architecture STRUCTURE;

