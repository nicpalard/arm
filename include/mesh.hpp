#ifndef __MESH_HPP__
#define __MESH_HPP__

#include <iostream>
#include <vector>
#include "vertex.hpp"

class Mesh {

private:
	std::vector<Vertex> m_vertex;
	std::vector<std::vector<int>> m_face;

public:
	Mesh();
	~Mesh();

	void addVertex(Vertex vertex);
	void addFace(std::vector<int>);
	void display();
};

#endif // __MESH_HPP__
