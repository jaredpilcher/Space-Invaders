-------------------------------------------------------------------------------
-- lab3_slave_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library lab3_slave;
use lab3_slave.All;

entity lab3_slave_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    Sl_DBus : out std_logic_vector(0 to 31);
    Sl_errAck : out std_logic;
    Sl_retry : out std_logic;
    Sl_toutSup : out std_logic;
    Sl_xferAck : out std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_DBus : in std_logic_vector(0 to 31);
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    interruptRequest : out std_logic;
    exp_io_40_s : in std_logic;
    exp_io_41_s : out std_logic;
    exp_io_42_s : in std_logic;
    exp_io_43_s : out std_logic;
    exp_io_44_s : in std_logic;
    exp_io_45_s : in std_logic;
    exp_io_48_s : out std_logic;
    exp_io_50_s : out std_logic;
    exp_io_52_s : out std_logic;
    exp_io_53_s : out std_logic;
    exp_io_54_s : out std_logic;
    exp_io_55_s : out std_logic;
    exp_io_56_s : out std_logic;
    exp_io_57_s : out std_logic;
    exp_io_58_s : out std_logic;
    exp_io_59_s : out std_logic;
    exp_io_60_s : out std_logic;
    exp_io_61_s : in std_logic;
    exp_io_62_s : out std_logic;
    exp_io_63_s : in std_logic;
    exp_io_64_s : in std_logic;
    exp_io_65_s : out std_logic;
    exp_io_66_s : in std_logic;
    exp_io_67_s : out std_logic;
    exp_io_68_s : in std_logic;
    exp_io_69_s : out std_logic;
    exp_io_70_s : in std_logic;
    exp_io_71_s : out std_logic;
    exp_io_72_s : in std_logic;
    exp_io_73_s : out std_logic;
    exp_io_74_s : in std_logic;
    exp_io_75_s : out std_logic;
    exp_io_76_s : in std_logic
  );
end lab3_slave_0_wrapper;

architecture STRUCTURE of lab3_slave_0_wrapper is

  component lab3_slave is
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
      Sl_DBus : out std_logic_vector(0 to (C_OPB_DWIDTH-1));
      Sl_errAck : out std_logic;
      Sl_retry : out std_logic;
      Sl_toutSup : out std_logic;
      Sl_xferAck : out std_logic;
      OPB_ABus : in std_logic_vector(0 to (C_OPB_AWIDTH-1));
      OPB_BE : in std_logic_vector(0 to ((C_OPB_DWIDTH/8)-1));
      OPB_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH-1));
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      interruptRequest : out std_logic;
      exp_io_40_s : in std_logic;
      exp_io_41_s : out std_logic;
      exp_io_42_s : in std_logic;
      exp_io_43_s : out std_logic;
      exp_io_44_s : in std_logic;
      exp_io_45_s : in std_logic;
      exp_io_48_s : out std_logic;
      exp_io_50_s : out std_logic;
      exp_io_52_s : out std_logic;
      exp_io_53_s : out std_logic;
      exp_io_54_s : out std_logic;
      exp_io_55_s : out std_logic;
      exp_io_56_s : out std_logic;
      exp_io_57_s : out std_logic;
      exp_io_58_s : out std_logic;
      exp_io_59_s : out std_logic;
      exp_io_60_s : out std_logic;
      exp_io_61_s : in std_logic;
      exp_io_62_s : out std_logic;
      exp_io_63_s : in std_logic;
      exp_io_64_s : in std_logic;
      exp_io_65_s : out std_logic;
      exp_io_66_s : in std_logic;
      exp_io_67_s : out std_logic;
      exp_io_68_s : in std_logic;
      exp_io_69_s : out std_logic;
      exp_io_70_s : in std_logic;
      exp_io_71_s : out std_logic;
      exp_io_72_s : in std_logic;
      exp_io_73_s : out std_logic;
      exp_io_74_s : in std_logic;
      exp_io_75_s : out std_logic;
      exp_io_76_s : in std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of lab3_slave : component is "lab3_slave_v";

begin

  lab3_slave_0 : lab3_slave
    generic map (
      C_BASEADDR => X"40080000",
      C_HIGHADDR => X"4008ffff",
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_FAMILY => "virtex2p"
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      Sl_DBus => Sl_DBus,
      Sl_errAck => Sl_errAck,
      Sl_retry => Sl_retry,
      Sl_toutSup => Sl_toutSup,
      Sl_xferAck => Sl_xferAck,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_DBus => OPB_DBus,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      interruptRequest => interruptRequest,
      exp_io_40_s => exp_io_40_s,
      exp_io_41_s => exp_io_41_s,
      exp_io_42_s => exp_io_42_s,
      exp_io_43_s => exp_io_43_s,
      exp_io_44_s => exp_io_44_s,
      exp_io_45_s => exp_io_45_s,
      exp_io_48_s => exp_io_48_s,
      exp_io_50_s => exp_io_50_s,
      exp_io_52_s => exp_io_52_s,
      exp_io_53_s => exp_io_53_s,
      exp_io_54_s => exp_io_54_s,
      exp_io_55_s => exp_io_55_s,
      exp_io_56_s => exp_io_56_s,
      exp_io_57_s => exp_io_57_s,
      exp_io_58_s => exp_io_58_s,
      exp_io_59_s => exp_io_59_s,
      exp_io_60_s => exp_io_60_s,
      exp_io_61_s => exp_io_61_s,
      exp_io_62_s => exp_io_62_s,
      exp_io_63_s => exp_io_63_s,
      exp_io_64_s => exp_io_64_s,
      exp_io_65_s => exp_io_65_s,
      exp_io_66_s => exp_io_66_s,
      exp_io_67_s => exp_io_67_s,
      exp_io_68_s => exp_io_68_s,
      exp_io_69_s => exp_io_69_s,
      exp_io_70_s => exp_io_70_s,
      exp_io_71_s => exp_io_71_s,
      exp_io_72_s => exp_io_72_s,
      exp_io_73_s => exp_io_73_s,
      exp_io_74_s => exp_io_74_s,
      exp_io_75_s => exp_io_75_s,
      exp_io_76_s => exp_io_76_s
    );

end architecture STRUCTURE;

