
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
  FILE        : util.h
  PURPOSE     : Misc. utility header file
  PROJECT     : DaVinci Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC        : Header for UTIL module
 ----------------------------------------------------------------------------- */ 

#ifndef _UTIL_H_
#define _UTIL_H_

#include "tistdtypes.h"

// Prevent C++ name mangling
#ifdef __cplusplus
extern far "c" {
#endif

/***********************************************************
* Global Macro Declarations                                *
***********************************************************/

#define ENDIAN_SWAP(a) (((a&0xFF)<<24)|((a&0xFF0000)>>8)|((a&0xFF00)<<8)|((a&0xFF000000)>>24))


/***********************************************************
* Global Typedef declarations                              *
***********************************************************/


/***********************************************************
* Global Function Declarations                             *
***********************************************************/

void *UTIL_allocMem (Uint32 size);
void *UTIL_callocMem(Uint32 size);
void *UTIL_getCurrMemPtr(void);
void UTIL_setCurrMemPtr(void *value);
void UTIL_waitLoop(Uint32 loopcnt);
void UTIL_waitLoopAccurate (Uint32 loopcnt);
Uint32 UTIL_calcCRC32(Uint32* lutCRC, Uint8 *data, Uint32 size, Uint32 currCRC);
void UTIL_buildCRC32Table(Uint32* lutCRC, Uint32 poly);
Uint16 UTIL_calcCRC16(Uint16* lutCRC, Uint8 *data, Uint32 size, Uint16 currCRC);
void UTIL_buildCRC16Table(Uint16* lutCRC, Uint16 poly);




/***********************************************************
* End file                                                 *
***********************************************************/

#ifdef __cplusplus
}
#endif

#endif //_UTIL_H_

/* --------------------------------------------------------------------------
  HISTORY
	  v1.00  -  DJA  -  07-Nov-2007
      Initial release 
 ----------------------------------------------------------------------------- */

