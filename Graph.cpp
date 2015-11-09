#include "Graph.h"
using namespace std;

template <typename T>
Graph<T>::Graph():numberOfElements(0) {}

template <typename T>
map<Vertex<T>, vector<Vertex<T>>> Graph<T>::getAdjacencyList() const
{
	return adjacencyList;
}

template <typename T>
int Graph<T>::getNumberOfElements() const
{
	return numberOfElements;
}