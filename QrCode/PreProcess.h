#pragma once
#include <iostream>
#include <windows.h>
#include <zbar.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/wechat_qrcode.hpp>


int ByteToMat(cv::Mat& outMat, BYTE* inBYTE, int height, int width, int channel);
int MatToByte(cv::Mat& inMat, BYTE* outBYTE);
extern "C" __declspec(dllimport) void GarbInit();
extern "C" __declspec(dllimport)void GarbImg(BYTE * outData, int width, int height, int channel);
extern "C" __declspec(dllimport) int Threshold(BYTE * inData, BYTE * outData, int height, int width, int channel, double thresh, double maxval, int type);
extern "C" __declspec(dllimport) void Detect(BYTE * inData, BYTE * outData, int height_, int width_, int channel_);
