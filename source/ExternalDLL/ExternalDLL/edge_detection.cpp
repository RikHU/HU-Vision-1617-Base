#include "edge_detection.hpp"

void edge_detection::mask_operation(const int (&mask)[9], const IntensityImage & original_image, IntensityImage & new_image) {
	int mask_size = sizeof(mask) / sizeof(*mask);
	int mask_total = 0;
	for (int i = 0; i < mask_size; i++) {
		mask_total += mask[i];
	}
	mask_size /= 3;

	int width = new_image.getWidth();
	int height = new_image.getHeight();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			//make the border of the image black
			if (x < mask_size || y < mask_size || x >= width - mask_size || y >= height - mask_size) {
				new_image.setPixel(x, y, 0);
			}
			//use the mask to detect edges
			else {
				int intensity = 0, count = 0;
				for (int mask_y = -mask_size / 2; mask_y <= mask_size / 2; mask_y++) {
					for (int mask_x = -mask_size / 2; mask_x <= mask_size / 2; mask_x++) {
						intensity += (original_image.getPixel(x + mask_x, y + mask_y) * mask[count]);
						count++;
					}
				}
				new_image.setPixel(x, y, intensity/16);
			}
		}
	}
}