#ifndef VERTEX_H
#define VERTEX_H

template <typename T>
class Vertex;

//need the forward declaration since it is a templated friend function
template <typename T>
bool operator< (const Vertex<T> & v1, const Vertex<T> & v2);

template <typename T>
class Vertex
{
	private:
		T data;
		int weight;
	public:
		Vertex();
		Vertex(const T Data);
		Vertex(const Vertex& V)=default;  //copy constructor
		Vertex(Vertex&& V)=default;  //move constructor
		Vertex& operator=(const Vertex& V)=default;  //assignment operator
		Vertex& operator=(Vertex&& V)=default;  //move assignment operator
		friend bool operator< <T>(const Vertex<T> & v1, const Vertex<T> & v2); //need the <T> since it is a templated friend function
		void setData(const T Data);
		T getData() const;
		int getWeight() const;
};

template <typename T>
bool operator< (const Vertex<T> & v1, const Vertex<T> & v2)
{
	return v1.data < v2.data;
}

//need this to avoid linker errors for templates
#include "Vertex.cpp"

#endif