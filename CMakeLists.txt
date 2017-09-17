project(pgm3dvisu)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)

#Qt
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB src
	"src/*.cpp"
	"include/*.hpp"
)

add_executable(${PROJECT_NAME} ${src})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core)
