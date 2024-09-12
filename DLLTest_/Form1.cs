using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DLLTest_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        [DllImport("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\x64\\Release\\QrCode.dll")]
        public static extern void GarbInit();
        [DllImport("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\x64\\Release\\QrCode.dll")]
        public static extern void GarbImg(IntPtr outData, int width, int height, int channel);
        [DllImport("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\x64\\Release\\QrCode.dll")]
        public static extern int Threshold(IntPtr inData, IntPtr outData, int height, int width, int channel, double thresh, double maxval, int type);
        [DllImport("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\x64\\Release\\QrCode.dll")]
        public static extern void Detect(IntPtr inData, IntPtr outData, int height, int width, int channel);
        private void button1_Click(object sender, EventArgs e)
        {
            Bitmap bmp = new Bitmap(640, 480, PixelFormat.Format24bppRgb);
            Rectangle rectangle = new Rectangle(0, 0, 640, 480);
            GarbInit();
            while (Visible)
            {
                BitmapData bmd = bmp.LockBits(rectangle, ImageLockMode.ReadWrite, PixelFormat.Format24bppRgb);
                GarbImg(bmd.Scan0, 640, 480, 3);
                //Threshold(bmd.Scan0, bmd.Scan0, 640, 480, 3, 0, 255, 8|0);
                Detect(bmd.Scan0, bmd.Scan0, 640, 480, 3);
                bmp.UnlockBits(bmd);
                pictureBox1.Image = bmp;
                Application.DoEvents();
            }
        }
    }
}
