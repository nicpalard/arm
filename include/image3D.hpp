#ifndef __IMAGE3D_HPP__
#define __IMAGE3D_HPP__

#include <string.h>
#include <vector>
#include "voxel.hpp"

class Image3D {
private:
	int m_width;
	int m_height;
	int m_depth;
	uint8_t m_grayscales;
	std::vector<Voxel> m_data;

public:
	Image3D();
	~Image3D();

	void displayInfo();
	void displayData();

	/* Use references to avoid copy */
	bool readPGM3D(const std::string &filename);


	static const int HEADER_SIZE = 5;
};

#endif // __IMAGE3D_HPP__
