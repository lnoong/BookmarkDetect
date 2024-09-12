#pragma once
#include <iostream>
#include <zbar.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/wechat_qrcode.hpp>


class CodeScanner
{
public:
	CodeScanner();
	~CodeScanner();


public:
	std::string codeData;
	int detectQR(cv::Mat& src, cv::Mat& dst);
	int detectBar(cv::Mat& src, cv::Mat& dst);
	
private:

	cv::Ptr<cv::wechat_qrcode::WeChatQRCode> wechat_scanner;
	zbar::ImageScanner zbar_scanner;

};

