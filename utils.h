#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
Mat Add(Mat img1, Mat img2);
Mat Sub(Mat img1, Mat img2);
int Clip(int a, int min = 0, int max = 255);
Mat Fill(Mat origin, int bgr[3]);
Mat Invert(Mat origin);
Mat Mask(Mat origin, int low, int high);
