#include "vertex.hpp"

Vertex::Vertex(float x, float y, float z)
{
  m_x = x;
  m_y = y;
  m_z = z;
}

Vertex::~Vertex() {}

std::ostream & operator << (std::ostream &os, const Vertex &vertex)
{
  os << "[" << vertex.m_x << ", "
     << vertex.m_y << ", "
     << vertex.m_z << "]" << std::endl;
}
