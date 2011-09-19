-------------------------------------------------------------------------------
-- plb_bram_if_cntlr_1_bram_elaborate.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity plb_bram_if_cntlr_1_bram_elaborate is
  generic (
    C_MEMSIZE : integer;
    C_PORT_DWIDTH : integer;
    C_PORT_AWIDTH : integer;
    C_NUM_WE : integer;
    C_FAMILY : string
    );
  port (
    BRAM_Rst_A : in std_logic;
    BRAM_Clk_A : in std_logic;
    BRAM_EN_A : in std_logic;
    BRAM_WEN_A : in std_logic_vector(0 to C_NUM_WE-1);
    BRAM_Addr_A : in std_logic_vector(0 to C_PORT_AWIDTH-1);
    BRAM_Din_A : out std_logic_vector(0 to C_PORT_DWIDTH-1);
    BRAM_Dout_A : in std_logic_vector(0 to C_PORT_DWIDTH-1);
    BRAM_Rst_B : in std_logic;
    BRAM_Clk_B : in std_logic;
    BRAM_EN_B : in std_logic;
    BRAM_WEN_B : in std_logic_vector(0 to C_NUM_WE-1);
    BRAM_Addr_B : in std_logic_vector(0 to C_PORT_AWIDTH-1);
    BRAM_Din_B : out std_logic_vector(0 to C_PORT_DWIDTH-1);
    BRAM_Dout_B : in std_logic_vector(0 to C_PORT_DWIDTH-1)
  );

  attribute keep_hierarchy : STRING;
  attribute keep_hierarchy of plb_bram_if_cntlr_1_bram_elaborate : entity is "yes";

end plb_bram_if_cntlr_1_bram_elaborate;

architecture STRUCTURE of plb_bram_if_cntlr_1_bram_elaborate is

  component RAMB16_S1_S1 is
    generic (
      WRITE_MODE_A : string;
      WRITE_MODE_B : string
    );
    port (
      ADDRA : in std_logic_vector(13 downto 0);
      CLKA : in std_logic;
      DIA : in std_logic_vector(0 downto 0);
      DOA : out std_logic_vector(0 downto 0);
      ENA : in std_logic;
      SSRA : in std_logic;
      WEA : in std_logic;
      ADDRB : in std_logic_vector(13 downto 0);
      CLKB : in std_logic;
      DIB : in std_logic_vector(0 downto 0);
      DOB : out std_logic_vector(0 downto 0);
      ENB : in std_logic;
      SSRB : in std_logic;
      WEB : in std_logic
    );
  end component;

  -- Internal signals

  signal dina : std_logic_vector(63 downto 0);
  signal dinb : std_logic_vector(63 downto 0);
  signal douta : std_logic_vector(63 downto 0);
  signal doutb : std_logic_vector(63 downto 0);

begin

  -- Internal assignments

  dina(63 downto 0) <= BRAM_Dout_A(0 to 63);
  BRAM_Din_A(0 to 63) <= douta(63 downto 0);
  dinb(63 downto 0) <= BRAM_Dout_B(0 to 63);
  BRAM_Din_B(0 to 63) <= doutb(63 downto 0);

  ramb16_s1_s1_0 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(63 downto 63),
      DOA => douta(63 downto 63),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(63 downto 63),
      DOB => doutb(63 downto 63),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_1 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(62 downto 62),
      DOA => douta(62 downto 62),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(62 downto 62),
      DOB => doutb(62 downto 62),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_2 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(61 downto 61),
      DOA => douta(61 downto 61),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(61 downto 61),
      DOB => doutb(61 downto 61),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_3 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(60 downto 60),
      DOA => douta(60 downto 60),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(60 downto 60),
      DOB => doutb(60 downto 60),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_4 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(59 downto 59),
      DOA => douta(59 downto 59),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(59 downto 59),
      DOB => doutb(59 downto 59),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_5 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(58 downto 58),
      DOA => douta(58 downto 58),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(58 downto 58),
      DOB => doutb(58 downto 58),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_6 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(57 downto 57),
      DOA => douta(57 downto 57),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(57 downto 57),
      DOB => doutb(57 downto 57),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_7 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(56 downto 56),
      DOA => douta(56 downto 56),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(0),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(56 downto 56),
      DOB => doutb(56 downto 56),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(0)
    );

  ramb16_s1_s1_8 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(55 downto 55),
      DOA => douta(55 downto 55),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(55 downto 55),
      DOB => doutb(55 downto 55),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_9 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(54 downto 54),
      DOA => douta(54 downto 54),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(54 downto 54),
      DOB => doutb(54 downto 54),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_10 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(53 downto 53),
      DOA => douta(53 downto 53),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(53 downto 53),
      DOB => doutb(53 downto 53),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_11 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(52 downto 52),
      DOA => douta(52 downto 52),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(52 downto 52),
      DOB => doutb(52 downto 52),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_12 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(51 downto 51),
      DOA => douta(51 downto 51),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(51 downto 51),
      DOB => doutb(51 downto 51),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_13 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(50 downto 50),
      DOA => douta(50 downto 50),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(50 downto 50),
      DOB => doutb(50 downto 50),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_14 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(49 downto 49),
      DOA => douta(49 downto 49),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(49 downto 49),
      DOB => doutb(49 downto 49),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_15 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(48 downto 48),
      DOA => douta(48 downto 48),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(1),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(48 downto 48),
      DOB => doutb(48 downto 48),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(1)
    );

  ramb16_s1_s1_16 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(47 downto 47),
      DOA => douta(47 downto 47),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(47 downto 47),
      DOB => doutb(47 downto 47),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_17 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(46 downto 46),
      DOA => douta(46 downto 46),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(46 downto 46),
      DOB => doutb(46 downto 46),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_18 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(45 downto 45),
      DOA => douta(45 downto 45),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(45 downto 45),
      DOB => doutb(45 downto 45),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_19 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(44 downto 44),
      DOA => douta(44 downto 44),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(44 downto 44),
      DOB => doutb(44 downto 44),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_20 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(43 downto 43),
      DOA => douta(43 downto 43),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(43 downto 43),
      DOB => doutb(43 downto 43),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_21 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(42 downto 42),
      DOA => douta(42 downto 42),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(42 downto 42),
      DOB => doutb(42 downto 42),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_22 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(41 downto 41),
      DOA => douta(41 downto 41),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(41 downto 41),
      DOB => doutb(41 downto 41),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_23 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(40 downto 40),
      DOA => douta(40 downto 40),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(2),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(40 downto 40),
      DOB => doutb(40 downto 40),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(2)
    );

  ramb16_s1_s1_24 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(39 downto 39),
      DOA => douta(39 downto 39),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(39 downto 39),
      DOB => doutb(39 downto 39),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_25 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(38 downto 38),
      DOA => douta(38 downto 38),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(38 downto 38),
      DOB => doutb(38 downto 38),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_26 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(37 downto 37),
      DOA => douta(37 downto 37),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(37 downto 37),
      DOB => doutb(37 downto 37),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_27 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(36 downto 36),
      DOA => douta(36 downto 36),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(36 downto 36),
      DOB => doutb(36 downto 36),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_28 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(35 downto 35),
      DOA => douta(35 downto 35),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(35 downto 35),
      DOB => doutb(35 downto 35),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_29 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(34 downto 34),
      DOA => douta(34 downto 34),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(34 downto 34),
      DOB => doutb(34 downto 34),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_30 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(33 downto 33),
      DOA => douta(33 downto 33),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(33 downto 33),
      DOB => doutb(33 downto 33),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_31 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(32 downto 32),
      DOA => douta(32 downto 32),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(3),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(32 downto 32),
      DOB => doutb(32 downto 32),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(3)
    );

  ramb16_s1_s1_32 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(31 downto 31),
      DOA => douta(31 downto 31),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(31 downto 31),
      DOB => doutb(31 downto 31),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_33 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(30 downto 30),
      DOA => douta(30 downto 30),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(30 downto 30),
      DOB => doutb(30 downto 30),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_34 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(29 downto 29),
      DOA => douta(29 downto 29),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(29 downto 29),
      DOB => doutb(29 downto 29),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_35 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(28 downto 28),
      DOA => douta(28 downto 28),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(28 downto 28),
      DOB => doutb(28 downto 28),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_36 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(27 downto 27),
      DOA => douta(27 downto 27),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(27 downto 27),
      DOB => doutb(27 downto 27),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_37 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(26 downto 26),
      DOA => douta(26 downto 26),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(26 downto 26),
      DOB => doutb(26 downto 26),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_38 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(25 downto 25),
      DOA => douta(25 downto 25),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(25 downto 25),
      DOB => doutb(25 downto 25),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_39 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(24 downto 24),
      DOA => douta(24 downto 24),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(4),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(24 downto 24),
      DOB => doutb(24 downto 24),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(4)
    );

  ramb16_s1_s1_40 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(23 downto 23),
      DOA => douta(23 downto 23),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(23 downto 23),
      DOB => doutb(23 downto 23),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_41 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(22 downto 22),
      DOA => douta(22 downto 22),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(22 downto 22),
      DOB => doutb(22 downto 22),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_42 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(21 downto 21),
      DOA => douta(21 downto 21),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(21 downto 21),
      DOB => doutb(21 downto 21),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_43 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(20 downto 20),
      DOA => douta(20 downto 20),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(20 downto 20),
      DOB => doutb(20 downto 20),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_44 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(19 downto 19),
      DOA => douta(19 downto 19),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(19 downto 19),
      DOB => doutb(19 downto 19),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_45 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(18 downto 18),
      DOA => douta(18 downto 18),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(18 downto 18),
      DOB => doutb(18 downto 18),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_46 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(17 downto 17),
      DOA => douta(17 downto 17),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(17 downto 17),
      DOB => doutb(17 downto 17),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_47 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(16 downto 16),
      DOA => douta(16 downto 16),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(5),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(16 downto 16),
      DOB => doutb(16 downto 16),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(5)
    );

  ramb16_s1_s1_48 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(15 downto 15),
      DOA => douta(15 downto 15),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(15 downto 15),
      DOB => doutb(15 downto 15),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_49 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(14 downto 14),
      DOA => douta(14 downto 14),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(14 downto 14),
      DOB => doutb(14 downto 14),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_50 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(13 downto 13),
      DOA => douta(13 downto 13),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(13 downto 13),
      DOB => doutb(13 downto 13),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_51 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(12 downto 12),
      DOA => douta(12 downto 12),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(12 downto 12),
      DOB => doutb(12 downto 12),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_52 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(11 downto 11),
      DOA => douta(11 downto 11),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(11 downto 11),
      DOB => doutb(11 downto 11),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_53 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(10 downto 10),
      DOA => douta(10 downto 10),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(10 downto 10),
      DOB => doutb(10 downto 10),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_54 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(9 downto 9),
      DOA => douta(9 downto 9),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(9 downto 9),
      DOB => doutb(9 downto 9),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_55 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(8 downto 8),
      DOA => douta(8 downto 8),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(6),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(8 downto 8),
      DOB => doutb(8 downto 8),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(6)
    );

  ramb16_s1_s1_56 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(7 downto 7),
      DOA => douta(7 downto 7),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(7 downto 7),
      DOB => doutb(7 downto 7),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_57 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(6 downto 6),
      DOA => douta(6 downto 6),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(6 downto 6),
      DOB => doutb(6 downto 6),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_58 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(5 downto 5),
      DOA => douta(5 downto 5),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(5 downto 5),
      DOB => doutb(5 downto 5),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_59 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(4 downto 4),
      DOA => douta(4 downto 4),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(4 downto 4),
      DOB => doutb(4 downto 4),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_60 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(3 downto 3),
      DOA => douta(3 downto 3),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(3 downto 3),
      DOB => doutb(3 downto 3),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_61 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(2 downto 2),
      DOA => douta(2 downto 2),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(2 downto 2),
      DOB => doutb(2 downto 2),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_62 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(1 downto 1),
      DOA => douta(1 downto 1),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(1 downto 1),
      DOB => doutb(1 downto 1),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

  ramb16_s1_s1_63 : RAMB16_S1_S1
    generic map (
      WRITE_MODE_A => "WRITE_FIRST",
      WRITE_MODE_B => "WRITE_FIRST"
    )
    port map (
      ADDRA => BRAM_Addr_A(15 to 28),
      CLKA => BRAM_Clk_A,
      DIA => dina(0 downto 0),
      DOA => douta(0 downto 0),
      ENA => BRAM_EN_A,
      SSRA => BRAM_Rst_A,
      WEA => BRAM_WEN_A(7),
      ADDRB => BRAM_Addr_B(15 to 28),
      CLKB => BRAM_Clk_B,
      DIB => dinb(0 downto 0),
      DOB => doutb(0 downto 0),
      ENB => BRAM_EN_B,
      SSRB => BRAM_Rst_B,
      WEB => BRAM_WEN_B(7)
    );

end architecture STRUCTURE;

