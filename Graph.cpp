#include "Graph.h"
using namespace std;

template <typename T>
Graph<T>::Graph():numberOfElements(0) {}

template <typename T>
void Graph<T>::addVertex(const T& Data, const T& AdjacentData)
{
	Vertex<T> vertex;

	vertex.setData(Data);

	Vertex<T> adjacentVertex;

	adjacentVertex.setData(AdjacentData);

	//insert the vertex and its adjacent vertex
	adjacencyList[vertex].emplace_back(adjacentVertex);

	//insert the adjacent vertex as its own vertex
	adjacencyList[adjacentVertex];

	//increase by two since we are inserting two vertices
	numberOfElements+=2;
}

template <typename T>
void Graph<T>::print() const
{
	for(const auto & vertex : adjacencyList)
	{
		//print each vertex
		cout << "Vertex " << vertex.first.getData() << " is adjacent to the following vertices: {";

		//print the list of adjacent vertices stored in the vector
		for(const auto & vert : vertex.second)
		{
			cout << vert.getData();
		}

		cout << "}" << endl;
	}
}

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