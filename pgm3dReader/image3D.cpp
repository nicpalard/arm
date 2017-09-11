#include "image3D.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

#define HEADER_SIZE 5

static void printHeader(std::string &format, int width, int height, int depth, int grayscales, std::vector<uint8_t> data) {
	std::cerr << "[Header]" << std::endl
	<< "format=" << format << std::endl
	<< "width=" << width << std::endl
	<< "height=" << height << std::endl
	<< "depth=" << depth << std::endl
	<< "grayscales=" << grayscales << std::endl
	<< "data=" << std::endl;
	for(int i = 0 ; i < data.size() ; i++) {
		std::cerr <<  unsigned(data[i]) << std::endl;
	}
}

/* Class Image3D
	- int size;
	- unint8 data; (typedef unsigned char uint8)
*/

Image3D::Image3D() : m_width(0), m_height(0), m_depth(0), m_grayscales(0)
{}

bool Image3D::readPGM3D(const std::string &filename) {
	std::ifstream inputFile(filename);

	if(!inputFile.is_open()) {
		std::cerr << "Error while reading input file." << std::endl;
		return false;
	}

	std::string data;
	std::string format;
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
				m_data.push_back(value);
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

	/* Debug line */
	//printHeader(format, m_width, m_height, m_depth, m_grayscales, m_data);
	return m_width * m_height * m_depth == m_data.size();
}


Image3D::~Image3D()
{}

int main(int argc, char** argv)
{
	if(argc != 2) {
		//usage(argv[0], BAD_ARGUMENT_NUMBER);
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		return EXIT_FAILURE;
	}

	char* filename = argv[1];

	Image3D image;
	if(!image.readPGM3D(filename)) {
		std::cout << "Bad file" << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
