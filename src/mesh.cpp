#include "mesh.hpp"

Mesh::Mesh()  {}
Mesh::~Mesh() {}

void Mesh::addVertex(Vertex vertex)
{
	m_vertex.push_back(vertex);
}

// TODO : Change this and overload the << operator.
void Mesh::display()
{
	std::cerr << "[Mesh]" << std::endl;
	for (int i = 0; i < m_vertex.size(); i++) {
		std::cerr << " Vertex " << i << " : " << m_vertex[i];
	}

/*
	for (int i = 0; i < m_face.size(); i++) {
		std::cerr << " Face " << i << " : [";
		for (int j = 0; j < m_face[i].size(); j++) {
			std::cerr << m_face[i][j];
			if (j < m_face[i].size()-1) { std::cerr << ", "; }
		}
		std::cerr << "]" << std::endl;
	}
*/
}

void Mesh::buildFace(Vertex tl, Vertex tr, Vertex bl, Vertex br, int grayscale) {
	m_faces.push_back(Face(tl, tr, bl, br, grayscale));
}
