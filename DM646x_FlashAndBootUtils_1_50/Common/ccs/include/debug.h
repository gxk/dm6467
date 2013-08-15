
/**************************************************************************
*                                                                         *
*   (C) Copyright 2008                                                    *
*   Texas Instruments, Inc.  <www.ti.com>                                 * 
*                                                                         *
*   See file CREDITS for list of people who contributed to this project.  *
*                                                                         *
**************************************************************************/


/**************************************************************************
*                                                                         *
*   This file is part of the DaVinci Flash and Boot Utilities.            *
*                                                                         *
*   This program is free software: you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation, either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful, but   *
*   WITHOUT ANY WARRANTY; without even the implied warranty of            *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
*   General Public License for more details.                              *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program.  if not, write to the Free Software          *
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307   *
*   USA                                                                   *
*                                                                         *
**************************************************************************/

/* --------------------------------------------------------------------------
  FILE        : debug.h
  PROJECT     : TI Booting and Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC	      : Header for the debug routines  
 ----------------------------------------------------------------------------- */ 

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include "tistdtypes.h"

// Prevent C++ name mangling
#ifdef __cplusplus
extern far "c" {
#endif

/***********************************************************
* Global Macro Declarations                                *
***********************************************************/

/***********************************************************
* Global Typedef declarations                              *
***********************************************************/

/***********************************************************
* Global Function Declarations                             *
***********************************************************/

Uint32 DEBUG_printString(String s);
Uint32 DEBUG_printHexInt(Uint32 i);
Uint32 DEBUG_readString(String s);
Uint32 DEBUG_readChar(Char *c);
Uint32 DEBUG_readHexInt(Uint32 *i);


/***********************************************************
* End file                                                 *
***********************************************************/

#ifdef __cplusplus
}
#endif

#endif //_DEBUG_H_

/* --------------------------------------------------------------------------
    HISTORY
		v1.00  -  DJA  -  07-Nov-2007
 	        Initial release 
 ----------------------------------------------------------------------------- */
