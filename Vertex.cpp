#include "Vertex.h"

template <typename T>
Vertex<T>::Vertex(const T Data):data(Data),weight(0) {}

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

