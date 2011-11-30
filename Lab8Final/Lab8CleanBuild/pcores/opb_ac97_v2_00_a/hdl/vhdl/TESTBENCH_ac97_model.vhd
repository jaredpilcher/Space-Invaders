-------------------------------------------------------------------------------
-- $Id: TESTBENCH_ac97_model.vhd,v 1.1 2005/02/18 15:30:21 wirthlin Exp $
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
-- Filename:        TESTBENCH_ac97_core.vhd
--
-- Description:     Simple testbench for ac97_core
-- 
-- VHDL-Standard:   VHDL'93
-------------------------------------------------------------------------------
-- Structure:   
--
-------------------------------------------------------------------------------
-- Author:          Mike Wirthlin
-- Revision:        $Revision: 1.1 $
-- Date:            $Date: 2005/02/18 15:30:21 $
--
-- History:
--
-------------------------------------------------------------------------------
-- Naming Conventions:
--      active low signals:                     "*_n"
--      clock signals:                          "clk", "clk_div#", "clk_#x" 
--      reset signals:                          "rst", "rst_n" 
--      generics:                               "C_*" 
--      user defined types:                     "*_TYPE" 
--      state machine next state:               "*_ns" 
--      state machine current state:            "*_cs" 
--      combinatorial signals:                  "*_com" 
--      pipelined or register delay signals:    "*_d#" 
--      counter signals:                        "*cnt*"
--      clock enable signals:                   "*_ce" 
--      internal version of output port         "*_i"
--      device pins:                            "*_pin" 
--      ports:                                  - Names begin with Uppercase 
--      processes:                              "*_PROCESS" 
--      component instantiations:               "<ENTITY_>I_<#|FUNC>
-------------------------------------------------------------------------------
library IEEE;
use IEEE.std_logic_1164.all;

entity TESTBENCH_ac97_core is
end TESTBENCH_ac97_core;

library opb_ac97_v2_00_a;
use opb_ac97_v2_00_a.all;
use opb_ac97_v2_00_a.TESTBENCH_ac97_package.all;

architecture behavioral of TESTBENCH_ac97_core is
  
  component ac97_core
  generic (
    C_PLAYBACK : integer := 1;
    C_RECORD   : integer := 1;
    C_PCM_DATA_WIDTH : integer := 16
    );
  port (

    Reset : in std_logic;

    -- signals attaching directly to AC97 codec
    AC97_Bit_Clk   : in  std_logic;
    AC97_Sync      : out std_logic;
    AC97_SData_Out : out std_logic;
    AC97_SData_In  : in  std_logic;

    AC97_Reg_Addr         : in  std_logic_vector(0 to 6);
    AC97_Reg_Write_Data   : in  std_logic_vector(0 to 15);
    AC97_Reg_Read_Data    : out std_logic_vector(0 to 15);
    AC97_Reg_Read_Data_Valid : out std_logic;
    
    AC97_Reg_Read         : in  std_logic;
    AC97_Reg_Write        : in  std_logic;
    AC97_Reg_Ready        : out  std_logic;

    PCM_Playback_Left: in std_logic_vector(0 to 15);
    PCM_Playback_Right: in std_logic_vector(0 to 15);
    PCM_Playback_Left_Valid: in std_logic;
    PCM_Playback_Right_Valid: in std_logic;

    PCM_Record_Left: out std_logic_vector(0 to 15);
    PCM_Record_Right: out std_logic_vector(0 to 15);
    PCM_Record_Left_Valid: out std_logic;
    PCM_Record_Right_Valid: out std_logic;

    New_Frame : out std_logic;

    CODEC_RDY : out std_logic

    );
  end component;

  component ac97_model is
  port (
    AC97Reset_n   : in  std_logic;         
    Bit_Clk   : out  std_logic;
    Sync      : in std_logic;
    SData_Out : in std_logic;
    SData_In  : out  std_logic
    );
  end component;

  signal reset : std_logic;
  signal ac97_reset : std_logic;

  signal clk : std_logic;
  signal sync : std_logic;
  signal sdata_out : std_logic;
  signal sdata_in : std_logic;

  signal reg_addr : std_logic_vector(0 to 6);
  signal reg_write_data   :   std_logic_vector(0 to 15);
  signal reg_read_data : std_logic_vector(0 to 15);
  signal reg_read_data_valid : std_logic;
    
  signal reg_read : std_logic;
  signal reg_write :  std_logic;
  signal reg_ready :  std_logic;

  signal PCM_Playback_Left:  std_logic_vector(0 to 15);
  signal PCM_Playback_Right: std_logic_vector(0 to 15);
  signal PCM_Playback_Left_Valid:  std_logic;
  signal PCM_Playback_Right_Valid: std_logic;
  
  signal PCM_Record_Left:  std_logic_vector(0 to 15);
  signal PCM_Record_Right:  std_logic_vector(0 to 15);
  signal PCM_Record_Left_Valid:  std_logic;
  signal PCM_Record_Right_Valid:  std_logic;
  
  signal New_Frame :  std_logic;
  
  signal CODEC_RDY :  std_logic;

  signal test_no : integer;
  
begin  -- behavioral

  ac97_reset <= not reset;
  
  uut_1 : ac97_model
  port map (
    AC97Reset_n => ac97_reset,
    Bit_Clk => clk,
    Sync => sync,
    SData_Out => sdata_out,
    SData_In => sdata_in
    );

  uut: ac97_core
  generic map (
    C_PLAYBACK => 1,
    C_RECORD => 1
    )
  port map (

    Reset => reset,

    -- signals attaching directly to AC97 codec
    AC97_Bit_Clk   => clk,
    AC97_Sync      => sync,
    AC97_SData_Out => sdata_out,
    AC97_SData_In  => sdata_in,

    AC97_Reg_Addr         => reg_addr,
    AC97_Reg_Write_Data   => reg_write_data,
    AC97_Reg_Read_Data    => reg_read_data,
    AC97_Reg_Read_Data_Valid => reg_read_data_valid,
    
    AC97_Reg_Read         => reg_read,
    AC97_Reg_Write        => reg_write,
    AC97_Reg_Ready        => reg_ready,

    PCM_Playback_Left => PCM_Playback_Left,
    PCM_Playback_Right => PCM_Playback_Right,
    PCM_Playback_Left_Valid => PCM_Playback_Left_Valid,
    PCM_Playback_Right_Valid => PCM_Playback_Right_Valid,

    PCM_Record_Left => PCM_Record_Left,
    PCM_Record_Right => PCM_Record_Right,
    PCM_Record_Left_Valid => PCM_Record_Left_Valid,
    PCM_Record_Right_Valid => PCM_Record_Right_Valid,

    New_Frame => New_Frame,

    CODEC_RDY => CODEC_RDY

    );


  -- simulate a reset
   opb_rst_gen: process
   begin
     reset <= '1';
     wait for 20 ns;
     reset <= '0'; 
     wait;
   end process opb_rst_gen;

   -- Test process
  test_process: process
  begin

    test_no <= 0;

    -- set default values
    reg_addr <= (others => '0');
    reg_write_data <= (others => '0');

    reg_read <= '0';
    reg_write <= '0';

    PCM_Playback_Left <= (others => '0');       
    PCM_Playback_Right <= (others => '0');
    PCM_Playback_Left_Valid <= '0';
    PCM_Playback_Right_Valid <= '0';

    -- 1. Wait until CODEC ready before doing anything
    wait until CODEC_RDY='1' and clk'event and clk='1';

    -- skip some time slots before performing a bus cycle 
    for i in 300 downto 0 loop
      wait until clk'event and clk='1';
    end loop;
    
    -- Start at first sync pulse
    wait until Sync'event and Sync='1';

    --wait until clk'event and clk='1';
    wait until clk'event and clk='1';

    test_no <= 1;

    -- send some playback data
    PCM_Playback_Left <= X"8001";
    PCM_Playback_Right <= X"0180";
    PCM_Playback_Left_Valid <= '1';
    PCM_Playback_Right_Valid <= '1';

    wait until New_Frame'event and New_Frame='0';

    test_no <= 2;

    PCM_Playback_Left <= X"4002";
    PCM_Playback_Right <= X"0240";

    wait until New_Frame'event and New_Frame='0';

    test_no <= 3;

    -- send a read command
    PCM_Playback_Left <= X"2004";
    PCM_Playback_Right <= X"0420";
    reg_addr <= "0010001";
    reg_read <= '1';
    wait until New_Frame'event and New_Frame='0';

    reg_read <= '0';
    
    wait;

    -- send a write command
    PCM_Playback_Left <= X"2004";
    PCM_Playback_Right <= X"0420";
    reg_addr <= "0010001";
    reg_write_data <= X"5A5A";
    reg_write <= '1';
    
    wait until New_Frame'event and New_Frame='0';
    
    wait;
  end process;
  
--   -- Recording Data
--   sdata_in_proc: process
--     variable slot0 : std_logic_vector(15 downto 0) := "1001100000000000";
--     -- Control address
--     variable slot1 : std_logic_vector(19 downto 0) := "10000000000000000000";
--     -- Control data
--     variable slot2 : std_logic_vector(19 downto 0) := "10000000000000000000";
--     -- PCM left (0x69696)
--     variable slot3 : std_logic_vector(19 downto 0) := "01101001011010010110";
--     -- PCM right (0x96969)
--     variable slot4 : std_logic_vector(19 downto 0) := "10010110100101101001";
--   begin
--     sdata_in <= '0';

--     -- 1. Wait until CODEC ready before doing anything
--     wait until CODEC_RDY='1' and clk'event and clk='1';

--     -- skip some time slots before performing a bus cycle 
--     for i in 300 downto 0 loop
--       wait until clk'event and clk='1';
--     end loop;
    
--     -- Start at first sync pulse
--     wait until Sync'event and Sync='1';

--     --wait until clk'event and clk='1';
--     wait until clk'event and clk='1';

--     -- (1) record data
--     send_basic_frame(clk, slot0, slot1, slot2, slot3, slot4, sdata_in);

--     -- (2) record data
--     slot3  := X"8001_0";
--     slot4  := X"1234_0";
--     send_basic_frame(clk, slot0, slot1, slot2, slot3, slot4, sdata_in);

--     -- (3) record data
--     slot3  := X"4002_0";
--     slot4  := X"2345_0";
--     send_basic_frame(clk, slot0, slot1, slot2, slot3, slot4, sdata_in);
    
--     -- (4) record data & some control data
--     slot3  := X"2004_0";
--     slot4  := X"3456_0";
--     slot0 := "1011100000000000";
--     slot2 := X"FEDC_B";
--     send_basic_frame(clk, slot0, slot1, slot2, slot3, slot4, sdata_in);

--     -- (5) record data
--     slot3  := X"1008_0";
--     slot4  := X"3456_0";
--     send_basic_frame(clk, slot0, slot1, slot2, slot3, slot4, sdata_in);

--     wait;
    
--   end process;       

--   -- Recording Data
--   control_proc: process
--   begin

--     reg_addr <= (others => '0');
--     reg_write_data <= (others => '0');

--     reg_read <= '0';
--     reg_write <= '0';

--     PCM_Playback_Left <= (others => '0');       
--     PCM_Playback_Right <= (others => '0');
--     PCM_Playback_Left_Valid <= '0';
--     PCM_Playback_Right_Valid <= '0';

--     -- skip 2 frames
--     for i in 1 downto 0 loop
--       wait until New_Frame'event and New_Frame='0';
--     end loop;

--     -- send some playback data
--     PCM_Playback_Left <= X"8001";
--     PCM_Playback_Right <= X"0180";
--     PCM_Playback_Left_Valid <= '1';
--     PCM_Playback_Right_Valid <= '1';

--     wait until New_Frame'event and New_Frame='0';

--     PCM_Playback_Left <= X"4002";
--     PCM_Playback_Right <= X"0240";

--     wait until New_Frame'event and New_Frame='0';
--     -- send a write command
--     PCM_Playback_Left <= X"2004";
--     PCM_Playback_Right <= X"0420";
--     reg_addr <= "0010001";
--     reg_write_data <= X"5A5A";
--     reg_write <= '1';
    
--     wait until New_Frame'event and New_Frame='0';
--     reg_write <= '0';

--     PCM_Playback_Left <= X"1008";
--     PCM_Playback_Right <= X"0810";
    

--     wait;
    
--   end process;       
  
end behavioral;
