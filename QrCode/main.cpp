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
//	cvtColor(src, image_gray, COLOR_BGR2GRAY);//ת��Ϊ�Ҷ�ͼ
//	
//	//�ֱ����ͼ����xy����ĵ���
//	Scharr(image_gray, image_gradX, CV_8U, 1, 0);
//	Scharr(image_gray, image_gradY, CV_8U, 0, 1);
//	//��Ϊ���ǵ���������X�����ϣ����Լ���y����ĵ���
//	subtract(image_gradX, image_gradY, image_grad);
//	
//
//	Mat image_threshold;
//	//��ͼ����ж�ֵ����������̬ѧ����
//	threshold(image_grad, image_threshold, 100, 255, THRESH_BINARY);//��ֵ��
//	Mat  element = getStructuringElement(1, Size(9, 9));//������̬ѧ�ĽṹԪ��
//	//�������Σ�ʹ������Ķ�ֵ��ͼ������ͨ
//	dilate(image_threshold, image_threshold, element);
//	dilate(image_threshold, image_threshold, element);
//	//��ʴ����
//	erode(image_threshold, image_threshold, element);
//	erode(image_threshold, image_threshold, element);
//	//ȥ�������ĵ�
//	morphologyEx(image_threshold, image_threshold, MORPH_CLOSE, element);
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(image_threshold, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_NONE);//Ѱ������
//	for (int i = 0; i < contours.size(); i++)
//	{
//		double TempArea = fabs(contourArea(contours[i]));//�������������
//		if (TempArea > 1000)//�����������1000��Ϊ��������
//		{
//			Rect rect = boundingRect(contours[i]);//����㼯�ľ��α߽�
//			rectangle(dst, rect, Scalar(255), 2);//��������
//			Mat image_roi = image_gray(rect);//������������Roi����
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