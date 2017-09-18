#ifndef __MESH_HPP__
#define __MESH_HPP__

#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "face.hpp"
#include "edge.hpp"

class Mesh {

private:
	std::vector<Vertex> m_vertex;
	std::vector<Face> m_faces;
	std::vector<Edge> m_edges;

public:
	Mesh();
	~Mesh();

	void addVertex(Vertex vertex);
	void buildFace(Vertex tl, Vertex tr, Vertex bl, Vertex br, int grayLevel);
	void display();
};

#endif // __MESH_HPP__
