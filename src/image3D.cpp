#include "image3D.hpp"
#include <fstream>
#include <cstdlib>
#include <climits>

/* Class Image3D
- int size;
- unint8 data; (typedef unsigned char uint8)
*/

Image3D::Image3D() : m_width(0), m_height(0), m_depth(0), m_grayscales(0) {}

Image3D::~Image3D() {}

void Image3D::displayInfo()
{
	std::cerr << "[Image Info]"                              << std::endl
	<< "  width = "      << m_width                << std::endl
	<< "  height = "     << m_height               << std::endl
	<< "  depth = "      << m_depth                << std::endl
	<< "  grayscales = " << unsigned(m_grayscales) << std::endl;
}

void Image3D::displayData()
{
	std::cerr << "[Image Data]" << std::endl << " ";

	for(int i = 0 ; i < m_data.size() ; i++) {
		std::cerr << m_data[i] << " ";
	}
	std::cerr << std::endl;
}

bool Image3D::readPGM3D(const std::string &filename)
{
	std::ifstream inputFile(filename);

	if(!inputFile.is_open()) {
		std::cerr << "Error while reading input file." << std::endl;
		return false;
	}

	std::string data;
	std::string format;

	int x = 0, y = 0, z = 0;
	int headerCount(0);
	while(inputFile >> data && inputFile) {
		if(data[0] == '#') {
			inputFile.ignore(INT_MAX, '\n');
		}
		else {
			/* If we have already read the header, we store the raw data in m_data */
			if(headerCount == HEADER_SIZE) {
				uint8_t value = (uint8_t)atoi(data.c_str());
				if(value > m_grayscales) {
					return false;
				}
				Voxel v(x, y, z, value);
				x++;
				if(x == m_width) {
					x=0;
					y++;
				}
				if(y == m_height) {
					y = 0;
					z++;
				}
				m_data.push_back(v);
			}
			else {
				/* We need to read the HEADER_SIZE values for header informations
				We assume that they're in the right order -> format width height depth grayscales */
				headerCount++;
				switch(headerCount)
				{
					case 1:
					format = data.c_str();
					if(format != "PGM3D") {
						return false;
					}
					break;
					case 2:
					m_width = atoi(data.c_str());
					break;
					case 3:
					m_height = atoi(data.c_str());
					break;
					case 4:
					m_depth = atoi(data.c_str());
					break;
					case 5:
					m_grayscales = (uint8_t)atoi(data.c_str());
					break;
					default:
					break;
				}
			}
		}
	}
	
	return (m_width * m_height * m_depth == m_data.size());
}
