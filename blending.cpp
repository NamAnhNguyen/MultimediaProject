#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math.h>   
#define PI 3.14159265
#include "utils.h"
using namespace cv;

Mat Sketch(Mat origin) {
	Mat result = origin.clone();
	int INTENSITY_FACTOR_BLACK = 100;
	int INTENSITY_FACTOR_WHITE = 120;

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = origin.at<Vec3b>(Point(j, i));
			int intensity = (color[0] + color[1] + color[2]) / 3;
			if (intensity > INTENSITY_FACTOR_WHITE )
			{
				color[0] = 255;
				color[1] = 255;
				color[2] = 255;
			}
			else if (intensity < INTENSITY_FACTOR_BLACK)
			{
				color[0] = 0;
				color[1] = 0;
				color[2] = 0;
			}
			else {
				color[0] = 127;
				color[1] = 127;
				color[2] = 127;
			}

			result.at<Vec3b>(Point(j, i)) = color;
		}
	}
	return result;
}
Mat GrayScale(Mat origin) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = origin.at<Vec3b>(Point(j, i));
			int avg = (color[0] + color[1] + color[2]) / 3;

			color[0] = avg;
			color[1] = avg;
			color[2] = avg;

			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}
Mat Splash(Mat origin, int colorRange[2]) {
	Mat image , result, grayScale;
	cvtColor(origin, image, COLOR_BGR2HSV_FULL);
	cvtColor(origin, grayScale, COLOR_BGR2GRAY);
	cvtColor(grayScale, grayScale, COLOR_GRAY2BGR);
	cvtColor(grayScale, grayScale, COLOR_BGR2HSV_FULL);

	Mat mask1 = Mask(image, colorRange[0], colorRange[1]);
	Mat mask2 = Mask(image, 179 - colorRange[1], 179 - colorRange[0]);
	Mat mask;

	bitwise_or(mask1, mask2, mask);

	bitwise_and(image, image, result, mask);
	
	//bitwise_or(result, grayScale, result);

	cvtColor(result, result, COLOR_HSV2BGR_FULL);
	return result;
}
Mat Sepia(Mat origin , float amount) {
	Mat result = origin.clone();
	Mat_ <float> sepia(3, 3);
	sepia << .131 + .869 * amount, .534 - .534 * amount, .272 - .272 * amount
		, .168 - .168 * amount, .686 + .314 * amount, .349 - .349 * amount
		, .189 - .189 * amount, .769 - .769 * amount, .393 + .607 * amount;

	transform(origin, result, sepia);
	return result;
}
Mat Saturate(Mat origin, float amount) {
	Mat result = origin.clone();
	Mat_ <float> saturate(3, 3);
	saturate << .072 + .928 * amount , .715 - .715 * amount, .213 - .213 * amount,
		.072 - .072 * amount, .715 + .285 * amount, .213 - .213 * amount,
		.072 - .072 * amount, .715 - .715 * amount, .213 + .787 * amount;
	transform(origin, result, saturate);
	return result;
}
Mat ContrastAndBrightness(Mat origin, float con, float bri) {
	Mat result;
	origin.convertTo(result, con, bri);
	return result;
}
Mat Blend(Mat foreground, Mat background , double alpha) {
	// g = ( 1 - a ) f1(x) + a f2(x)
	Mat result ;
	double  beta = 1.0 - alpha;
	addWeighted(foreground, alpha, background, beta, 0.0, result);
	return result;
}
Mat HueRotate(Mat origin, int deg) {
	Mat result = origin.clone();

	float cos_hue = cos(deg * PI / 180.0);
	float sin_hue = sin(deg * PI / 180.0);

	Mat_ <float> matrix(3, 3);
	matrix << .072 + cos_hue * .928 + sin_hue * .072, .715 - cos_hue * .715 + sin_hue * .715, .213 - cos_hue * .213 - sin_hue * .787,
		.072 - cos_hue * .072 - sin_hue * .283, .715 + cos_hue * .285 + sin_hue * .140, .213 - cos_hue * .213 + sin_hue * .143,
		.072 - cos_hue * .072 + sin_hue * .928, .715 - cos_hue * .715 - sin_hue * .715, .213 + cos_hue * .787 - sin_hue * .213;

	transform(origin, result, matrix);
	return result;
}