#include "voxel.hpp"

Voxel::Voxel(int x, int y, int z, uint8_t data)
{
  m_x = x;
  m_y = y;
  m_z = z;
  m_data = data;
  makeMesh();
}


Voxel::~Voxel() {}

Mesh Voxel::makeMesh()
{
  Mesh mesh;
  
  for (float x = -0.5; x <= 0.5; x++) {
    for (float y = -0.5; y <= 0.5; y++) {
      for (float z = -0.5; z <= 0.5; z++) {
	mesh.addVertex(Vertex(m_x+x, m_y+y, m_z+z));
      }
    }
  }

  mesh.addFace({0,2,3,1});
  mesh.addFace({4,6,7,5});
  mesh.addFace({0,4,5,1});
  mesh.addFace({0,4,6,2});
  mesh.addFace({2,6,7,3});
  mesh.addFace({1,5,7,3});

  mesh.display();
  
  return mesh;
}


std::ostream & operator << (std::ostream &os, const Voxel &voxel)
{
  os << "["
     << voxel.m_x << ", "
     << voxel.m_y << ", "
     << voxel.m_z << ", "
     << (int)voxel.m_data
     << "]" << std::endl;
}
