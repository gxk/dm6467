
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
  public class EmbeddedFileIO
  {
    private static List<String> resources = new List<String>(10);
    private static List<String> files = new List<String>(10);

    public static void ExtractFile(Assembly thisAssm, String fileName, Boolean overWrite)
    {
      Stream dataStream;
      Stream myStream = null;
      String myResourceName = "";

      foreach (String s in thisAssm.GetManifestResourceNames())
      {
        if (s.Contains(fileName))
        {
            myResourceName = s;
            break;
        }
      }
      if (myResourceName.Equals(""))
        myStream = null;

      try
      {
        myStream = thisAssm.GetManifestResourceStream(myResourceName);
      }
      catch (Exception e)
      {
        if (e is FileNotFoundException)
          myStream = null;
        else
          throw e;
      }
      dataStream = myStream;

      if ((File.Exists(fileName)) && overWrite)
      {
        // If the file is already there and we are supposed to overwrite,
        // but there is no embedded version, do nothing
        if (dataStream == null)
        {
          return;
        }
        // If the file is already there and we are supposed to overwrite,
        // but we already extracted it from here, do nothing
        else if (resources.Contains(myResourceName))
          return;
      }
      else if (!File.Exists(fileName))
      {
        if (dataStream == null)
          throw new FileNotFoundException("File " + fileName + " was not found in the assembly or in the current directory.");
      }
      else
      {
        return;
      }

      FileStream newFile = File.Open(fileName, FileMode.Create, FileAccess.Write);
      Byte[] buffer = new Byte[dataStream.Length];
      dataStream.Seek(0, SeekOrigin.Begin);
      dataStream.Read(buffer, 0, (int)dataStream.Length);
      newFile.Write(buffer, 0, (int)buffer.Length);
      newFile.Close();
      files.Add(fileName);
      resources.Add(myResourceName);
    }

    public static void CleanUpEmbeddedFiles()
    {
      foreach (String s in files)
      {
        File.Delete(s);
      }
      files.Clear();
    }

    private static Stream GetEmbeddedStream(Assembly thisAssm, String fileName)
    {
      Stream myStream = null;
      String myResourceName = "";

      foreach (String s in thisAssm.GetManifestResourceNames())
      {
        Console.WriteLine(s);
        if (s.Contains(fileName))
        {
          myResourceName = s;
          break;
        }
      }
      if (myResourceName.Equals(""))
        return null;

      try
      {
        myStream = thisAssm.GetManifestResourceStream(myResourceName);
      }
      catch (Exception e)
      {
        if (e is FileNotFoundException)
          return null;
        else
          throw e;
      }

      return myStream;
    }        
  }
}
