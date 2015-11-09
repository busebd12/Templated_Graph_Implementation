#ifndef GRAPH_H
#define GRAPH_H
#include "Vertex.h"
#include <map>
#include <vector>
#include <iostream>
template <typename T>
class Graph
{	
	private:
		std::map<Vertex<T>, std::vector<Vertex<T>>> adjacencyList;
		int numberOfElements;
	public:
		Graph();
		Graph(const Graph& G)=default;  //copy constructor
		Graph(Graph&& G)=default;  //move constructor
		Graph& operator=(const Graph& G)=default;   //assignment operator
		Graph& operator=(Graph&& G)=default;  //copy assignment operator
		std::map<Vertex<T>, std::vector<Vertex<T>>> getAdjacencyList() const;
		int getNumberOfElements() const;
};

//need this to avoid linker errors for templates
#include "Graph.cpp"

#endif