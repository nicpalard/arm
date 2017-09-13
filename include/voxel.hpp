#ifndef __VOXEL_HPP__
#define __VOXEL_HPP__

#include <iostream>
#include <cstdint>
#include <vector>
#include "vertex.hpp"
#include "mesh.hpp"

class Voxel {

private:
  int m_x;
  int m_y;
  int m_z;
  uint8_t m_data;

public:
  Voxel(int x, int y, int z, uint8_t data = 0);
  ~Voxel();
  
  Mesh makeMesh();

  friend std::ostream & operator <<(std::ostream &os, const Voxel &voxel);
};

#endif // __VOXEL_HPP__
