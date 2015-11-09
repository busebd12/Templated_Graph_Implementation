#ifndef VERTEX_H
#define VERTEX_H
template <typename T>
class Vertex
{
	private:
		T data;
		int weight;
	public:
		Vertex(const T Data);
		Vertex(const Vertex& V)=default;  //copy constructor
		Vertex(Vertex&& V)=default;  //move constructor
		Vertex& operator=(const Vertex& V)=default;  //assignment operator
		Vertex& operator=(Vertex&& V)=default;  //move assignment operator
		T getData() const;
		int getWeight() const;
};

//need this to avoid linker errors for templates
#include "Vertex.cpp"

#endif