#include "Vertex.h"
using namespace std;

template <typename T>
Vertex<T>::Vertex(const T Data):data(Data),weight(0) {}

template <typename T>
Vertex<T>::Vertex() {}

template <typename T>
void Vertex<T>::setData(const T Data)
{
	data=Data;
}

template <typename T>
void Vertex<T>::setVisited()
{
	cout << "inside setVisited function" << endl;

	visited=true;
}

template <typename T>
T Vertex<T>::getData() const
{
	return data;
}

template <typename T>
int Vertex<T>::getWeight() const
{
	return weight;
}

template <typename T>
bool Vertex<T>::getVisited() const
{
	return visited;
}

