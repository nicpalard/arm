#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include <iostream>

class Vertex {
  
private:
  float m_x;
  float m_y;
  float m_z;

public:
  Vertex(float x, float y, float z);
  ~Vertex();

  friend std::ostream & operator <<(std::ostream &os, const Vertex &vertex);
};

#endif // __VERTEX_HPP__
