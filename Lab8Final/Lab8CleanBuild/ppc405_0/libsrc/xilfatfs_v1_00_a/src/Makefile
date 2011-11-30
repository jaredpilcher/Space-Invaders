####################################/-*-Makefile-*- 
#
# Copyright (c) 2004 Xilinx, Inc.  All rights reserved.
#
# Xilinx, Inc.
#
# XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
# COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
# ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
# STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION
# IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
# FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION.  
# XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
# THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
# ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
# FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
# AND FITNESS FOR A PARTICULAR PURPOSE.
# 
######################################################

include Makefile.config

DEBUG_OUTPUT 		= n
STANDALONE 		= n

#include all common source files
SRCS = xilfatfs_alloc.c xilfatfs_close.c xilfatfs_directory.c	\
	xilfatfs_fat.c xilfatfs_fat16.c xilfatfs_fat32.c xilfatfs_filespec.c	\
	xilfatfs_filestatus.c xilfatfs_open.c xilfatfs_part.c xilfatfs_read.c xilfatfs_wd.c \
	xilfatfs_stats.c xilfatfs_bufcache.c

CFLAGS = -Wall -O2

# parse options
ifeq ($(CONFIG_WRITE), y)
CFLAGS += -DCONFIG_WRITE
SRCS   += xilfatfs_write.c xilfatfs_remove.c
ifeq ($(CONFIG_DIR_SUPPORT), y)
CFLAGS += -DCONFIG_DIR_SUPPORT
SRCS   += xilfatfs_chdir.c xilfatfs_mkdir.c
endif
endif

ifeq ($(CONFIG_FAT12), y)
CFLAGS += -DCONFIG_FAT12
SRCS   += xilfatfs_fat12.c
endif

ifeq ($(DEBUG_OUTPUT), y)
CFLAGS += -DDEBUG
endif

ifeq ($(STANDALONE), y)
SRCS += xilfatfs_standalone-utils.c
else
SRCS += xilfatfs_sysace.c
endif

ifdef CONFIG_MAXFILES
	CFLAGS += -DMAXFILES=$(CONFIG_MAXFILES)
else
	CFLAGS += -DMAXFILES=5
endif

OBJS = ${SRCS:.c=.o}

COMPILER=
ARCHIVER=
CP=cp
EXTRA_COMPILER_FLAGS= 
LIB=libxil.a
LEVEL=0

RELEASEDIR=../../../lib/
INCLUDEDIR=../../../include/
INCLUDES=-I./include/ -I${INCLUDEDIR}

INCLUDEFILES= ./include/sysace_stdio.h
LIBSOURCES= $(SRCS:%.c=src/%.c)
OUTS = *.o 

libs:
	for i in $(LIBSOURCES); do \
	  echo "Compiling " $$i ;\
	  $(COMPILER) $(COMPILER_FLAGS) $(CFLAGS) $(EXTRA_COMPILER_FLAGS) $(INCLUDES) $$i; \
        done
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} ${OUTS} 
	echo make clean

include: dummy
	${CP} -rf ${INCLUDEFILES} ${INCLUDEDIR}

dummy:
clean:
	rm -rf ${OUTS}

