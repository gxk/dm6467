
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
  FILE        : slt.c                                                   
  PROJECT     : TI Booting and Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC        : The main project file for the serial flasher target
 ----------------------------------------------------------------------------- */

// General type include
#include "tistdtypes.h"

// This module's header file 
#include "slt.h"

// Device specific CSL
#include "device.h"

// Misc. utility function include
#include "util.h"

// Project specific debug functionality
#include "debug.h"
#include "uart.h"

// UART boot functionality
#include "uartboot.h"


/************************************************************
* Explicit External Declarations                            *
************************************************************/


/************************************************************
* Local Macro Declarations                                  *
************************************************************/


/************************************************************
* Local Typedef Declarations                                *
************************************************************/


/************************************************************
* Local Function Declarations                               *
************************************************************/

static Uint32 LOCAL_boot(void);
static void (*APPEntry)(void);


/************************************************************
* Local Variable Definitions                                *
************************************************************/


/************************************************************
* Global Variable Definitions                               *
************************************************************/

Uint32 gEntryPoint;


/************************************************************
* Global Function Definitions                               *
************************************************************/

void main(void)
{
  
  // Call to real boot function code
  LOCAL_boot();
    
  // Jump to entry point
  APPEntry = (void (*)(void)) gEntryPoint;
  (*APPEntry)();  
}


/************************************************************
* Local Function Definitions                                *
************************************************************/

static Uint32 LOCAL_boot(void)
{
  DEVICE_BootMode bootMode;
  
  // Read boot mode 
  bootMode = DEVICE_bootMode();
    
  if (bootMode == DEVICE_BOOTMODE_UART)
  {
    // Wait until the RBL is done using the UART. 
    while((UART0->LSR & 0x40) == 0 );
  }

  // Platform Initialization
  if ( DEVICE_init() != E_PASS )
  {
    DEBUG_printString(devString);
    DEBUG_printString(" initialization failed!\r\n");
    asm(" MOV PC, #0");
  }
  else
  {
    DEBUG_printString(devString);
    DEBUG_printString(" initialization passed!\r\n");
  }

  // Set RAM pointer to beginning of RAM space
  UTIL_setCurrMemPtr(0);

  // Send some information to host
  DEBUG_printString("TI SLT Version: ");
  DEBUG_printString(SLT_VERSION_STRING);
  DEBUG_printString("\r\nBooting Catalog Serial Loader\r\n");
  
  UARTBOOT_copy();
    
  DEBUG_printString("   DONE");
  
  UTIL_waitLoop(10000);

  DEVICE_TIMER0Stop();

  return E_PASS;    
}


