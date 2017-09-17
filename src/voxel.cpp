#include "voxel.hpp"

Voxel::Voxel(int x, int y, int z, uint8_t data)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_data = data;
	buildMesh();
}


Voxel::~Voxel() {}

Mesh Voxel::buildMesh()
{
	Mesh mesh;

	/*
	for (float xShift = -0.5; xShift <= 0.5; xShift++) {
		for (float yShift = -0.5; yShift <= 0.5; yShift++) {
			for (float zShift = -0.5; zShift <= 0.5; zShift++) {
				mesh.addVertex(Vertex(m_x+xShift, m_y+yShift, m_z+zShift));
			}
		}
	}

	mesh.addFace({0,2,3,1});
	mesh.addFace({4,6,7,5});
	mesh.addFace({0,4,5,1});
	mesh.addFace({0,4,6,2});
	mesh.addFace({2,6,7,3});
	mesh.addFace({1,5,7,3});

	*/

	/*
	  z
	 /
	+ --- x
	|
	y
	  g--------f
	 /|       /|
	a-+------b |
	| |      | |
	| h------+-e
	|/       |/
	c--------d

	1: a b c d
	2: a b f g
	3: c d e h
	4: b d e f
	5: e f g h
	6: a c g h
	*/

	Vertex a = Vertex(m_x-0.5, m_y-0.5, m_z-0.5);
	Vertex g = Vertex(m_x-0.5, m_y-0.5, m_z+0.5);

	Vertex b = Vertex(m_x+0.5, m_y-0.5, m_z-0.5);
	Vertex f = Vertex(m_x+0.5, m_y-0.5, m_z+0.5);

	Vertex c = Vertex(m_x-0.5, m_y+0.5, m_z-0.5);
	Vertex h = Vertex(m_x-0.5, m_y+0.5, m_z+0.5);

	Vertex d = Vertex(m_x+0.5, m_y+0.5, m_z-0.5);
	Vertex e = Vertex(m_x+0.5, m_y+0.5, m_z+0.5);

	mesh.buildFace(a, b, c, d, m_data);
	mesh.buildFace(a, b, f, g, m_data);
	mesh.buildFace(c, d, e, h, m_data);
	mesh.buildFace(b, d, e, f, m_data);
	mesh.buildFace(e, f, g, h, m_data);
	mesh.buildFace(a, c, g, h, m_data);

	//mesh.display();

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
