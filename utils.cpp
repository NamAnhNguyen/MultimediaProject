#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;

Mat Add(Mat img1, Mat img2) {
	Mat result = img1.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color1 = img1.at<Vec3b>(Point(j, i));
			Vec3b& color2 = img2.at<Vec3b>(Point(j, i));

			Vec3b& color = result.at<Vec3b>(Point(j, i));

			for (int k = 0; k < 3; k++)
			{
				int sum = color1[k] + color2[k];
				color[k] = sum > 255 ? 255 : sum;
			}

			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}

Mat Sub(Mat img1, Mat img2) {
	Mat result = img1.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color1 = img1.at<Vec3b>(Point(j, i));
			Vec3b& color2 = img2.at<Vec3b>(Point(j, i));

			Vec3b& color = result.at<Vec3b>(Point(j, i));

			for (int k = 0; k < 3; k++)
			{
				int sub = color1[k] - color2[k];
				color[k] = sub < 0 ? 0 : sub;
			}

			result.at<Vec3b>(Point(j, i)) = color;
		}
	}

	return result;
}

int Clip(int a, int min, int max) {
	int maxOf = a > min ? a : min;
	return max < maxOf ? max : maxOf;
}

Mat Fill(Mat origin, int bgr[3]) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = result.at<Vec3b>(Point(j, i));

			for (int k = 0; k < 3; k++)
			{
				color[k] = bgr[k];
			}

			result.at<Vec3b>(Point(j, i)) = color;

		}
	}
	return result;
}

Mat Invert(Mat origin) {
	Mat result = origin.clone();

	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			Vec3b& color = result.at<Vec3b>(Point(j, i));

			for (int k = 0; k < 3; k++)
			{
				color[k] = 255 - color[k];
			}

			result.at<Vec3b>(Point(j, i)) = color;
		}
	}
	return result;
}

Mat Mask(Mat origin, int low, int high) {

	Mat result = origin.clone();
	inRange(result, Scalar(low, 120, 70), Scalar(high, 255, 255), result);
	return result;
}