
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

all:
		$(MAKE) -C build TYPE=nand
		$(MAKE) -C build TYPE=nor
DM6441:
		$(MAKE) -C build TYPE=nand DEVICE=DM6441
		$(MAKE) -C build TYPE=nor DEVICE=DM6441
		
DM6441_LV:
		$(MAKE) -C build TYPE=nand DEVICE=DM6441_LV
		$(MAKE) -C build TYPE=nor DEVICE=DM6441_LV
		
clean:
		$(MAKE) -C build TYPE=nand clean
		$(MAKE) -C build TYPE=nor clean
%::
		$(MAKE) -C build TYPE=nand $@
		$(MAKE) -C build TYPE=nor $@
		
