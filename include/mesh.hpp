#ifndef __MESH_HPP__
#define __MESH_HPP__

#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "face.hpp"

class Mesh {

private:
	std::vector<Vertex> m_vertex;
	std::vector<std::vector<int>> m_face;
	std::vector<Face> m_faces;

public:
	Mesh();
	~Mesh();

	void addVertex(Vertex vertex);
	void addFace(std::vector<int>);
	void buildFace(Vertex tl, Vertex tr, Vertex bl, Vertex br, int grayLevel);
	void display();
};

#endif // __MESH_HPP__
