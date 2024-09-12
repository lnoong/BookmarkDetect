#include "PreProcess.h"

int MatToByte(cv::Mat& inMat, BYTE* outBYTE)
{

	int cols = inMat.cols;
	int rows = inMat.rows;
	int channels = inMat.channels();

	/*if (outBYTE)
		delete outBYTE;
	outBYTE = new BYTE[cols * rows * channels];*/
	//outBYTE =(BYTE*)realloc(outBYTE,cols * rows * channels);
	int index = 0;
	for (int i = 0; i < rows; ++i) {
		std::memcpy(outBYTE + index, inMat.ptr(i), cols * channels);
		index += cols * channels;
	}
	return 0;
}

int ByteToMat(cv::Mat& outMat, BYTE* inBYTE,  int width, int height, int channel)
{
	if (inBYTE == nullptr)
	{
		return -1;
	}
	int type = channel == 1 ? CV_8UC1 : CV_8UC3;
	outMat = cv::Mat::zeros(height, width, type);

	// 逐行拷贝像素值到 cv::Mat 对象中
	int index = 0;
	for (int i = 0; i < height; ++i) {
		std::memcpy(outMat.ptr(i), inBYTE + index, width * channel);
		index += width * channel;
	}
	return 0;
}


int Threshold(BYTE* inData,BYTE* outData,int width, int height, int channel, double thresh, double maxval, int type)
{
	cv::Mat src;
	ByteToMat(src, inData, width, height, channel);
	if (channel == 3)
	{
		cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
	}
	cv::threshold(src, src, thresh, maxval, type);
	cv::resize(src,src,cv::Size(width*channel, height),0,0,1);
	MatToByte(src, outData);
	return 0;
}