-------------------------------------------------------------------------------
-- chipscope_opb_iba_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity chipscope_opb_iba_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    SYS_Rst : in std_logic;
    Debug_SYS_Rst : in std_logic;
    WDT_Rst : in std_logic;
    M_ABus : in std_logic_vector(0 to 63);
    M_BE : in std_logic_vector(0 to 7);
    M_beXfer : in std_logic_vector(0 to 1);
    M_busLock : in std_logic_vector(0 to 1);
    M_DBus : in std_logic_vector(0 to 63);
    M_DBusEn : in std_logic_vector(0 to 1);
    M_DBusEn32_63 : in std_logic_vector(0 to 1);
    M_dwXfer : in std_logic_vector(0 to 1);
    M_fwXfer : in std_logic_vector(0 to 1);
    M_hwXfer : in std_logic_vector(0 to 1);
    M_request : in std_logic_vector(0 to 1);
    M_RNW : in std_logic_vector(0 to 1);
    M_select : in std_logic_vector(0 to 1);
    M_seqAddr : in std_logic_vector(0 to 1);
    Sl_beAck : in std_logic_vector(0 to 10);
    Sl_DBus : in std_logic_vector(0 to 351);
    Sl_DBusEn : in std_logic_vector(0 to 10);
    Sl_DBusEn32_63 : in std_logic_vector(0 to 10);
    Sl_errAck : in std_logic_vector(0 to 10);
    Sl_dwAck : in std_logic_vector(0 to 10);
    Sl_fwAck : in std_logic_vector(0 to 10);
    Sl_hwAck : in std_logic_vector(0 to 10);
    Sl_retry : in std_logic_vector(0 to 10);
    Sl_toutSup : in std_logic_vector(0 to 10);
    Sl_xferAck : in std_logic_vector(0 to 10);
    OPB_MRequest : in std_logic_vector(0 to 1);
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_beXfer : in std_logic;
    OPB_beAck : in std_logic;
    OPB_busLock : in std_logic;
    OPB_rdDBus : in std_logic_vector(0 to 31);
    OPB_wrDBus : in std_logic_vector(0 to 31);
    OPB_DBus : in std_logic_vector(0 to 31);
    OPB_errAck : in std_logic;
    OPB_dwAck : in std_logic;
    OPB_dwXfer : in std_logic;
    OPB_fwAck : in std_logic;
    OPB_fwXfer : in std_logic;
    OPB_hwAck : in std_logic;
    OPB_hwXfer : in std_logic;
    OPB_MGrant : in std_logic_vector(0 to 1);
    OPB_pendReq : in std_logic_vector(0 to 1);
    OPB_retry : in std_logic;
    OPB_RNW : in std_logic;
    OPB_select : in std_logic;
    OPB_seqAddr : in std_logic;
    OPB_timeout : in std_logic;
    OPB_toutSup : in std_logic;
    OPB_xferAck : in std_logic;
    chipscope_icon_control : in std_logic_vector(35 downto 0);
    iba_trig_in : in std_logic_vector(7 downto 0);
    iba_trig_out : out std_logic
  );
end chipscope_opb_iba_0_wrapper;

architecture STRUCTURE of chipscope_opb_iba_0_wrapper is

  component chipscope_opb_iba is
    generic (
      C_OPB_AWIDTH : integer;
      C_OPB_DWIDTH : integer;
      C_NUM_MASTERS : integer;
      C_NUM_SLAVES : integer;
      C_FAMILY : string;
      C_DEVICE : string;
      C_PACKAGE : string;
      C_SPEEDGRADE : string;
      C_NUM_DATA_SAMPLES : integer;
      C_ENABLE_TRIGGER_OUT : integer;
      C_DISABLE_SRL16S : integer;
      C_RISING_CLOCK_EDGE : integer;
      C_ENABLE_TRIGGER_SEQUENCER : integer;
      C_MAX_SEQUENCER_LEVELS : integer;
      C_ENABLE_STORAGE_QUALIFICATION : integer;
      C_CONTROL_UNITS : integer;
      C_CONTROL_UNIT_COUNTER_WIDTH : integer;
      C_CONTROL_UNIT_MATCH_TYPE : string;
      C_ADDR_UNITS : integer;
      C_ADDR_UNIT_COUNTER_WIDTH : integer;
      C_ADDR_UNIT_MATCH_TYPE : string;
      C_DATA_UNITS : integer;
      C_DATA_UNIT_COUNTER_WIDTH : integer;
      C_DATA_UNIT_MATCH_TYPE : string;
      C_WRDATA_UNITS : integer;
      C_WRDATA_UNIT_COUNTER_WIDTH : integer;
      C_WRDATA_UNIT_MATCH_TYPE : string;
      C_RDDATA_UNITS : integer;
      C_RDDATA_UNIT_COUNTER_WIDTH : integer;
      C_RDDATA_UNIT_MATCH_TYPE : string;
      C_PV_UNITS : integer;
      C_PV_UNIT_COUNTER_WIDTH : integer;
      C_PV_UNIT_MATCH_TYPE : string;
      C_GENERIC_TRIGGER_UNITS : integer;
      C_TRIGGER_UNIT_COUNTER_WIDTH : integer;
      C_TRIGGER_UNIT_MATCH_TYPE : string;
      C_GENERIC_TRIGGER_IN_WIDTH : integer;
      C_MASTER0_UNITS : integer;
      C_MASTER0_UNIT_COUNTER_WIDTH : integer;
      C_MASTER0_UNIT_MATCH_TYPE : string;
      C_MASTER1_UNITS : integer;
      C_MASTER1_UNIT_COUNTER_WIDTH : integer;
      C_MASTER1_UNIT_MATCH_TYPE : string;
      C_MASTER2_UNITS : integer;
      C_MASTER2_UNIT_COUNTER_WIDTH : integer;
      C_MASTER2_UNIT_MATCH_TYPE : string;
      C_MASTER3_UNITS : integer;
      C_MASTER3_UNIT_COUNTER_WIDTH : integer;
      C_MASTER3_UNIT_MATCH_TYPE : string;
      C_MASTER4_UNITS : integer;
      C_MASTER4_UNIT_COUNTER_WIDTH : integer;
      C_MASTER4_UNIT_MATCH_TYPE : string;
      C_MASTER5_UNITS : integer;
      C_MASTER5_UNIT_COUNTER_WIDTH : integer;
      C_MASTER5_UNIT_MATCH_TYPE : string;
      C_MASTER6_UNITS : integer;
      C_MASTER6_UNIT_COUNTER_WIDTH : integer;
      C_MASTER6_UNIT_MATCH_TYPE : string;
      C_MASTER7_UNITS : integer;
      C_MASTER7_UNIT_COUNTER_WIDTH : integer;
      C_MASTER7_UNIT_MATCH_TYPE : string;
      C_SLAVE0_UNITS : integer;
      C_SLAVE0_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE0_UNIT_MATCH_TYPE : string;
      C_SLAVE1_UNITS : integer;
      C_SLAVE1_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE1_UNIT_MATCH_TYPE : string;
      C_SLAVE2_UNITS : integer;
      C_SLAVE2_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE2_UNIT_MATCH_TYPE : string;
      C_SLAVE3_UNITS : integer;
      C_SLAVE3_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE3_UNIT_MATCH_TYPE : string;
      C_SLAVE4_UNITS : integer;
      C_SLAVE4_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE4_UNIT_MATCH_TYPE : string;
      C_SLAVE5_UNITS : integer;
      C_SLAVE5_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE5_UNIT_MATCH_TYPE : string;
      C_SLAVE6_UNITS : integer;
      C_SLAVE6_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE6_UNIT_MATCH_TYPE : string;
      C_SLAVE7_UNITS : integer;
      C_SLAVE7_UNIT_COUNTER_WIDTH : integer;
      C_SLAVE7_UNIT_MATCH_TYPE : string;
      C_DISABLE_RPM : integer
    );
    port (
      OPB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      SYS_Rst : in std_logic;
      Debug_SYS_Rst : in std_logic;
      WDT_Rst : in std_logic;
      M_ABus : in std_logic_vector(0 to (C_OPB_AWIDTH*C_NUM_MASTERS)-1);
      M_BE : in std_logic_vector(0 to (C_OPB_DWIDTH+7)/8*C_NUM_MASTERS-1);
      M_beXfer : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_busLock : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH*C_NUM_MASTERS)-1);
      M_DBusEn : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_DBusEn32_63 : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_dwXfer : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_fwXfer : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_hwXfer : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_request : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_RNW : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_select : in std_logic_vector(0 to C_NUM_MASTERS-1);
      M_seqAddr : in std_logic_vector(0 to C_NUM_MASTERS-1);
      Sl_beAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_DBus : in std_logic_vector(0 to (C_OPB_DWIDTH*C_NUM_SLAVES)-1);
      Sl_DBusEn : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_DBusEn32_63 : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_errAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_dwAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_fwAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_hwAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_retry : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_toutSup : in std_logic_vector(0 to C_NUM_SLAVES-1);
      Sl_xferAck : in std_logic_vector(0 to C_NUM_SLAVES-1);
      OPB_MRequest : in std_logic_vector(0 to C_NUM_MASTERS-1);
      OPB_ABus : in std_logic_vector(0 to C_OPB_AWIDTH-1);
      OPB_BE : in std_logic_vector(0 to (C_OPB_DWIDTH+7)/8-1);
      OPB_beXfer : in std_logic;
      OPB_beAck : in std_logic;
      OPB_busLock : in std_logic;
      OPB_rdDBus : in std_logic_vector(0 to C_OPB_DWIDTH-1);
      OPB_wrDBus : in std_logic_vector(0 to C_OPB_DWIDTH-1);
      OPB_DBus : in std_logic_vector(0 to C_OPB_DWIDTH-1);
      OPB_errAck : in std_logic;
      OPB_dwAck : in std_logic;
      OPB_dwXfer : in std_logic;
      OPB_fwAck : in std_logic;
      OPB_fwXfer : in std_logic;
      OPB_hwAck : in std_logic;
      OPB_hwXfer : in std_logic;
      OPB_MGrant : in std_logic_vector(0 to C_NUM_MASTERS-1);
      OPB_pendReq : in std_logic_vector(0 to C_NUM_MASTERS-1);
      OPB_retry : in std_logic;
      OPB_RNW : in std_logic;
      OPB_select : in std_logic;
      OPB_seqAddr : in std_logic;
      OPB_timeout : in std_logic;
      OPB_toutSup : in std_logic;
      OPB_xferAck : in std_logic;
      chipscope_icon_control : in std_logic_vector(35 downto 0);
      iba_trig_in : in std_logic_vector(C_GENERIC_TRIGGER_IN_WIDTH-1 downto 0);
      iba_trig_out : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute box_type : STRING;
  attribute x_core_info of chipscope_opb_iba : component is "chipscope_opb_iba_v1_01_a";
  attribute box_type of chipscope_opb_iba : component is "black_box";

begin

  chipscope_opb_iba_0 : chipscope_opb_iba
    generic map (
      C_OPB_AWIDTH => 32,
      C_OPB_DWIDTH => 32,
      C_NUM_MASTERS => 2,
      C_NUM_SLAVES => 11,
      C_FAMILY => "virtex2p",
      C_DEVICE => "2vp30",
      C_PACKAGE => "ff896",
      C_SPEEDGRADE => "-7",
      C_NUM_DATA_SAMPLES => 512,
      C_ENABLE_TRIGGER_OUT => 1,
      C_DISABLE_SRL16S => 0,
      C_RISING_CLOCK_EDGE => 1,
      C_ENABLE_TRIGGER_SEQUENCER => 1,
      C_MAX_SEQUENCER_LEVELS => 16,
      C_ENABLE_STORAGE_QUALIFICATION => 1,
      C_CONTROL_UNITS => 1,
      C_CONTROL_UNIT_COUNTER_WIDTH => 0,
      C_CONTROL_UNIT_MATCH_TYPE => "basic with edges",
      C_ADDR_UNITS => 1,
      C_ADDR_UNIT_COUNTER_WIDTH => 0,
      C_ADDR_UNIT_MATCH_TYPE => "extended with edges",
      C_DATA_UNITS => 1,
      C_DATA_UNIT_COUNTER_WIDTH => 0,
      C_DATA_UNIT_MATCH_TYPE => "basic",
      C_WRDATA_UNITS => 0,
      C_WRDATA_UNIT_COUNTER_WIDTH => 0,
      C_WRDATA_UNIT_MATCH_TYPE => "basic",
      C_RDDATA_UNITS => 0,
      C_RDDATA_UNIT_COUNTER_WIDTH => 0,
      C_RDDATA_UNIT_MATCH_TYPE => "basic",
      C_PV_UNITS => 0,
      C_PV_UNIT_COUNTER_WIDTH => 0,
      C_PV_UNIT_MATCH_TYPE => "basic",
      C_GENERIC_TRIGGER_UNITS => 0,
      C_TRIGGER_UNIT_COUNTER_WIDTH => 0,
      C_TRIGGER_UNIT_MATCH_TYPE => "extended with edges",
      C_GENERIC_TRIGGER_IN_WIDTH => 8,
      C_MASTER0_UNITS => 0,
      C_MASTER0_UNIT_COUNTER_WIDTH => 0,
      C_MASTER0_UNIT_MATCH_TYPE => "basic",
      C_MASTER1_UNITS => 0,
      C_MASTER1_UNIT_COUNTER_WIDTH => 0,
      C_MASTER1_UNIT_MATCH_TYPE => "basic",
      C_MASTER2_UNITS => 0,
      C_MASTER2_UNIT_COUNTER_WIDTH => 0,
      C_MASTER2_UNIT_MATCH_TYPE => "basic",
      C_MASTER3_UNITS => 0,
      C_MASTER3_UNIT_COUNTER_WIDTH => 0,
      C_MASTER3_UNIT_MATCH_TYPE => "basic",
      C_MASTER4_UNITS => 0,
      C_MASTER4_UNIT_COUNTER_WIDTH => 0,
      C_MASTER4_UNIT_MATCH_TYPE => "basic",
      C_MASTER5_UNITS => 0,
      C_MASTER5_UNIT_COUNTER_WIDTH => 0,
      C_MASTER5_UNIT_MATCH_TYPE => "basic",
      C_MASTER6_UNITS => 0,
      C_MASTER6_UNIT_COUNTER_WIDTH => 0,
      C_MASTER6_UNIT_MATCH_TYPE => "basic",
      C_MASTER7_UNITS => 0,
      C_MASTER7_UNIT_COUNTER_WIDTH => 0,
      C_MASTER7_UNIT_MATCH_TYPE => "basic",
      C_SLAVE0_UNITS => 0,
      C_SLAVE0_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE0_UNIT_MATCH_TYPE => "basic",
      C_SLAVE1_UNITS => 0,
      C_SLAVE1_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE1_UNIT_MATCH_TYPE => "basic",
      C_SLAVE2_UNITS => 0,
      C_SLAVE2_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE2_UNIT_MATCH_TYPE => "basic",
      C_SLAVE3_UNITS => 0,
      C_SLAVE3_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE3_UNIT_MATCH_TYPE => "basic",
      C_SLAVE4_UNITS => 0,
      C_SLAVE4_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE4_UNIT_MATCH_TYPE => "basic",
      C_SLAVE5_UNITS => 0,
      C_SLAVE5_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE5_UNIT_MATCH_TYPE => "basic",
      C_SLAVE6_UNITS => 0,
      C_SLAVE6_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE6_UNIT_MATCH_TYPE => "basic",
      C_SLAVE7_UNITS => 0,
      C_SLAVE7_UNIT_COUNTER_WIDTH => 0,
      C_SLAVE7_UNIT_MATCH_TYPE => "basic",
      C_DISABLE_RPM => 0
    )
    port map (
      OPB_Clk => OPB_Clk,
      OPB_Rst => OPB_Rst,
      SYS_Rst => SYS_Rst,
      Debug_SYS_Rst => Debug_SYS_Rst,
      WDT_Rst => WDT_Rst,
      M_ABus => M_ABus,
      M_BE => M_BE,
      M_beXfer => M_beXfer,
      M_busLock => M_busLock,
      M_DBus => M_DBus,
      M_DBusEn => M_DBusEn,
      M_DBusEn32_63 => M_DBusEn32_63,
      M_dwXfer => M_dwXfer,
      M_fwXfer => M_fwXfer,
      M_hwXfer => M_hwXfer,
      M_request => M_request,
      M_RNW => M_RNW,
      M_select => M_select,
      M_seqAddr => M_seqAddr,
      Sl_beAck => Sl_beAck,
      Sl_DBus => Sl_DBus,
      Sl_DBusEn => Sl_DBusEn,
      Sl_DBusEn32_63 => Sl_DBusEn32_63,
      Sl_errAck => Sl_errAck,
      Sl_dwAck => Sl_dwAck,
      Sl_fwAck => Sl_fwAck,
      Sl_hwAck => Sl_hwAck,
      Sl_retry => Sl_retry,
      Sl_toutSup => Sl_toutSup,
      Sl_xferAck => Sl_xferAck,
      OPB_MRequest => OPB_MRequest,
      OPB_ABus => OPB_ABus,
      OPB_BE => OPB_BE,
      OPB_beXfer => OPB_beXfer,
      OPB_beAck => OPB_beAck,
      OPB_busLock => OPB_busLock,
      OPB_rdDBus => OPB_rdDBus,
      OPB_wrDBus => OPB_wrDBus,
      OPB_DBus => OPB_DBus,
      OPB_errAck => OPB_errAck,
      OPB_dwAck => OPB_dwAck,
      OPB_dwXfer => OPB_dwXfer,
      OPB_fwAck => OPB_fwAck,
      OPB_fwXfer => OPB_fwXfer,
      OPB_hwAck => OPB_hwAck,
      OPB_hwXfer => OPB_hwXfer,
      OPB_MGrant => OPB_MGrant,
      OPB_pendReq => OPB_pendReq,
      OPB_retry => OPB_retry,
      OPB_RNW => OPB_RNW,
      OPB_select => OPB_select,
      OPB_seqAddr => OPB_seqAddr,
      OPB_timeout => OPB_timeout,
      OPB_toutSup => OPB_toutSup,
      OPB_xferAck => OPB_xferAck,
      chipscope_icon_control => chipscope_icon_control,
      iba_trig_in => iba_trig_in,
      iba_trig_out => iba_trig_out
    );

end architecture STRUCTURE;

