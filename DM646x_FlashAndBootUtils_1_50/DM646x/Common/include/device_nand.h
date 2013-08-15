
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
  FILE        : device_nand.h
  PROJECT     : TI Booting and Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC        : Provides device differentiation for the project files. This
                file MUST be modified to match the device specifics.
----------------------------------------------------------------------------- */

#ifndef _DEVICE_NAND_H_
#define _DEVICE_NAND_H_

#include "tistdtypes.h"

// Prevent C++ name mangling
#ifdef __cplusplus
extern far "c" {
#endif

/***********************************************************
* Global Macro Declarations                                *
***********************************************************/

#define DEVICE_NAND_DATA_OFFSET        (0x00000000u)
#define DEVICE_NAND_ALE_OFFSET         (0x00040000u)
#define DEVICE_NAND_CLE_OFFSET         (0x00080000u)
#define DEVICE_NAND_TIMEOUT            (10240)

#define DEVICE_NAND_MAX_BYTES_PER_OP       (512)   // Max Bytes per operation (EMIF IP constrained)
#define DEVICE_NAND_MAX_SPAREBYTES_PER_OP  (16)    // Max Spare Bytes per operation
#define DEVICE_NAND_MIN_SPAREBYTES_PER_OP  (4)    // Min Spare Bytes per operation (ECC operation constrained)

// Defines which NAND blocks the RBL will search in for a UBL image
#define DEVICE_NAND_RBL_SEARCH_START_BLOCK     (1)
#define DEVICE_NAND_RBL_SEARCH_END_BLOCK       (5)

// Defines which NAND blocks are valid for writing the APP data
#define DEVICE_NAND_UBL_SEARCH_START_BLOCK     (6)
#define DEVICE_NAND_UBL_SEARCH_END_BLOCK       (50)


/******************************************************
* Global Typedef declarations                         *
******************************************************/


/***********************************************************
* Global Function Declarations                             *
***********************************************************/


/***********************************************************
* End file                                                 *
***********************************************************/

#ifdef __cplusplus
}
#endif

#endif // End _DEVICE_NAND_H_

