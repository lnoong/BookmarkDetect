using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace DllTest
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        [DllImport("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\x64\\Release\\QrCode.dll")]
        public static extern int Threshold();
  
        private void Button_Click(object sender, RoutedEventArgs e)
        {

            Bitmap bmp = new Bitmap(1440, 1080, PixelFormat.Format24bppRgb);
            Rectangle rectangle = new Rectangle(0, 0, 1440, 1080);
            while (Visible)
            {
                BitmapData bmd = bmp.LockBits(rectangle, ImageLockMode.ReadWrite, PixelFormat.Format24bppRgb);
                ImageToCs(bmd.Scan0);
                bmp.UnlockBits(bmd);
                pictureBox1.Image = bmp;
                Application.DoEvents();
            }

        }
    }
}
