#include "image3D.hpp"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QMainWindow>

int main(int argc, char** argv)
{
	QApplication run(argc, argv);
	QMainWindow window;
	window.setFixedSize(200, 200);
	window.show();
	run.exec();
	
	if(argc != 2) {
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
