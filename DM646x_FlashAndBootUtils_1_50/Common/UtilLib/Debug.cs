
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

using System;
using System.Text;

namespace UtilLib
{
    public class Debug
    {
        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(String value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }
        
        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(Boolean value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(Char value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="buffer">A unicode character array.</param>
        public static void DebugMSG(char[] buffer)
        {
#if DEBUG
            Console.WriteLine(buffer);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(int value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(double value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(float value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(decimal value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(short value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(long value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(object value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(uint value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }       

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(ulong value)
        {
#if DEBUG
            Console.WriteLine(value);
#endif
        }

        /// <summary>
        /// Writes the text representation of the specified array of objects, followed by the line terminator, to the standard
        /// output, but only if the current build is a DEBUG build.  
        /// </summary>
        /// <param name="value">The value to write.</param>
        public static void DebugMSG(String format, params Object[] arg)
        {
#if DEBUG
            Console.WriteLine(format, arg);
#endif
        }

    }
}
