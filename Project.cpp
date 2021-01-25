#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "utils.h"
#include "blending.h"
#include "filters.h"

using namespace cv;

int main()
{
	Mat image1 = imread("Image/ruyi.jpg"); //BGR	
	int bgr[3] = { 0,30 };
	int colorRange[2] = { 60,180 };
	Mat newImage = Splash(image1,colorRange);

	cv::namedWindow("Origin1", WINDOW_NORMAL);
	cv::imshow("Origin1", image1);

	cv::namedWindow("Demo", WINDOW_NORMAL);
	cv::imshow("Demo", newImage);
	cv::waitKey(0);
	return 0;
}

