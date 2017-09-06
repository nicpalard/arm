#include "pgm3dReader.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

#define HEADER_SIZE 5

void printHeader(std::string format, int width, int height, int depth, int grayscales) {
	std::cerr << "[Header]" << std::endl
	<< "format=" << format << std::endl
	<< "width=" << width << std::endl
	<< "height=" << height << std::endl
	<< "depth=" << depth << std::endl
	<< "grayscales=" << grayscales << std::endl;
}

PGM3DReader::PGM3DReader() : m_width(0), m_height(0), m_depth(0), m_grayscales(0)
{}

bool PGM3DReader::readPGM3D(const std::string &filename) {
	std::ifstream inputFile(filename);

	if(!inputFile.is_open())
	{
		std::cerr << "Error while reading input file." << std::endl;
		return false;
	}

	std::string data;
	std::string format;
	int headerCount(0);
	while(inputFile)
	{
		inputFile >> data;
		if(data[0] == '#')
		{
			inputFile.ignore(20, '\n');
			std::cout << "Skip" << std::endl;
		}
		else
		{
			/* If we have already read the header, we store the raw data in m_data */
			if(headerCount == HEADER_SIZE)
			{
				m_data.push_back(atoi(data.c_str()));
			}
			else
			{
				/* We need to read the HEADER_SIZE values for heade informations
				We assume that they're in the right order -> format width height depth grayscales */
				headerCount++;
				switch(headerCount)
				{
					case 1:
						format = data.c_str();
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
						m_grayscales = atoi(data.c_str());
						break;
					default:
						break;
				}
			}
		}
	}

	/* Debug line */
	printHeader(format, m_width, m_height, m_depth, m_grayscales);

	return true;
}


PGM3DReader::~PGM3DReader()
{}

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		//usage(argv[0], BAD_ARGUMENT_NUMBER);
		std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
		return EXIT_FAILURE;
	}

	char* filename = argv[1];

	PGM3DReader reader;
	if(!reader.readPGM3D(filename)){
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
