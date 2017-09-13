project(washington)

cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB src
	"src/*.cpp"
	"include/*.hpp"
)

add_executable(${PROJECT_NAME} ${src})
