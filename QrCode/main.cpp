#include"CodeScanner.h"
#include"PreProcess.h"

//int main()
//{
//	cv::VideoCapture cap(0);
//	cv::waitKey(200);
//
//	cv::Mat frame;
//	cv::namedWindow("test");
//	CodeScanner test;
//	while (1)
//	{
//		cap >> frame;
//		if (frame.empty()) 
//			break;
//		test.detectQR(frame, frame);
//		cv::imshow("test",frame);
//		cv::waitKey(1);
//		
//	}
//	
//	cv::destroyWindow("test");
//	return 0;
//}




//void GetBarRoi(Mat &src,Mat &dst)
//{
//	Mat image_gray, image_gradX, image_gradY, image_grad;
//
//	cvtColor(src, image_gray, COLOR_BGR2GRAY);//转换为灰度图
//	
//	//分别计算图像在xy方向的导数
//	Scharr(image_gray, image_gradX, CV_8U, 1, 0);
//	Scharr(image_gray, image_gradY, CV_8U, 0, 1);
//	//因为我们的条形码在X方向上，所以减掉y方向的导数
//	subtract(image_gradX, image_gradY, image_grad);
//	
//
//	Mat image_threshold;
//	//对图像进行二值化并进行形态学处理
//	threshold(image_grad, image_threshold, 100, 255, THRESH_BINARY);//二值化
//	Mat  element = getStructuringElement(1, Size(9, 9));//创建形态学的结构元素
//	//膨胀两次，使条形码的二值化图像相连通
//	dilate(image_threshold, image_threshold, element);
//	dilate(image_threshold, image_threshold, element);
//	//腐蚀两次
//	erode(image_threshold, image_threshold, element);
//	erode(image_threshold, image_threshold, element);
//	//去除孤立的点
//	morphologyEx(image_threshold, image_threshold, MORPH_CLOSE, element);
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(image_threshold, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);//寻找轮廓
//	for (int i = 0; i < contours.size(); i++)
//	{
//		double TempArea = fabs(contourArea(contours[i]));//计算轮廓的面积
//		if (TempArea > 1000)//轮廓面积大于1000认为是条形码
//		{
//			Rect rect = boundingRect(contours[i]);//计算点集的矩形边界
//			rectangle(dst, rect, Scalar(255), 2);//画出矩形
//			Mat image_roi = image_gray(rect);//根据轮廓画出Roi区域
//		}
//	}
//}


//
//int main()
//{
//	cv::VideoCapture cap;
//	cap.open("D:\\AllProjects\\CProject\\opencv_project\\yolov5-opencv-cpp-python-main\\1.mp4");
//	cv::Mat src;
//	cv::Mat mat_test;
//	int width=cap.get(cv::CAP_PROP_FRAME_WIDTH);
//	int height= cap.get(cv::CAP_PROP_FRAME_HEIGHT);
//	int channel=3;
//	BYTE* byte_test = NULL; /*= new BYTE[width*height*channel]*/;
//	while (1)
//	{
//		cap >> src;
//		MatToByte(src, byte_test);
//		Threshold(byte_test, byte_test, width, height, channel,0,255,8);
//		ByteToMat(mat_test, byte_test, width, height, channel);
//		channel = 3;
//
//		cv::imshow("test", mat_test);
//		cv::waitKey(1);
//	}
//	return 0;
//}  
cv::VideoCapture cap;
int width = 2448; 
int height = 2048; 
int channel = 0;


void Detect(BYTE* inData, BYTE* outData, int height_, int width_, int channel_)
{
	CodeScanner sacanner;
	cv::Mat src;
	ByteToMat(src, inData, width,height, channel_);
	sacanner.detectQR(src, src);
	//cv::imshow("src",src);
	//cv::waitKey(1);
	MatToByte(src, outData);
}


void GarbInit()
{
	//cap.open("D:\\AllProjects\\CProject\\opencv_project\\yolov5-opencv-cpp-python-main\\1.mp4");
	cap.open(0);
	width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
	height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	channel = 3;
}
void GarbImg(BYTE* outData, int width, int height, int channel)
{
	cv::Mat src;
	cap >> src;
	//src = cv::imread("D:\\AllProjects\\CProject\\ProjectFour\\QrCode\\resources\\picture\\test.png");
	cv::resize(src, src, cv::Size(width, height), 0, 0, 1);
	//while (1)
	//{
	//	cap >> src;
		//cv::imshow("test", src);
	//	cv::waitKey(1);
	//
	MatToByte(src, outData);
}