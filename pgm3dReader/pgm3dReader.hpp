#ifndef __PGM3D_READER_H__
#define __PGM3D_READER_H__

#include <iostream>
#include <string.h>
#include <vector>

class PgmReader
{
private:
	int m_xMax;
	int m_yMax;
	int m_zMax;
	int m_grayscalesMax;
	std::vector<int> m_data;
public:
	PgmReader(std::string filename);
	~PgmReader();
};

#endif
