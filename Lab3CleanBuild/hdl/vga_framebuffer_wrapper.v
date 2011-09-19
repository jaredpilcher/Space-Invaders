//-----------------------------------------------------------------------------
// vga_framebuffer_wrapper.v
//-----------------------------------------------------------------------------

module vga_framebuffer_wrapper
  (
    SYS_plbClk,
    SYS_plbReset,
    Mn_request,
    Mn_ABus,
    Mn_RNW,
    Mn_BE,
    Mn_size,
    Mn_type,
    Mn_priority,
    Mn_rdBurst,
    Mn_wrBurst,
    Mn_busLock,
    Mn_abort,
    Mn_lockErr,
    Mn_msize,
    Mn_ordered,
    Mn_compress,
    Mn_guarded,
    Mn_wrDBus,
    PLB_MnRdWdAddr,
    PLB_MnRdDBus,
    PLB_MnAddrAck,
    PLB_MnRdDAck,
    PLB_MnWrDAck,
    PLB_MnRearbitrate,
    PLB_MnBusy,
    PLB_MnErr,
    PLB_MnRdBTerm,
    PLB_MnWrBTerm,
    PLB_Mnssize,
    PLB_pendReq,
    PLB_pendPri,
    PLB_reqPri,
    SYS_dcrClk,
    DCR_Ack,
    DCR_DBusOut,
    DCR_ABus,
    DCR_DBusIn,
    DCR_Read,
    DCR_Write,
    SYS_tftClk,
    TFT_LCD_HSYNC,
    TFT_LCD_VSYNC,
    TFT_LCD_DE,
    TFT_LCD_CLK,
    TFT_LCD_DPS,
    TFT_LCD_R,
    TFT_LCD_G,
    TFT_LCD_B,
    TFT_LCD_BLNK
  );
  input SYS_plbClk;
  input SYS_plbReset;
  output Mn_request;
  output [0:31] Mn_ABus;
  output Mn_RNW;
  output [0:7] Mn_BE;
  output [0:3] Mn_size;
  output [0:2] Mn_type;
  output [0:1] Mn_priority;
  output Mn_rdBurst;
  output Mn_wrBurst;
  output Mn_busLock;
  output Mn_abort;
  output Mn_lockErr;
  output [0:1] Mn_msize;
  output Mn_ordered;
  output Mn_compress;
  output Mn_guarded;
  output [0:63] Mn_wrDBus;
  input [0:3] PLB_MnRdWdAddr;
  input [0:63] PLB_MnRdDBus;
  input PLB_MnAddrAck;
  input PLB_MnRdDAck;
  input PLB_MnWrDAck;
  input PLB_MnRearbitrate;
  input PLB_MnBusy;
  input PLB_MnErr;
  input PLB_MnRdBTerm;
  input PLB_MnWrBTerm;
  input [0:1] PLB_Mnssize;
  input PLB_pendReq;
  input [0:1] PLB_pendPri;
  input [0:1] PLB_reqPri;
  input SYS_dcrClk;
  output DCR_Ack;
  output [0:31] DCR_DBusOut;
  input [0:9] DCR_ABus;
  input [0:31] DCR_DBusIn;
  input DCR_Read;
  input DCR_Write;
  input SYS_tftClk;
  output TFT_LCD_HSYNC;
  output TFT_LCD_VSYNC;
  output TFT_LCD_DE;
  output TFT_LCD_CLK;
  output TFT_LCD_DPS;
  output [5:0] TFT_LCD_R;
  output [5:0] TFT_LCD_G;
  output [5:0] TFT_LCD_B;
  output TFT_LCD_BLNK;

  defparam vga_framebuffer.C_DCR_BASEADDR = 'b1000000000;
  defparam vga_framebuffer.C_DCR_HIGHADDR = 'b1000000001;
  defparam vga_framebuffer.C_DEFAULT_TFT_BASE_ADDR = 'b00000000000;
  defparam vga_framebuffer.C_DPS_INIT = 'b1;
  defparam vga_framebuffer.C_ON_INIT = 'b1;
  defparam vga_framebuffer.C_PIXCLK_IS_BUSCLK_DIVBY4 = 'b1;
  plb_tft_cntlr_ref
    vga_framebuffer (
      .SYS_plbClk ( SYS_plbClk ),
      .SYS_plbReset ( SYS_plbReset ),
      .Mn_request ( Mn_request ),
      .Mn_ABus ( Mn_ABus ),
      .Mn_RNW ( Mn_RNW ),
      .Mn_BE ( Mn_BE ),
      .Mn_size ( Mn_size ),
      .Mn_type ( Mn_type ),
      .Mn_priority ( Mn_priority ),
      .Mn_rdBurst ( Mn_rdBurst ),
      .Mn_wrBurst ( Mn_wrBurst ),
      .Mn_busLock ( Mn_busLock ),
      .Mn_abort ( Mn_abort ),
      .Mn_lockErr ( Mn_lockErr ),
      .Mn_msize ( Mn_msize ),
      .Mn_ordered ( Mn_ordered ),
      .Mn_compress ( Mn_compress ),
      .Mn_guarded ( Mn_guarded ),
      .Mn_wrDBus ( Mn_wrDBus ),
      .PLB_MnRdWdAddr ( PLB_MnRdWdAddr ),
      .PLB_MnRdDBus ( PLB_MnRdDBus ),
      .PLB_MnAddrAck ( PLB_MnAddrAck ),
      .PLB_MnRdDAck ( PLB_MnRdDAck ),
      .PLB_MnWrDAck ( PLB_MnWrDAck ),
      .PLB_MnRearbitrate ( PLB_MnRearbitrate ),
      .PLB_MnBusy ( PLB_MnBusy ),
      .PLB_MnErr ( PLB_MnErr ),
      .PLB_MnRdBTerm ( PLB_MnRdBTerm ),
      .PLB_MnWrBTerm ( PLB_MnWrBTerm ),
      .PLB_Mnssize ( PLB_Mnssize ),
      .PLB_pendReq ( PLB_pendReq ),
      .PLB_pendPri ( PLB_pendPri ),
      .PLB_reqPri ( PLB_reqPri ),
      .SYS_dcrClk ( SYS_dcrClk ),
      .DCR_Ack ( DCR_Ack ),
      .DCR_DBusOut ( DCR_DBusOut ),
      .DCR_ABus ( DCR_ABus ),
      .DCR_DBusIn ( DCR_DBusIn ),
      .DCR_Read ( DCR_Read ),
      .DCR_Write ( DCR_Write ),
      .SYS_tftClk ( SYS_tftClk ),
      .TFT_LCD_HSYNC ( TFT_LCD_HSYNC ),
      .TFT_LCD_VSYNC ( TFT_LCD_VSYNC ),
      .TFT_LCD_DE ( TFT_LCD_DE ),
      .TFT_LCD_CLK ( TFT_LCD_CLK ),
      .TFT_LCD_DPS ( TFT_LCD_DPS ),
      .TFT_LCD_R ( TFT_LCD_R ),
      .TFT_LCD_G ( TFT_LCD_G ),
      .TFT_LCD_B ( TFT_LCD_B ),
      .TFT_LCD_BLNK ( TFT_LCD_BLNK )
    );

endmodule

// synthesis attribute x_core_info of plb_tft_cntlr_ref is plb_tft_cntlr_ref_v1_00_d;

