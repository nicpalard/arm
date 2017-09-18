#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include <utility>
#include "vertex.hpp"

class Edge {
private:
	std::pair<const Vertex, const Vertex> edge;
public:
	Edge(const Vertex &a, const Vertex &b) : edge(a, b){}
	~Edge() {};
};

#endif // __EDGE_HPP__
