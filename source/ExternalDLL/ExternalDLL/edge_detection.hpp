#ifndef EDGE_DETECTION_HPP
#define EDGE_DETECTION_HPP

#include "IntensityImage.h"

class edge_detection {
public:
	static void mask_operation(const int(&mask)[9], IntensityImage const & original_image, IntensityImage & new_image);
};

#endif