-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    fpga_0_RS232_Uart_1_RX_pin : in std_logic;
    fpga_0_RS232_Uart_1_TX_pin : out std_logic;
    fpga_0_SysACE_CompactFlash_SysACE_CLK_pin : in std_logic;
    fpga_0_SysACE_CompactFlash_SysACE_MPA_pin : out std_logic_vector(6 downto 0);
    fpga_0_SysACE_CompactFlash_SysACE_MPD_pin : inout std_logic_vector(15 downto 0);
    fpga_0_SysACE_CompactFlash_SysACE_CEN_pin : out std_logic;
    fpga_0_SysACE_CompactFlash_SysACE_OEN_pin : out std_logic;
    fpga_0_SysACE_CompactFlash_SysACE_WEN_pin : out std_logic;
    fpga_0_SysACE_CompactFlash_SysACE_MPIRQ_pin : in std_logic;
    fpga_0_PushButtons_5Bit_GPIO_IO_pin : inout std_logic_vector(0 to 4);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clk_pin : out std_logic_vector(0 to 2);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clkn_pin : out std_logic_vector(0 to 2);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Addr_pin : out std_logic_vector(0 to 12);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_BankAddr_pin : out std_logic_vector(0 to 1);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CASn_pin : out std_logic;
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_RASn_pin : out std_logic;
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_WEn_pin : out std_logic;
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DM_pin : out std_logic_vector(0 to 7);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQS_pin : inout std_logic_vector(0 to 7);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQ_pin : inout std_logic_vector(0 to 63);
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CKE_pin : out std_logic;
    fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CSn_pin : out std_logic;
    fpga_0_VGA_FrameBuffer_TFT_LCD_HSYNC_pin : out std_logic;
    fpga_0_VGA_FrameBuffer_TFT_LCD_VSYNC_pin : out std_logic;
    fpga_0_VGA_FrameBuffer_TFT_LCD_CLK_pin : out std_logic;
    fpga_0_VGA_FrameBuffer_TFT_LCD_R_pin : out std_logic_vector(5 downto 0);
    fpga_0_VGA_FrameBuffer_TFT_LCD_G_pin : out std_logic_vector(5 downto 0);
    fpga_0_VGA_FrameBuffer_TFT_LCD_B_pin : out std_logic_vector(5 downto 0);
    fpga_0_VGA_FrameBuffer_TFT_LCD_BLNK_pin : out std_logic;
    fpga_0_net_gnd_pin : out std_logic;
    fpga_0_net_gnd_1_pin : out std_logic;
    fpga_0_net_gnd_2_pin : out std_logic;
    fpga_0_net_gnd_3_pin : out std_logic;
    fpga_0_net_gnd_4_pin : out std_logic;
    fpga_0_net_gnd_5_pin : out std_logic;
    fpga_0_net_gnd_6_pin : out std_logic;
    fpga_0_DDR_CLK_FB : in std_logic;
    fpga_0_DDR_CLK_FB_OUT : out std_logic;
    sys_clk_pin : in std_logic;
    sys_rst_pin : in std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      fpga_0_RS232_Uart_1_RX_pin : in std_logic;
      fpga_0_RS232_Uart_1_TX_pin : out std_logic;
      fpga_0_SysACE_CompactFlash_SysACE_CLK_pin : in std_logic;
      fpga_0_SysACE_CompactFlash_SysACE_MPA_pin : out std_logic_vector(6 downto 0);
      fpga_0_SysACE_CompactFlash_SysACE_MPD_pin : inout std_logic_vector(15 downto 0);
      fpga_0_SysACE_CompactFlash_SysACE_CEN_pin : out std_logic;
      fpga_0_SysACE_CompactFlash_SysACE_OEN_pin : out std_logic;
      fpga_0_SysACE_CompactFlash_SysACE_WEN_pin : out std_logic;
      fpga_0_SysACE_CompactFlash_SysACE_MPIRQ_pin : in std_logic;
      fpga_0_PushButtons_5Bit_GPIO_IO_pin : inout std_logic_vector(0 to 4);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clk_pin : out std_logic_vector(0 to 2);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clkn_pin : out std_logic_vector(0 to 2);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Addr_pin : out std_logic_vector(0 to 12);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_BankAddr_pin : out std_logic_vector(0 to 1);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CASn_pin : out std_logic;
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_RASn_pin : out std_logic;
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_WEn_pin : out std_logic;
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DM_pin : out std_logic_vector(0 to 7);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQS_pin : inout std_logic_vector(0 to 7);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQ_pin : inout std_logic_vector(0 to 63);
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CKE_pin : out std_logic;
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CSn_pin : out std_logic;
      fpga_0_VGA_FrameBuffer_TFT_LCD_HSYNC_pin : out std_logic;
      fpga_0_VGA_FrameBuffer_TFT_LCD_VSYNC_pin : out std_logic;
      fpga_0_VGA_FrameBuffer_TFT_LCD_CLK_pin : out std_logic;
      fpga_0_VGA_FrameBuffer_TFT_LCD_R_pin : out std_logic_vector(5 downto 0);
      fpga_0_VGA_FrameBuffer_TFT_LCD_G_pin : out std_logic_vector(5 downto 0);
      fpga_0_VGA_FrameBuffer_TFT_LCD_B_pin : out std_logic_vector(5 downto 0);
      fpga_0_VGA_FrameBuffer_TFT_LCD_BLNK_pin : out std_logic;
      fpga_0_net_gnd_pin : out std_logic;
      fpga_0_net_gnd_1_pin : out std_logic;
      fpga_0_net_gnd_2_pin : out std_logic;
      fpga_0_net_gnd_3_pin : out std_logic;
      fpga_0_net_gnd_4_pin : out std_logic;
      fpga_0_net_gnd_5_pin : out std_logic;
      fpga_0_net_gnd_6_pin : out std_logic;
      fpga_0_DDR_CLK_FB : in std_logic;
      fpga_0_DDR_CLK_FB_OUT : out std_logic;
      sys_clk_pin : in std_logic;
      sys_rst_pin : in std_logic
    );
  end component;

begin

  system_i : system
    port map (
      fpga_0_RS232_Uart_1_RX_pin => fpga_0_RS232_Uart_1_RX_pin,
      fpga_0_RS232_Uart_1_TX_pin => fpga_0_RS232_Uart_1_TX_pin,
      fpga_0_SysACE_CompactFlash_SysACE_CLK_pin => fpga_0_SysACE_CompactFlash_SysACE_CLK_pin,
      fpga_0_SysACE_CompactFlash_SysACE_MPA_pin => fpga_0_SysACE_CompactFlash_SysACE_MPA_pin,
      fpga_0_SysACE_CompactFlash_SysACE_MPD_pin => fpga_0_SysACE_CompactFlash_SysACE_MPD_pin,
      fpga_0_SysACE_CompactFlash_SysACE_CEN_pin => fpga_0_SysACE_CompactFlash_SysACE_CEN_pin,
      fpga_0_SysACE_CompactFlash_SysACE_OEN_pin => fpga_0_SysACE_CompactFlash_SysACE_OEN_pin,
      fpga_0_SysACE_CompactFlash_SysACE_WEN_pin => fpga_0_SysACE_CompactFlash_SysACE_WEN_pin,
      fpga_0_SysACE_CompactFlash_SysACE_MPIRQ_pin => fpga_0_SysACE_CompactFlash_SysACE_MPIRQ_pin,
      fpga_0_PushButtons_5Bit_GPIO_IO_pin => fpga_0_PushButtons_5Bit_GPIO_IO_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clk_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clk_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clkn_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Clkn_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Addr_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_Addr_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_BankAddr_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_BankAddr_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CASn_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CASn_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_RASn_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_RASn_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_WEn_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_WEn_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DM_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DM_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQS_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQS_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQ_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_DQ_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CKE_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CKE_pin,
      fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CSn_pin => fpga_0_DDR_256MB_32MX64_rank1_row13_col10_cl2_5_DDR_CSn_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_HSYNC_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_HSYNC_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_VSYNC_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_VSYNC_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_CLK_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_CLK_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_R_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_R_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_G_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_G_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_B_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_B_pin,
      fpga_0_VGA_FrameBuffer_TFT_LCD_BLNK_pin => fpga_0_VGA_FrameBuffer_TFT_LCD_BLNK_pin,
      fpga_0_net_gnd_pin => fpga_0_net_gnd_pin,
      fpga_0_net_gnd_1_pin => fpga_0_net_gnd_1_pin,
      fpga_0_net_gnd_2_pin => fpga_0_net_gnd_2_pin,
      fpga_0_net_gnd_3_pin => fpga_0_net_gnd_3_pin,
      fpga_0_net_gnd_4_pin => fpga_0_net_gnd_4_pin,
      fpga_0_net_gnd_5_pin => fpga_0_net_gnd_5_pin,
      fpga_0_net_gnd_6_pin => fpga_0_net_gnd_6_pin,
      fpga_0_DDR_CLK_FB => fpga_0_DDR_CLK_FB,
      fpga_0_DDR_CLK_FB_OUT => fpga_0_DDR_CLK_FB_OUT,
      sys_clk_pin => sys_clk_pin,
      sys_rst_pin => sys_rst_pin
    );

end architecture STRUCTURE;

