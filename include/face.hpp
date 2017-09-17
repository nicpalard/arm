#ifndef __FACE_HPP__
#define __FACE_HPP__

#include "vertex.hpp"

class Face {
private:
	Vertex m_topLeft, m_topRight, m_botLeft, m_botRight;
	int m_grayLevel;

public:
	Face(Vertex tl, Vertex tr, Vertex bl, Vertex br, int grayLevel) : m_topLeft(tl), m_topRight(tr), m_botLeft(bl), m_botRight(br), m_grayLevel(grayLevel) {};
	~Face() {};
};

#endif // __FACE_HPP
