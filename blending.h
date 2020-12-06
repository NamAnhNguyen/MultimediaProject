#pragma once
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
Mat Sketch(Mat origin);
Mat GrayScale(Mat origin);
Mat Splash(Mat origin, int colorRange[2]);
Mat Sepia(Mat origin, float amount = 1);
Mat Saturate(Mat origin, int amount);
Mat ContrastAndBrightness(Mat origin, int con, int bri);
Mat Blend(Mat foreground, Mat background, double alpha);
Mat HueRotate(Mat origin, int deg);