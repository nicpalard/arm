#include "pgm3dReader.hpp"
#include <iostream>
#include <fstream>

PgmReader::PgmReader(std::string filename)
{
	std::ifstream inputFile(filename);

	if(!inputFile.is_open())
	{
		std::cerr << "Error while reading input file." << std::endl;
		return;
	}

	std::string format;
	inputFile >> format >> m_xMax >> m_yMax >> m_zMax >> m_grayscalesMax;

	int rawData, i = 0;
	while(i != m_xMax * m_zMax * m_yMax && inputFile >> rawData)
	{
		m_data.push_back(rawData);
		i++;
	}
}

PgmReader::~PgmReader()
{}


int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " filename" << std::endl;
		return EXIT_FAILURE;
	}

	char* filename = argv[1];

	PgmReader pgm(filename);
	return EXIT_SUCCESS;
}
