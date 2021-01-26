#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "blending.h"
#include "utils.h"

using namespace cv;
Mat _1977(Mat origin) {
	Mat background = origin.clone();
	int bgr[] = { 188,106,243 };
	background = Fill(background, bgr);

	Mat newImage = Blend(origin, background, 0.9);

	newImage = ContrastAndBrightness(newImage, 0.55, 1.1);
	return newImage;
}

Mat Brannan(Mat origin) {
	Mat background = origin.clone();
	int bgr[] = { 199,44,161 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.75);
	newImage = Sepia(newImage, 0.5);
	newImage = ContrastAndBrightness(newImage, 0.55, 1);

	return newImage;
}

Mat Brooklyn(Mat origin) {
	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 193, 223, 168 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 200, 183, 196 };
	background2 = Fill(background2, bgr2);

	Mat newImage1 = Blend(origin, background1, 0.9);
	Mat newImage2 = Blend(origin, background2, 0.9);
	Mat newImage = Add(newImage1, newImage2);

	newImage = ContrastAndBrightness(newImage, 0.9, 1.1);

	return newImage;
}

Mat Clarendon(Mat origin) {
	Mat background = origin.clone();
	int bgr[] = { 227, 187, 127 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.825);
	newImage = ContrastAndBrightness(newImage, 1.2, 1);
	newImage = Saturate(newImage, 1);

	return newImage;
}

Mat Gingham(Mat origin) {
	Mat background = origin.clone();
	int bgr[] = { 250, 230, 230 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.825);
	newImage = ContrastAndBrightness(newImage, 1, 1.05);
	newImage = HueRotate(newImage, -10);

	return newImage;
}

Mat Inkwell(Mat origin) {

	Mat newImage = Sepia(origin, 0.3);
	newImage = ContrastAndBrightness(newImage, 1.1, 1.1);
	newImage = GrayScale(newImage);

	return newImage;
}

Mat Kelvin(Mat origin) {
	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 52, 44, 56 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 33, 125, 183 };
	background2 = Fill(background2, bgr2);

	Mat newImage = Blend(origin, background1, 0.825);
	newImage = Blend(newImage, background2, 0.825);

	return newImage;
}

Mat Lark(Mat origin) {
	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 63, 44, 34 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 242,242,242 };
	background2 = Fill(background2, bgr2);

	Mat newImage = Blend(origin, background1, 0.825);
	newImage = Blend(newImage, background2, 0.825);
	newImage = ContrastAndBrightness(newImage, 0.9, 1);

	return newImage;
}


Mat Maven(Mat origin) {

	Mat background = origin.clone();
	int bgr[] = { 26, 230, 3 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.825);
	newImage = Sepia(newImage, 0.25);
	newImage = ContrastAndBrightness(newImage, 0.95, 1.95);
	newImage = Saturate(newImage, 1.5);

	return newImage;
}

Mat Moon(Mat origin) {

	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 160, 160, 160 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 56,56,56 };
	background2 = Fill(background2, bgr2);

	Mat newImage = Blend(origin, background1, 0.825);
	newImage = Blend(newImage, background2, 0.825);
	newImage = GrayScale(newImage);
	newImage = ContrastAndBrightness(newImage, 1.1, 1.1);

	return newImage;
}

Mat Nashville(Mat origin) {

	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 153, 176, 247 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 150,70,0 };
	background2 = Fill(background2, bgr2);

	Mat newImage = Blend(origin, background1, 0.825);
	newImage = Blend(newImage, background2, 0.825);
	newImage = Sepia(newImage, 0.2);
	newImage = ContrastAndBrightness(newImage, 1.2, 1.05);
	newImage = Saturate(newImage, 1.2);

	return newImage;
}

Mat Reyes(Mat origin) {

	Mat background = origin.clone();
	int bgr[] = { 173, 205, 239 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.5);
	newImage = ContrastAndBrightness(newImage, 0.85, 1.1);

	return newImage;
}

Mat Slumber(Mat origin) {

	Mat background1 = origin.clone();
	Mat background2 = origin.clone();

	int bgr1[] = { 12, 41, 69 };
	background1 = Fill(background1, bgr1);

	int bgr2[] = { 24,105,125 };
	background2 = Fill(background2, bgr2);

	Mat newImage = Blend(origin, background1, 0.75);
	newImage = Blend(newImage, background2, 0.75);
	newImage = ContrastAndBrightness(newImage, 1, 1.05);
	return newImage;
}
Mat Stinson(Mat origin) {

	Mat background = origin.clone();
	int bgr[] = { 128, 149, 240 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.75);
	newImage = ContrastAndBrightness(newImage, 0.75, 1.15);

	return newImage;
}

Mat Valencia(Mat origin) {

	Mat background = origin.clone();
	int bgr[] = { 57, 3, 58 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.5);
	newImage = ContrastAndBrightness(newImage, 1.08, 1.08);
	newImage = Sepia(newImage, 0.08);

	return newImage;
}

Mat Walden(Mat origin) {

	Mat background = origin.clone();
	int bgr[] = { 204, 68, 0 };
	background = Fill(background, bgr);
	Mat newImage = Blend(origin, background, 0.7);
	newImage = ContrastAndBrightness(newImage, 1, 1.1);
	newImage = HueRotate(newImage,0.3);
	newImage = Sepia(newImage, 0.3);

	return newImage;
}