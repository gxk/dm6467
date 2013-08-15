
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
  FILE        : spi.h
  PROJECT     : DaVinci User Boot-Loader and Flasher
  AUTHOR      : Texas Instruments Incorporated
  DESC        : Generic SPI driver header file
 ----------------------------------------------------------------------------- */
 
#ifndef _SPI_H_
#define _SPI_H_

#include "tistdtypes.h"

// Prevent C++ name mangling
#ifdef __cplusplus
extern far "c" {
#endif

/************************************************************
* Global Macro Declarations                                 *
************************************************************/

#define SPI_RXINTFLAG     (0x00000100u)
#define SPI_OVRNINTFLG    (0x00000040u)
#define SPI_BITERRFLG     (0x00000010u)
#define SPI_DESELECTFLG   (0x00000004u)            // SPI_PARERRFLG


/***********************************************************
* Global Typedef declarations                              *
***********************************************************/

// SPI Module Roles
typedef enum _SPI_ROLE_
{
  SPI_ROLE_MASTER = 0x01,
  SPI_ROLE_SLAVE = 0x02
}
SPI_Role;

// SPI Module Modes of Operation
typedef enum _SPI_MODE_
{
  SPI_MODE_3PIN       = 0x01,
  SPI_MODE_4PIN_CS    = 0x02,
  SPI_MODE_4PIN_ENA   = 0x04,
  SPI_MODE_5PIN       = 0x08
}
SPI_Mode;

typedef struct _SPI_CONFIG_
{
  Uint8 polarity;
  Uint8 phase;
  Uint8 prescalar;
  Uint8 charLen;
}
SPI_Config;

// SPI driver structure
typedef struct _SPI_INFO_
{
  Uint32      peripheralNum;
  void        *regs;
  SPI_Role    role;
  SPI_Mode    mode;
  SPI_Config  *config;
}
SPI_InfoObj, *SPI_InfoHandle;


/************************************************************
* Global Function Declarations                              *
************************************************************/

extern SPI_InfoHandle SPI_open(Uint32 spiPeripheralNum, SPI_Role role, SPI_Mode mode, SPI_Config *config);
extern Uint32 SPI_reset(SPI_InfoHandle hSPIInfo);
extern Uint32 SPI_readBytes(SPI_InfoHandle hSPIInfo, Uint32 byteCnt, Uint8 *dest);
extern Uint32 SPI_writeBytes(SPI_InfoHandle hSPIInfo, Uint32 byteCnt, Uint8 *src);
extern Uint32 SPI_xferOneChar(SPI_InfoHandle hSPIInfo, Uint32 dataOut);
extern void SPI_enableCS(SPI_InfoHandle hSPIInfo);
extern void SPI_disableCS(SPI_InfoHandle hSPIInfo);


/***********************************************************
* End file                                                 *
***********************************************************/

#ifdef __cplusplus
}
#endif

#endif //_SPI_H_

