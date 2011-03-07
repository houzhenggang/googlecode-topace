﻿using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace FONT3D
{
    public class Font3D
    {
        struct VT3
        {
            public float x, y, z;
        }

        struct CHAR3D
        {
            public int code;
            public string value;
            public VT3[] verts;
        }

        private byte[] Head;
        private const int Verson = 1;

        //private int filesize;
        private int pageCode; //1200 unicode
        private int charscount;
        public int CharCount
        {
            get { return charscount; }
        }

        public int GetCharNum()
        {
            return charscount;
        }

        public string GetChar(int i)
        {
            return chs[i].value;
        }

        public void SetCharVert(int idx,float[] xyz)
        {
            chs[idx].verts = new VT3[xyz.Length / 3];
            for (int i = 0; i < xyz.Length / 3; i++)
            {
                chs[idx].verts[i].x = xyz[i * 3 + 0];
                chs[idx].verts[i].y = xyz[i * 3 + 1];
                chs[idx].verts[i].z = xyz[i * 3 + 2];
            }
        }

        public void savefile(string fname)
        {
            MemoryStream ms = new MemoryStream();
            BinaryWriter w = new BinaryWriter(ms);
            w.Write(Head);
            w.Write(Verson);
            w.Write(0);

            w.Write(pageCode);
            w.Write(charscount);
            w.Write(0); w.Write(0);

            for (int i = 0; i < 0x10000; i++)
            {
                w.Write(0); w.Write(0);
            }

            MemoryStream vtms = new MemoryStream();
            BinaryWriter vw = new BinaryWriter(vtms);

            for (int i = 0; i < charscount; i++)
            {
                w.BaseStream.Position = 0x20 + chs[i].code * 8;
                w.Write((int)vw.BaseStream.Length + 0x80020);
                w.Write(chs[i].verts.Length);
                for (int j = 0; j < chs[i].verts.Length; j++)
                {
                    vw.Write(chs[i].verts[j].x);
                    vw.Write(chs[i].verts[j].y);
                    vw.Write(chs[i].verts[j].z);
                }
                vw.Flush();
            }
            vw.Flush();
            w.BaseStream.Position = w.BaseStream.Length;
            w.Write(vtms.ToArray());
            vw.Close();
            w.BaseStream.Position = 0xc;
            w.Write((int)w.BaseStream.Length);
            w.Flush();
            File.WriteAllBytes(fname, ms.ToArray());
            w.Close();
        }

        private CHAR3D[] chs;

        public Font3D()
        {
            Head = new byte[] { (byte)'T', (byte)'A', (byte)'M', (byte)'F', (byte)'N', (byte)'T', (byte)'3', (byte)'D' };
            //filesize = 0;
            pageCode = 1200;

            string temstr = TEXTCOLL.Reduce(CODETBL.unicode);

            //charscount = CODETBL.unicode.Length;
            charscount = temstr.Length;
            chs = new CHAR3D[charscount];
            //char[] temchar = CODETBL.unicode.ToCharArray();
            char[] temchar = temstr.ToCharArray();
            for (int i = 0; i < charscount; i++)
            {
                chs[i].value = temchar[i].ToString();
                chs[i].code = temchar[i];
            }
        }


        public Font3D(string fontcharlist,int codepage)
        {
            Head = new byte[] { (byte)'T', (byte)'A', (byte)'M', (byte)'F', (byte)'N', (byte)'T', (byte)'3', (byte)'D' };
            //filesize = 0;
            pageCode = codepage;

            string temstr = TEXTCOLL.Reduce(File.ReadAllText(fontcharlist, Encoding.GetEncoding(codepage)));

            //charscount = CODETBL.unicode.Length;
            charscount = temstr.Length;
            chs = new CHAR3D[charscount];
            //char[] temchar = CODETBL.unicode.ToCharArray();
            char[] temchar = temstr.ToCharArray();
            for (int i = 0; i < charscount; i++)
            {
                chs[i].value = temchar[i].ToString();
                chs[i].code = temchar[i];
            }
        }



    }
}
