#include "StudentPreProcessing.h"
#include "edge_detection.hpp"
#include "ImageFactory.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	IntensityImage * blur_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	IntensityImage * sobel_image = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	int gausian_blur_mask[] = { 1, 2, 1, 2, 4, 2, 1, 2, 1 };
	int sobel_mask[] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };
	edge_detection::mask_operation(gausian_blur_mask, image, *blur_image);
	edge_detection::mask_operation(sobel_mask, *blur_image, *sobel_image);



	return sobel_image;
	//return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}