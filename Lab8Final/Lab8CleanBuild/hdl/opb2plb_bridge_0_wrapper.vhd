-------------------------------------------------------------------------------
-- opb2plb_bridge_0_wrapper.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

library opb2plb_bridge_v1_00_c;
use opb2plb_bridge_v1_00_c.All;

entity opb2plb_bridge_0_wrapper is
  port (
    OPB_Clk : in std_logic;
    PLB_Clk : in std_logic;
    OPB_Rst : in std_logic;
    PLB_Rst : in std_logic;
    BGI_Trans_Abort : in std_logic;
    Bus_Error_Det : out std_logic;
    OPB_select : in std_logic;
    OPB_ABus : in std_logic_vector(0 to 31);
    OPB_RNW : in std_logic;
    OPB_BE : in std_logic_vector(0 to 3);
    OPB_DBus : in std_logic_vector(0 to 31);
    OPB_seqAddr : in std_logic;
    BGI_DBus : out std_logic_vector(0 to 31);
    BGI_retry : out std_logic;
    BGI_toutSup : out std_logic;
    BGI_xferAck : out std_logic;
    BGI_errAck : out std_logic;
    BGI_request : out std_logic;
    BGI_ABus : out std_logic_vector(0 to 31);
    BGI_RNW : out std_logic;
    BGI_BE : out std_logic_vector(0 to 7);
    BGI_size : out std_logic_vector(0 to 3);
    BGI_type : out std_logic_vector(0 to 2);
    BGI_priority : out std_logic_vector(0 to 1);
    BGI_rdBurst : out std_logic;
    BGI_wrBurst : out std_logic;
    BGI_busLock : out std_logic;
    BGI_abort : out std_logic;
    BGI_lockErr : out std_logic;
    BGI_mSize : out std_logic_vector(0 to 1);
    BGI_ordered : out std_logic;
    BGI_compress : out std_logic;
    BGI_guarded : out std_logic;
    BGI_wrDBus : out std_logic_vector(0 to 63);
    PLB_RdWdAddr : in std_logic_vector(0 to 3);
    PLB_RdDBus : in std_logic_vector(0 to 63);
    PLB_AddrAck : in std_logic;
    PLB_RdDAck : in std_logic;
    PLB_WrDAck : in std_logic;
    PLB_rearbitrate : in std_logic;
    PLB_Busy : in std_logic;
    PLB_Err : in std_logic;
    PLB_RdBTerm : in std_logic;
    PLB_WrBTerm : in std_logic;
    PLB_sSize : in std_logic_vector(0 to 1);
    PLB_pendReq : in std_logic;
    PLB_pendPri : in std_logic_vector(0 to 1);
    PLB_reqPri : in std_logic_vector(0 to 1);
    DCR_Read : in std_logic;
    DCR_Write : in std_logic;
    DCR_ABus : in std_logic_vector(0 to 9);
    DCR_DBus : in std_logic_vector(0 to 31);
    BGI_dcr_DBus : out std_logic_vector(0 to 31);
    BGI_ack : out std_logic
  );
end opb2plb_bridge_0_wrapper;

architecture STRUCTURE of opb2plb_bridge_0_wrapper is

  component opb2plb_bridge is
    generic (
      C_SAME_CLKS : integer;
      C_RD_PREFETCH_CNT : integer;
      C_WR_CACHELINE_SIZE : integer;
      C_OPB_REG_INTFC : integer;
      C_ABORT_DLY_CNT : integer;
      C_OPB_AWIDTH : integer;
      C_PLB_AWIDTH : integer;
      C_FAMILY : string;
      C_NUM_ADDR_RNG : integer;
      C_RNG0_BASEADDR : std_logic_vector;
      C_RNG0_HIGHADDR : std_logic_vector;
      C_RNG1_BASEADDR : std_logic_vector;
      C_RNG1_HIGHADDR : std_logic_vector;
      C_RNG2_BASEADDR : std_logic_vector;
      C_RNG2_HIGHADDR : std_logic_vector;
      C_RNG3_BASEADDR : std_logic_vector;
      C_RNG3_HIGHADDR : std_logic_vector;
      C_RNG0_PREFETCH : integer;
      C_RNG1_PREFETCH : integer;
      C_RNG2_PREFETCH : integer;
      C_RNG3_PREFETCH : integer;
      C_RNG0_BURST : integer;
      C_RNG1_BURST : integer;
      C_RNG2_BURST : integer;
      C_RNG3_BURST : integer;
      C_RNG0_LINE : integer;
      C_RNG1_LINE : integer;
      C_RNG2_LINE : integer;
      C_RNG3_LINE : integer;
      C_OPB_BASEADDR : std_logic_vector;
      C_OPB_HIGHADDR : std_logic_vector;
      C_OPB_DWIDTH : integer;
      C_PLB_DWIDTH : integer;
      C_PLB_PRIORITY : integer;
      C_DCR_BASEADDR : std_logic_vector;
      C_DCR_HIGHADDR : std_logic_vector;
      C_DCR_AWIDTH : integer;
      C_DCR_DWIDTH : integer;
      C_IRQ_ACTIVE : std_logic;
      C_SWR_COUNT : integer
    );
    port (
      OPB_Clk : in std_logic;
      PLB_Clk : in std_logic;
      OPB_Rst : in std_logic;
      PLB_Rst : in std_logic;
      BGI_Trans_Abort : in std_logic;
      Bus_Error_Det : out std_logic;
      OPB_select : in std_logic;
      OPB_ABus : in std_logic_vector(0 to C_OPB_AWIDTH-1);
      OPB_RNW : in std_logic;
      OPB_BE : in std_logic_vector(0 to C_OPB_DWIDTH/8-1);
      OPB_DBus : in std_logic_vector(0 to C_OPB_DWIDTH-1);
      OPB_seqAddr : in std_logic;
      BGI_DBus : out std_logic_vector(0 to C_OPB_DWIDTH-1);
      BGI_retry : out std_logic;
      BGI_toutSup : out std_logic;
      BGI_xferAck : out std_logic;
      BGI_errAck : out std_logic;
      BGI_request : out std_logic;
      BGI_ABus : out std_logic_vector(0 to C_PLB_AWIDTH-1);
      BGI_RNW : out std_logic;
      BGI_BE : out std_logic_vector(0 to C_PLB_DWIDTH/8-1);
      BGI_size : out std_logic_vector(0 to 3);
      BGI_type : out std_logic_vector(0 to 2);
      BGI_priority : out std_logic_vector(0 to 1);
      BGI_rdBurst : out std_logic;
      BGI_wrBurst : out std_logic;
      BGI_busLock : out std_logic;
      BGI_abort : out std_logic;
      BGI_lockErr : out std_logic;
      BGI_mSize : out std_logic_vector(0 to 1);
      BGI_ordered : out std_logic;
      BGI_compress : out std_logic;
      BGI_guarded : out std_logic;
      BGI_wrDBus : out std_logic_vector(0 to C_PLB_DWIDTH-1);
      PLB_RdWdAddr : in std_logic_vector(0 to 3);
      PLB_RdDBus : in std_logic_vector(0 to C_PLB_DWIDTH-1);
      PLB_AddrAck : in std_logic;
      PLB_RdDAck : in std_logic;
      PLB_WrDAck : in std_logic;
      PLB_rearbitrate : in std_logic;
      PLB_Busy : in std_logic;
      PLB_Err : in std_logic;
      PLB_RdBTerm : in std_logic;
      PLB_WrBTerm : in std_logic;
      PLB_sSize : in std_logic_vector(0 to 1);
      PLB_pendReq : in std_logic;
      PLB_pendPri : in std_logic_vector(0 to 1);
      PLB_reqPri : in std_logic_vector(0 to 1);
      DCR_Read : in std_logic;
      DCR_Write : in std_logic;
      DCR_ABus : in std_logic_vector(0 to C_DCR_AWIDTH-1);
      DCR_DBus : in std_logic_vector(0 to C_DCR_DWIDTH-1);
      BGI_dcr_DBus : out std_logic_vector(0 to C_DCR_DWIDTH-1);
      BGI_ack : out std_logic
    );
  end component;

  attribute x_core_info : STRING;
  attribute x_core_info of opb2plb_bridge : component is "opb2plb_bridge_v1_00_c";

begin

  opb2plb_bridge_0 : opb2plb_bridge
    generic map (
      C_SAME_CLKS => 0,
      C_RD_PREFETCH_CNT => 8,
      C_WR_CACHELINE_SIZE => 8,
      C_OPB_REG_INTFC => 0,
      C_ABORT_DLY_CNT => 10,
      C_OPB_AWIDTH => 32,
      C_PLB_AWIDTH => 32,
      C_FAMILY => "virtex2p",
      C_NUM_ADDR_RNG => 1,
      C_RNG0_BASEADDR => X"00000000",
      C_RNG0_HIGHADDR => X"0FFFFFFF",
      C_RNG1_BASEADDR => X"FFFFFFFF",
      C_RNG1_HIGHADDR => X"00000000",
      C_RNG2_BASEADDR => X"FFFFFFFF",
      C_RNG2_HIGHADDR => X"00000000",
      C_RNG3_BASEADDR => X"FFFFFFFF",
      C_RNG3_HIGHADDR => X"00000000",
      C_RNG0_PREFETCH => 0,
      C_RNG1_PREFETCH => 0,
      C_RNG2_PREFETCH => 0,
      C_RNG3_PREFETCH => 0,
      C_RNG0_BURST => 0,
      C_RNG1_BURST => 0,
      C_RNG2_BURST => 0,
      C_RNG3_BURST => 0,
      C_RNG0_LINE => 0,
      C_RNG1_LINE => 0,
      C_RNG2_LINE => 0,
      C_RNG3_LINE => 0,
      C_OPB_BASEADDR => X"FFFFFFFF",
      C_OPB_HIGHADDR => X"00000000",
      C_OPB_DWIDTH => 32,
      C_PLB_DWIDTH => 64,
      C_PLB_PRIORITY => 0,
      C_DCR_BASEADDR => B"1111111111",
      C_DCR_HIGHADDR => B"0000000000",
      C_DCR_AWIDTH => 10,
      C_DCR_DWIDTH => 32,
      C_IRQ_ACTIVE => '1',
      C_SWR_COUNT => 2
    )
    port map (
      OPB_Clk => OPB_Clk,
      PLB_Clk => PLB_Clk,
      OPB_Rst => OPB_Rst,
      PLB_Rst => PLB_Rst,
      BGI_Trans_Abort => BGI_Trans_Abort,
      Bus_Error_Det => Bus_Error_Det,
      OPB_select => OPB_select,
      OPB_ABus => OPB_ABus,
      OPB_RNW => OPB_RNW,
      OPB_BE => OPB_BE,
      OPB_DBus => OPB_DBus,
      OPB_seqAddr => OPB_seqAddr,
      BGI_DBus => BGI_DBus,
      BGI_retry => BGI_retry,
      BGI_toutSup => BGI_toutSup,
      BGI_xferAck => BGI_xferAck,
      BGI_errAck => BGI_errAck,
      BGI_request => BGI_request,
      BGI_ABus => BGI_ABus,
      BGI_RNW => BGI_RNW,
      BGI_BE => BGI_BE,
      BGI_size => BGI_size,
      BGI_type => BGI_type,
      BGI_priority => BGI_priority,
      BGI_rdBurst => BGI_rdBurst,
      BGI_wrBurst => BGI_wrBurst,
      BGI_busLock => BGI_busLock,
      BGI_abort => BGI_abort,
      BGI_lockErr => BGI_lockErr,
      BGI_mSize => BGI_mSize,
      BGI_ordered => BGI_ordered,
      BGI_compress => BGI_compress,
      BGI_guarded => BGI_guarded,
      BGI_wrDBus => BGI_wrDBus,
      PLB_RdWdAddr => PLB_RdWdAddr,
      PLB_RdDBus => PLB_RdDBus,
      PLB_AddrAck => PLB_AddrAck,
      PLB_RdDAck => PLB_RdDAck,
      PLB_WrDAck => PLB_WrDAck,
      PLB_rearbitrate => PLB_rearbitrate,
      PLB_Busy => PLB_Busy,
      PLB_Err => PLB_Err,
      PLB_RdBTerm => PLB_RdBTerm,
      PLB_WrBTerm => PLB_WrBTerm,
      PLB_sSize => PLB_sSize,
      PLB_pendReq => PLB_pendReq,
      PLB_pendPri => PLB_pendPri,
      PLB_reqPri => PLB_reqPri,
      DCR_Read => DCR_Read,
      DCR_Write => DCR_Write,
      DCR_ABus => DCR_ABus,
      DCR_DBus => DCR_DBus,
      BGI_dcr_DBus => BGI_dcr_DBus,
      BGI_ack => BGI_ack
    );

end architecture STRUCTURE;

