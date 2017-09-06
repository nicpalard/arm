#ifndef __PGM3D_READER_H__
#define __PGM3D_READER_H__

#include <iostream>
#include <string.h>
#include <vector>

class PGM3DReader
{
private:
	int m_width;
	int m_height;
	int m_depth;
	int m_grayscales;
	std::vector<int> m_data;
public:
	PGM3DReader();
	~PGM3DReader();

	/* Use references to avoid copy */
	bool readPGM3D(const std::string &filename);
};

#endif
