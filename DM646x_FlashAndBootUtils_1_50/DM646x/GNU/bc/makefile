
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
# Makefile for TI Boot Loader Bin Creator (BC) project.     #
#   Generates the binary image with the appropriate header  #
#   in place for flashing boot loader images (UBL, U-boot)  #
#   within the U-boot  environment.                         #
#############################################################
# Auth: Daniel Allred
#	    
PROGRAM:=bc

MONOCOMPILE=gmcs
DOTNETCOMPILE=csc
REMOTESOURCES=$(PROGRAM).cs device_name.cs Debug.cs CRC32.cs EmbeddedFileIO.cs FileIO.cs SerialIO.cs
DEVSTRING=DM646x

OBJECTS:=$(patsubst %.cs,%.module,$(REMOTESOURCES))
EXECUTABLE:=../$(PROGRAM)_$(DEVSTRING).exe
COMMONPATH:=../../../Common
ICONPATH:=$(COMMONPATH)/ti.ico
UTILLIBPATH:=$(COMMONPATH)/UtilLib

# Target definitions
all: $(EXECUTABLE) $(OBJECTS)

.PHONY : clean
clean:
		-rm -f -v $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
ifeq ($(shell uname),Linux)
		@$(MONOCOMPILE) -t:exe -define:$(DEVSTRING) -out:$(EXECUTABLE) $(OBJECTS)
else
		@$(DOTNETCOMPILE) /t:exe /define:$(DEVSTRING) /out:$(EXECUTABLE) /win32icon:$(ICONPATH) $(OBJECTS)
endif

%.module: %.cs
		@cp $< $@


vpath %.cs $(UTILLIBPATH)/:$(COMMONPATH)/bc/:../../Common/src/

