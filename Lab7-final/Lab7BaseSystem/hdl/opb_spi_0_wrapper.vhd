-------------------------------------------------------------------------------
-- opb_spi_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb_spi_v1_00_e;
use opb_spi_v1_00_e.All;

entity opb_spi_0_wrapper is
  port (
    SCK_I : in std_logic;
    SCK_O : out std_logic;
    SCK_T : out std_logic;
    MISO_I : in std_logic;
    MISO_O : out std_logic;
    MISO_T : out std_logic;
    MOSI_I : in std_logic;
    MOSI_O : out std_logic;
    MOSI_T : out std_logic;
    SPISEL : in std_logic;
    SS_I : in std_logic_vector(0 to 0);
    SS_O : out std_logic_vector(0 to 0);
    SS_T : out std_logic;
    OPB_Rst : in std_logic;
    IP2INTC_Irpt : out std_logic;
    Freeze : in std_logic;
    OPB_Clk : in std_logic;
    OPB_select : in std_logic;
    OPB_RNW : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_DBus : in std_logic_vector(0 to 31);
    SPI_DBus : out std_logic_vector(0 to 31);
    SPI_xferAck : out std_logic;
    SPI_errAck : out std_logic;
    SPI_toutSup : out std_logic;
    SPI_retry : out std_logic
  );
end opb_spi_0_wrapper;

architecture STRUCTURE of opb_spi_0_wrapper is

  component opb_spi is
    generic (
      C_FIFO_EXIST : INTEGER;
      C_OPB_SCK_RATIO : INTEGER;
      C_SPI_SLAVE_ONLY : INTEGER;
      C_NUM_OFFCHIP_SS_BITS : INTEGER;
      C_NUM_SS_BITS : INTEGER;
      C_NUM_BITS_SR : INTEGER;
      C_DEV_BLK_ID : INTEGER;
      C_DEV_MIR_ENABLE : INTEGER;
      C_FAMILY : STRING;
      C_BASEADDR : std_logic_vector;
      C_HIGHADDR : std_logic_vector;
      C_INTERRUPT_PRESENT : INTEGER;
      C_OPB_AWIDTH : INTEGER;
      C_OPB_DWIDTH : INTEGER;
      C_IP_REG_BAR_OFFSET : std_logic_vector;
      C_DEPTH : INTEGER;
      C_NUM_BITS_REG : INTEGER;
      C_OCCUPANCY_NUM_BITS : INTEGER
    );
    port (
      SCK_I : in std_logic;
      SCK_O : out std_logic;
      SCK_T : out std_logic;
      MISO_I : in std_logic;
      MISO_O : out std_logic;
      MISO_T : out std_logic;
      MOSI_I : in std_logic;
      MOSI_O : out std_logic;
      MOSI_T : out std_logic;
      SPISEL : in std_logic;
      SS_I : in std_logic_vector(0 to (C_NUM_SS_BITS-1));
      SS_O : out std_logic_vector(0 to (C_NUM_SS_BITS-1));
      SS_T : out std_logic;
      OPB_Rst : in std_logic;
      IP2INTC_Irpt : out std_logic;
      Freeze : in std_logic;
      OPB_Clk : in std_logic;
      OPB_select : in std_logic;
      OPB_RNW : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_BE : in std_logic_vector(0 to ((C_OPB_DWIDTH/8)-1));
      OPB_ABus : in std_logic_vector(0 to (C_OPB_AWIDTH-1));
      OPB_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH-1));
      SPI_DBus : out std_logic_vector(0 to (C_OPB_DWIDTH-1));
      SPI_xferAck : out std_logic;
      SPI_errAck : out std_logic;
      SPI_toutSup : out std_logic;
      SPI_retry : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb_spi : component is "opb_spi_v1_00_e";

begin

  opb_spi_0 : opb_spi
    generic map (
      C_FIFO_EXIST => 1,
      C_OPB_SCK_RATIO => 32,
      C_SPI_SLAVE_ONLY => 0,
      C_NUM_OFFCHIP_SS_BITS => 0,
      C_NUM_SS_BITS => 1,
      C_NUM_BITS_SR => 8,
      C_DEV_BLK_ID => 4,
      C_DEV_MIR_ENABLE => 0,
      C_FAMILY => "virtex2p",
      C_BASEADDR => X"00000000",
      C_HIGHADDR => X"0000007f",
      C_INTERRUPT_PRESENT => 1,
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_IP_REG_BAR_OFFSET => X"00000060",
      C_DEPTH => 16,
      C_NUM_BITS_REG => 8,
      C_OCCUPANCY_NUM_BITS => 4
    )
    port map (
      SCK_I => SCK_I,
      SCK_O => SCK_O,
      SCK_T => SCK_T,
      MISO_I => MISO_I,
      MISO_O => MISO_O,
      MISO_T => MISO_T,
      MOSI_I => MOSI_I,
      MOSI_O => MOSI_O,
      MOSI_T => MOSI_T,
      SPISEL => SPISEL,
      SS_I => SS_I,
      SS_O => SS_O,
      SS_T => SS_T,
      OPB_Rst => OPB_Rst,
      IP2INTC_Irpt => IP2INTC_Irpt,
      Freeze => Freeze,
      OPB_Clk => OPB_Clk,
      OPB_select => OPB_select,
      OPB_RNW => OPB_RNW,
      OPB_seqAddr => OPB_seqAddr,
      OPB_BE => OPB_BE,
      OPB_ABus => OPB_ABus,
      OPB_DBus => OPB_DBus,
      SPI_DBus => SPI_DBus,
      SPI_xferAck => SPI_xferAck,
      SPI_errAck => SPI_errAck,
      SPI_toutSup => SPI_toutSup,
      SPI_retry => SPI_retry
    );

end architecture STRUCTURE;

