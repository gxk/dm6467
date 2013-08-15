
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
using System.IO;
using System.Reflection;
using System.Collections.Generic;
using System.Text;

namespace UtilLib.IO
{
  public class FileIO
  {
    /// <summary>
    /// Function to find and read a file's data
    /// </summary>
    /// <param name="filename">The name of the file to load</param>
    /// <returns></returns>
    public static Byte[] GetFileData(String filename)
    {
      Byte[] data;

      if (!File.Exists(filename))
      {
        throw new FileNotFoundException("File " + filename + " is not present.");
      }

      // Open file and read data
      try
      {
        data = File.ReadAllBytes(filename);
      }
      catch (Exception e)
      {
        Console.WriteLine("Error: "+e.Message);
        throw e;
      }

      return data;
    }
    
    public static String GetFileText(String filename)
    {
      String text;

      if (!File.Exists(filename))
      {
        throw new FileNotFoundException("File " + filename + " is not present.");
      }

      // Open file and read data
      try
      {
        text = File.ReadAllText(filename);
      }
      catch (Exception e)
      {
        Console.WriteLine("Error: "+e.Message);
        throw e;
      }

      return text;
    }

    public static void SetFileData(String filename, Byte[] data, Boolean overwrite)
    {
      // Open file and read data
      try
      {
        if (!File.Exists(filename))
        {
          using (FileStream fs = File.Create(filename)){}
        }
        else if (overwrite)
        {
          using (FileStream fs = File.Create(filename)){}
        }
        
        File.WriteAllBytes(filename,data);
      }
      catch (Exception e)
      {
        Console.WriteLine("Error: "+e.Message);
        throw e;
      }
    }
    
    public static void SetFileText(String filename, String data, Boolean overwrite)
    {
      // Open file and read data
      try
      {
        if (!File.Exists(filename))
        {
          using (FileStream fs = File.Create(filename)){}
        }
        else if (overwrite)
        {
          using (FileStream fs = File.Create(filename)){}
        }

        File.WriteAllText(filename,data);
      }
      catch (Exception e)
      {
        Console.WriteLine("Error: "+e.Message);
        throw e;
      }
    }
    

  }
}
