#include "voxel.hpp"

Voxel::Voxel(int x, int y, int z, uint8_t data) {
	m_x = x;
	m_y = y;
	m_z = z;
	m_data = data;
}

Voxel::~Voxel() {}

std::ostream & operator << (std::ostream &os, const Voxel &voxel) {
	os << "[" << voxel.m_x << ", "
	<< voxel.m_y << ", "
	<< voxel.m_z << ", "
	<< (int)voxel.m_data << "]" << std::endl;
}
