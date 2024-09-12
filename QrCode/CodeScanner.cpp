#include "CodeScanner.h"

CodeScanner::CodeScanner()
{
	std::string detect_prototxt = "D:\\qrcode\\detect.prototxt";
	std::string detect_caffe_model = "D:\\qrcode\\detect.caffemodel";
	std::string sr_prototxt = "D:\\qrcode\\sr.prototxt";
	std::string sr_caffe_model = "D:\\qrcode\\sr.caffemodel";
	////	.\\resources\\model\\sr.caffemodel
	wechat_scanner = cv::makePtr<cv::wechat_qrcode::WeChatQRCode>(detect_prototxt, detect_caffe_model, sr_prototxt, sr_caffe_model);
	//zbar_scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

}
CodeScanner::~CodeScanner()
{



	


}



int CodeScanner::detectQR(cv::Mat& src, cv::Mat& dst)
{
	int state = 0;
	std::vector<cv::Mat> vPoints;
	std::vector<std::string> strDecoded;
	strDecoded = wechat_scanner->detectAndDecode(src, vPoints);
	if (!strDecoded.empty())
	{
			for (int i = 0; i < strDecoded.size(); i++)
			{
				cv::Point pt1 = cv::Point((int)vPoints[i].at<float>(0, 0), (int)vPoints[i].at<float>(0, 1));
				cv::Point pt2 = cv::Point((int)vPoints[i].at<float>(1, 0), (int)vPoints[i].at<float>(1, 1));
				cv::Point pt3 = cv::Point((int)vPoints[i].at<float>(2, 0), (int)vPoints[i].at<float>(2, 1));
				cv::Point pt4 = cv::Point((int)vPoints[i].at<float>(3, 0), (int)vPoints[i].at<float>(3, 1));
				line(dst, pt1, pt2, cv::Scalar(0, 255, 0), 2);
				line(dst, pt2, pt3, cv::Scalar(0, 255, 0), 2);
				line(dst, pt3, pt4, cv::Scalar(0, 255, 0), 2);
				line(dst, pt4, pt1, cv::Scalar(0, 255, 0), 2);
				putText(dst, strDecoded[i], pt1, 0, 0.5, cv::Scalar(255, 0, 0), 2);
				codeData = strDecoded.back();
			}
			state = 0;
	}
	else
		state = -1;
	return state;
}


//int CodeScanner::detectBar(cv::Mat& src, cv::Mat& dst)
//{
//	int state = 0;
//	
//	cv::Mat imageGray;
//	cv::cvtColor(src, imageGray, cv::COLOR_BGR2GRAY);
//	int width = imageGray.cols;
//	int height = imageGray.rows;
//	uchar* raw = (uchar*)imageGray.data;
//	// 在Zbar中进行扫描时候，
//	//需要将OpenCV中的Mat类型转换为（uchar *）类型，raw中存放的是图像的地址；
//	//对应的图像需要转成Zbar中对应的图像zbar::Image
//	zbar::Image imageZbar(width, height, "Y800", raw, width * height);
//	//Y800=GREY 是GRAY灰度图像
//	zbar_scanner.scan(imageZbar);
//	zbar::Image::SymbolIterator symbol = imageZbar.symbol_begin();
//	
//	if (symbol->get_count()!=0)
//	{
//		codeData = symbol->get_data();
//		state = 0;
//	}
//	else
//		state = -1;
//	return state;
//}