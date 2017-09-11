#ifndef __IMAGE3D_HPP__
#define __IMAGE3D_HPP__

#include <iostream>
#include <string.h>
#include <vector>
#include <cstdint>

class Image3D {
private:
	int m_width;
	int m_height;
	int m_depth;
	uint8_t m_grayscales;
	std::vector<uint8_t> m_data;
public:
	Image3D();
	~Image3D();

	/* Use references to avoid copy */
	bool readPGM3D(const std::string &filename);
};

#endif
