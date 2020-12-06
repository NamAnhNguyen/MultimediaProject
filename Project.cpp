#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "utils.h"
#include "blending.h"
#include "filters.h"

using namespace cv;

Mat blue(Mat origin) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = origin.at<Vec3b>(Point(j, i));

			color[1] = 0;
			color[2] = 0;
			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}

Mat green(Mat origin) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = origin.at<Vec3b>(Point(j, i));

			color[0] = 0;
			color[2] = 0;
			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}

Mat red(Mat origin) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = origin.at<Vec3b>(Point(j, i));

			int avg = (color[0] + color[1] + color[2]) / 3;

			color[0] = 0;
			color[1] = 0;
			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}



int main()
{
	Mat image = imread("Image/lyca2.jpg"); //BGR
	
	Mat gaussianBlurImage = image.clone();

	GaussianBlur(image, gaussianBlurImage, Size(5, 5), 0);
	addWeighted(image, 1.5, gaussianBlurImage, -0.5, 0, gaussianBlurImage);

	Mat newImage = Walden(gaussianBlurImage);

	namedWindow("Origin", WINDOW_NORMAL);
	imshow("Origin", image);

	namedWindow("Demo", WINDOW_NORMAL);
	imshow("Demo", newImage);
	waitKey(0);
	return 0;
}

