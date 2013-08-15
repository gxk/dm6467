
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
  FILE        : selfcopy.c                                                   
  PROJECT     : TI Booting and Flashing Utilities
  AUTHOR      : Daniel Allred
  DESC        : The XiP self-copy code for the user boot loader
 ----------------------------------------------------------------------------- */

// General type include
#include "tistdtypes.h"

// The header for the boot entry point
#include "boot.h"

// This module's header file 
#include "selfcopy.h"

/************************************************************
* Explicit External Declarations                            *
************************************************************/

extern __FAR__ Uint32 __selfcopysrc, __selfcopysrcend, __selfcopydest;


/************************************************************
* Local Macro Declarations                                  *
************************************************************/


/************************************************************
* Local Typedef Declarations                                *
************************************************************/


/************************************************************
* Local Function Declarations                               *
************************************************************/


/************************************************************
* Local Variable Definitions                                *
************************************************************/


/************************************************************
* Global Variable Definitions                               *
************************************************************/


/************************************************************
* Global Function Definitions                               *
************************************************************/

#if defined(__TMS470__)
  #pragma FUNC_EXT_CALLED(selfcopy);
  #pragma CODE_SECTION(selfcopy,".selfcopy");
  #pragma TASK(selfcopy);
#endif
void selfcopy(void)
{
  asm(" .global DRAMStart");
  asm(" .global __selfcopysrc");
  asm(" .global __selfcopydest");
  asm(" .global __selfcopysrcend");
  asm(" .global _dramstart"); 
  asm(" .global _selfcopysrc"); 
  asm(" .global _selfcopydest"); 
  asm(" .global _selfcopysrcend"); 
  asm(" .global boot");  

  //Enable ITCM
  asm(" MRC p15,#0,r0,c9,c1,#1");
  asm(" MOV r0, #0x1");
  asm(" MCR p15,#0,r0,c9,c1,#1");
    
  //Enable DTCM
  asm(" MRC p15,#0,r0,c9,c1,#0");
  asm(" LDR r0,_dramstart");
  asm(" ORR r0,r0,#0x1D");
  asm(" MCR p15,#0,r0,c9,c1,#0");

  // Init copy variables
  asm(" LDR r0,_selfcopysrc");
  asm(" LDR r1,_selfcopydest");
  asm(" LDR r2,_selfcopysrcend");

  // Copy loop
  asm(" CMP  r2, r0");
  asm(" BLS  endcopyloop");
  asm(" SUB  r2, r2, r0");
  asm(" MOV  r2, r2, ASR #2");
  asm("copyloop:");
  asm(" LDR  r12, [R0], #0x4");
  asm(" SUBS r2, r2, #0x1");
  asm(" STR  r12, [r1], #0x4");
  asm(" BNE copyloop");
  asm("endcopyloop:");
  
  // Long jump to the normal entry point 
  asm(" LDR r0,_bootaddr");
  asm(" MOV pc,r0");

  asm("_dramstart: ");
  asm(" .word DRAMStart");
  asm("_bootaddr: ");
  asm(" .word boot");
  asm("_selfcopysrc: ");
  asm(" .word __selfcopysrc");
  asm("_selfcopydest: ");
  asm(" .word __selfcopydest");
  asm("_selfcopysrcend: ");
  asm(" .word __selfcopysrcend");
}

/************************************************************
* Local Function Definitions                                *
************************************************************/


/************************************************************
* End file                                                  *
************************************************************/

