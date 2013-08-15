
###########################################################################
#                                                                         #
#   (C) Copyright 2008                                                    #
#   Texas Instruments, Inc.  <www.ti.com>                                 # 
#                                                                         #
#   See file CREDITS for list of people who contributed to this project.  #
#                                                                         #
###########################################################################


###########################################################################
#                                                                         #
#   This file is part of the DaVinci Flash and Boot Utilities.            #
#                                                                         #
#   This program is free software: you can redistribute it and/or modify  #
#   it under the terms of the GNU General Public License as published by  #
#   the Free Software Foundation, either version 2 of the License, or     #
#   (at your option) any later version.                                   #
#                                                                         #
#   This program is distributed in the hope that it will be useful, but   #
#   WITHOUT ANY WARRANTY; without even the implied warranty of            #
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     #
#   General Public License for more details.                              #
#                                                                         #
#   You should have received a copy of the GNU General Public License     #
#   along with this program.  if not, write to the Free Software          #
#   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307   #
#   USA                                                                   #
#                                                                         #
###########################################################################

#############################################################
# Makefile for TI Serial Flash Target (SFT) project.        #
#   Generates the binary SFT file that is intended to be    #
#   executed on the device for writing the flash storage.   #
#############################################################
# Author:   Daniel Allred
#
PROGRAM:=sft

CROSSCOMPILE=arm-none-linux-gnueabi-
CC=$(CROSSCOMPILE)gcc
OBJCOPY=$(CROSSCOMPILE)objcopy
OBJDUMP=$(CROSSCOMPILE)objdump
LDFLAGS=-Wl,-T$(LINKERSCRIPT) -nostdlib 
OBJCOPYFLAGS = --gap-fill 0xFF -S
SOURCES=$(PROGRAM).c boot.c selfcopy.c uartboot.c device.c debug.c uart.c util.c
DEVSTRING=DM646x
ENTRYPOINT=boot

CFLAGS:=-c -Os -Wall -mlong-calls -ffreestanding -I../../../Common/include -I../../../../Common/include -I../../../../Common/arch/arm926ejs/include -I../../../../Common/$(PROGRAM)/include -I../../../../Common/ubl/include -I../../../../Common/drivers/include -I../../../../Common/gnu/include 
ifeq ($(TYPE),nand)
  CFLAGS+= -DUBL_NAND
  SOURCES+= nand.c device_nand.c
endif
ifeq ($(TYPE),nor)
  CFLAGS+= -DUBL_NOR
  SOURCES+= nor.c
endif
ifeq ($(TYPE),sdmmc)
	CFLAGS+= -DUBL_SDMMC
  SOURCES+= sdmmc.c
endif

OBJECTS:=$(patsubst %.c,%_$(TYPE).o,$(SOURCES))
EXECUTABLE:=$(PROGRAM)_$(DEVSTRING)_$(TYPE)
BINARY:=../$(EXECUTABLE).bin
LINKERSCRIPT=../$(PROGRAM).lds

# Target definitions
all: $(BINARY) $(OBJECTS)

.PHONY : clean objclean
clean:
		-rm -f -v $(OBJECTS) $(BINARY) $(EXECUTABLE)
		
objclean:
		-rm -f -v $(OBJECTS)
		
$(BINARY): $(EXECUTABLE)
		$(OBJCOPY) $(OBJCOPYFLAGS) -O binary $< $@
		@echo -n "The entry point of the binary is 0x"
		@$(OBJDUMP) -t $< | grep -E '[0-9a-f]{8}*[0-9a-f]{8} $(ENTRYPOINT)' | sed  's/^\([0-9a-f]\{4\}\)\([0-9a-f]\{4\}\).*/\2/'

$(EXECUTABLE): $(OBJECTS) $(LINKERSCRIPT)
		$(CC) $(LDFLAGS) $(OBJECTS) -o $@
		
%_$(TYPE).o : %.c %.h
		$(CC) $(CFLAGS) $< -o $@      
        
# Search paths for code and header files
vpath %.h :../../../Common/include:../../../../Common/include:../../../../Common/arch/arm926ejs/include:../../../../Common/$(PROGRAM)/include:../../../../Common/ubl/include:../../../../Common/gnu/include:../../../../Common/drivers/include
vpath %.c ../../../Common/src:../../../../Common/src:../../../../Common/arch/arm926ejs/src:../../../../Common/$(PROGRAM)/src:../../../../Common/ubl/src:../../../../Common/gnu/src:../../../../Common/drivers/src

