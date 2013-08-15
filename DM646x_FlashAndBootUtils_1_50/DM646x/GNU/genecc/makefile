
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
# Makefile for ECC Generation (genecc) project.             #
#############################################################
# Auth: Daniel Allred
#	    
PROGRAM:=genecc
DEVSTRING:=DM646x

MONOCOMPILE=gmcs
DOTNETCOMPILE=csc
REMOTESOURCES=$(PROGRAM)_hamming.cs device_name.cs Debug.cs ECC.cs FileIO.cs
ICON=ti.ico

OBJECTS:=$(patsubst %.cs,%.module,$(REMOTESOURCES))
EXECUTABLE:=../$(PROGRAM)_$(DEVSTRING).exe
LOCAL_ICON:=ti.icon
COMMONPATH:=../../../Common
UTILLIBPATH:=$(COMMONPATH)/UtilLib
DEVCOMMONPATH:=../../Common
GNUCOMMONPATH:=../Common

# Target definitions
all: $(EXECUTABLE) $(OBJECTS)

.PHONY : clean
clean:
		-rm -f -v $(EXECUTABLE) $(OBJECTS) $(LOCAL_ICON)

$(EXECUTABLE): $(OBJECTS) $(LOCAL_ICON)
ifeq ($(shell uname),Linux)
		@$(MONOCOMPILE) -t:exe -define:$(DEVSTRING) -out:$(EXECUTABLE) $(OBJECTS)
else
		@$(DOTNETCOMPILE) /t:exe /define:$(DEVSTRING) /out:$(EXECUTABLE) /win32icon:$(LOCAL_ICON) $(OBJECTS)
endif

%.module: %.cs
		@cp $< $@

%.icon: %.ico
		@cp $< $@

vpath %.cs ./::$(COMMONPATH)/genecc/:$(UTILLIBPATH)/:$(GNUCOMMONPATH)/:$(DEVCOMMONPATH)/src/
vpath %.ico ./::$(COMMONPATH)


