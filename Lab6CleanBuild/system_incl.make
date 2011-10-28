#################################################################
# Makefile generated by Xilinx Platform Studio 
# Project:D:\Put_Your_Temp_Files_Here\space_invaders\Lab6CleanBuild\system.xmp
#
# WARNING : This file will be re-generated every time a command
# to run a make target is invoked. So, any changes made to this  
# file manually, will be lost when make is invoked next. 
#################################################################

XILINX_EDK_DIR = C:/Xilinx91i/EDK

SYSTEM = system

MHSFILE = system.mhs

MSSFILE = system.mss

FPGA_ARCH = virtex2p

DEVICE = xc2vp30ff896-7

LANGUAGE = vhdl

SEARCHPATHOPT = 

SUBMODULE_OPT = 

PLATGEN_OPTIONS = -p $(DEVICE) -lang $(LANGUAGE) $(SEARCHPATHOPT) $(SUBMODULE_OPT)

LIBGEN_OPTIONS = -mhs $(MHSFILE) -p $(DEVICE) $(SEARCHPATHOPT)

VPGEN_OPTIONS = -p $(DEVICE) $(SEARCHPATHOPT)

TESTAPP_PERIPHERAL_OUTPUT_DIR = TestApp_Peripheral
TESTAPP_PERIPHERAL_OUTPUT = $(TESTAPP_PERIPHERAL_OUTPUT_DIR)/executable.elf

MICROBLAZE_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/microblaze/mb_bootloop.elf
PPC405_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/ppc405/ppc_bootloop.elf
PPC440_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/ppc440/ppc440_bootloop.elf
BOOTLOOP_DIR = bootloops

PPC405_0_BOOTLOOP = $(BOOTLOOP_DIR)/ppc405_0.elf

PPC405_1_BOOTLOOP = $(BOOTLOOP_DIR)/ppc405_1.elf

BRAMINIT_ELF_FILES =  $(TESTAPP_PERIPHERAL_OUTPUT) 
BRAMINIT_ELF_FILE_ARGS =   -pe ppc405_0 $(TESTAPP_PERIPHERAL_OUTPUT) 

ALL_USER_ELF_FILES = $(TESTAPP_PERIPHERAL_OUTPUT) 

SIM_CMD = vsim

BEHAVIORAL_SIM_SCRIPT = simulation/behavioral/$(SYSTEM).do

STRUCTURAL_SIM_SCRIPT = simulation/structural/$(SYSTEM).do

TIMING_SIM_SCRIPT = simulation/timing/$(SYSTEM).do

DEFAULT_SIM_SCRIPT = $(BEHAVIORAL_SIM_SCRIPT)

MIX_LANG_SIM_OPT = -mixed yes

SIMGEN_OPTIONS = -p $(DEVICE) -lang $(LANGUAGE) $(SEARCHPATHOPT) $(BRAMINIT_ELF_FILE_ARGS) $(MIX_LANG_SIM_OPT)  -s mti -X D:/Put_Your_Temp_Files_Here/space_invaders/Lab6CleanBuild/ -E D:/Put_Your_Temp_Files_Here/space_invaders/Lab6CleanBuild/


LIBRARIES =  \
       ppc405_0/lib/libxil.a  \
       ppc405_1/lib/libxil.a 
VPEXEC = virtualplatform/vpexec.exe

LIBSCLEAN_TARGETS = ppc405_0_libsclean ppc405_1_libsclean 

PROGRAMCLEAN_TARGETS = TestApp_Peripheral_programclean 

CORE_STATE_DEVELOPMENT_FILES = 

WRAPPER_NGC_FILES = implementation/ppc405_0_wrapper.ngc \
implementation/ppc405_1_wrapper.ngc \
implementation/jtagppc_0_wrapper.ngc \
implementation/reset_block_wrapper.ngc \
implementation/plb_wrapper.ngc \
implementation/opb_wrapper.ngc \
implementation/plb2opb_wrapper.ngc \
implementation/rs232_uart_1_wrapper.ngc \
implementation/sysace_compactflash_wrapper.ngc \
implementation/leds_4bit_wrapper.ngc \
implementation/dipsws_4bit_wrapper.ngc \
implementation/pushbuttons_5bit_wrapper.ngc \
implementation/ddr_256mb_32mx64_rank1_row13_col10_cl2_5_wrapper.ngc \
implementation/plb_bram_if_cntlr_1_wrapper.ngc \
implementation/plb_bram_if_cntlr_1_bram_wrapper.ngc \
implementation/opb_intc_0_wrapper.ngc \
implementation/sysclk_inv_wrapper.ngc \
implementation/clk90_inv_wrapper.ngc \
implementation/ddr_clk90_inv_wrapper.ngc \
implementation/dcm_0_wrapper.ngc \
implementation/dcm_1_wrapper.ngc \
implementation/vga_framebuffer_wrapper.ngc \
implementation/dcr_v29_0_wrapper.ngc \
implementation/opb2dcr_bridge_0_wrapper.ngc \
implementation/audio_codec_wrapper.ngc

POSTSYN_NETLIST = implementation/$(SYSTEM).ngc

SYSTEM_BIT = implementation/$(SYSTEM).bit

DOWNLOAD_BIT = implementation/download.bit

SYSTEM_ACE = implementation/$(SYSTEM).ace

UCF_FILE = data/system.ucf

BMM_FILE = implementation/$(SYSTEM).bmm

BITGEN_UT_FILE = etc/bitgen.ut

XFLOW_OPT_FILE = etc/fast_runtime.opt
XFLOW_DEPENDENCY = __xps/xpsxflow.opt $(XFLOW_OPT_FILE)

XPLORER_DEPENDENCY = __xps/xplorer.opt
XPLORER_OPTIONS = -p $(DEVICE) -uc $(SYSTEM).ucf -bm $(SYSTEM).bmm -max_runs 7

FPGA_IMP_DEPENDENCY = $(BMM_FILE) $(POSTSYN_NETLIST) $(UCF_FILE) $(BITGEN_UT_FILE) $(XFLOW_DEPENDENCY)

#################################################################
# SOFTWARE APPLICATION TESTAPP_PERIPHERAL
#################################################################

TESTAPP_PERIPHERAL_SOURCES = TestApp_Peripheral/src/xintc_tapp_example.c TestApp_Peripheral/src/xsysace_selftest_example.c TestApp_Peripheral/src/xgpio_tapp_example.c TestApp_Peripheral/src/xgpio_intr_tapp_example.c TestApp_Peripheral/src/timer.c TestApp_Peripheral/src/alienCodes.c TestApp_Peripheral/src/bullets.c TestApp_Peripheral/src/coord_objects.c TestApp_Peripheral/src/drawUtils.c TestApp_Peripheral/src/explosion.c TestApp_Peripheral/src/TestApp_Memory.c TestApp_Peripheral/src/TestApp_Peripheral.c TestApp_Peripheral/src/text.c TestApp_Peripheral/src/sound.c TestApp_Peripheral/src/wave_header.c TestApp_Peripheral/src/OPB_Int.c 

TESTAPP_PERIPHERAL_HEADERS = TestApp_Peripheral/src/intc_header.h TestApp_Peripheral/src/sysace_header.h TestApp_Peripheral/src/gpio_header.h TestApp_Peripheral/src/gpio_intr_header.h TestApp_Peripheral/src/timer.h TestApp_Peripheral/src/alienCodes.h TestApp_Peripheral/src/bullets.h TestApp_Peripheral/src/coord_objects.h TestApp_Peripheral/src/ddr_header.h TestApp_Peripheral/src/drawUtils.h TestApp_Peripheral/src/explosion.h TestApp_Peripheral/src/TestApp_Memory.h TestApp_Peripheral/src/text.h TestApp_Peripheral/src/sounds/game_sounds2.h TestApp_Peripheral/src/sound.h TestApp_Peripheral/src/wave_header.h TestApp_Peripheral/src/OPB_Int.h 

TESTAPP_PERIPHERAL_CC = powerpc-eabi-gcc
TESTAPP_PERIPHERAL_CC_SIZE = powerpc-eabi-size
TESTAPP_PERIPHERAL_CC_OPT = -O2
TESTAPP_PERIPHERAL_CFLAGS = 
TESTAPP_PERIPHERAL_CC_SEARCH = # -B
TESTAPP_PERIPHERAL_LIBPATH = -L./ppc405_0/lib/ # -L
TESTAPP_PERIPHERAL_INCLUDES = -I./ppc405_0/include/  -ITestApp_Peripheral/src/ -ITestApp_Peripheral/src/sounds/ # -I
TESTAPP_PERIPHERAL_LFLAGS = # -l
TESTAPP_PERIPHERAL_LINKER_SCRIPT = TestApp_Peripheral/src/TestApp_Peripheral_LinkScr.ld
TESTAPP_PERIPHERAL_LINKER_SCRIPT_FLAG = -Wl,-T -Wl,$(TESTAPP_PERIPHERAL_LINKER_SCRIPT) 
TESTAPP_PERIPHERAL_CC_DEBUG_FLAG =  -g 
TESTAPP_PERIPHERAL_CC_PROFILE_FLAG = # -pg
TESTAPP_PERIPHERAL_CC_GLOBPTR_FLAG= # -msdata=eabi
TESTAPP_PERIPHERAL_CC_INFERRED_FLAGS= 
TESTAPP_PERIPHERAL_CC_START_ADDR_FLAG=  #  # -Wl,-defsym -Wl,_START_ADDR=
TESTAPP_PERIPHERAL_CC_STACK_SIZE_FLAG=  #  # -Wl,-defsym -Wl,_STACK_SIZE=
TESTAPP_PERIPHERAL_CC_HEAP_SIZE_FLAG=  #  # -Wl,-defsym -Wl,_HEAP_SIZE=
TESTAPP_PERIPHERAL_OTHER_CC_FLAGS= $(TESTAPP_PERIPHERAL_CC_GLOBPTR_FLAG)  \
                  $(TESTAPP_PERIPHERAL_CC_START_ADDR_FLAG) $(TESTAPP_PERIPHERAL_CC_STACK_SIZE_FLAG) $(TESTAPP_PERIPHERAL_CC_HEAP_SIZE_FLAG)  \
                  $(TESTAPP_PERIPHERAL_CC_INFERRED_FLAGS)  \
                  $(TESTAPP_PERIPHERAL_LINKER_SCRIPT_FLAG) $(TESTAPP_PERIPHERAL_CC_DEBUG_FLAG) $(TESTAPP_PERIPHERAL_CC_PROFILE_FLAG) 
