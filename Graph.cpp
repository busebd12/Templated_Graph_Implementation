#include "Graph.h"
using namespace std;

template <typename T>
Graph<T>::Graph():numberOfElements(0) {}

template <typename T>
void Graph<T>::addVertexPair(const T& Data, const T& AdjacentData)
{
	Vertex<T> vertex;

	vertex.setData(Data);

	Vertex<T> adjacentVertex;

	adjacentVertex.setData(AdjacentData);

	//insert the vertex and its adjacent vertex
	adjacencyList[vertex].emplace_back(adjacentVertex);

	//insert the adjacent vertex as its own vertex
	adjacencyList[adjacentVertex];
}

template <typename T>
void Graph<T>::depthFirstTraversal()
{
	vector<Vertex<T>> visitedNodes;

	map<Vertex<T>, bool> visited; 

	//map all vertices to false since we have not looked at them yet
	for(const auto & vertex : adjacencyList)
	{
		visited.insert(make_pair(vertex.first.getData(), false));
	}

	stack<Vertex<T>> S;

	//pick our starting vertex for depth first traversal
	auto startingVertex=adjacencyList.begin()->first;

	S.push(startingVertex);

	while(!S.empty())
	{
		auto topVertex=S.top();

		//cout << "Looking at vertex " << S.top().getData() << endl;

		//cout << endl;

		S.pop();

		//if we haven't visited the vertex yet
		if(visited[topVertex.getData()]==false)
		{
			//mark it as visited
			visited[topVertex.getData()]=true;

			//add it to the discovered vertices vector
			visitedNodes.emplace_back(topVertex);

			//get all the adjacent vertices to the vertex we are looking at and store them in a vector
			auto adjacentVertices=adjacencyList.at(topVertex);

			//go through adjacent vertices and add them to the stack since we haven't visited them yet
			for(const auto & vertex : adjacentVertices)
			{
				//cout << "Adding adjacent vertex " << adjacentVertices.at(i).getData() << " to the stack" << endl;

				//cout << endl;

				S.push(vertex);
			}
		}
	}

	cout << "Depth first traversal of the graph:" << endl;

	for(const auto & vertex : visitedNodes)
	{
		cout << vertex.getData() << " ";
	}
	cout << endl;
}

template <typename T>
void Graph<T>::breadthFirstTraversal()
{
	int x=0; 

	vector<Vertex<T>> visitedNodes;

	map<Vertex<T>, bool> visited;

	//map all vertices to false since we haven't visited them yet
	for(const auto & vertex : adjacencyList)
	{
		visited.insert(make_pair(vertex.first.getData(), false));
	}

	queue<Vertex<T>> Q;

	//pick our starting vertex for depth first search
	auto startingVertex=adjacencyList.begin()->first;

	//visit the starting vertex
	visited[startingVertex.getData()]=true;

	//add to queue so that we can explore its adjacent vertices
	Q.push(startingVertex);

	while(!Q.empty())
	{
		auto headVertex=Q.front();

		//cout << "Looking at vertex " << headVertex.getData() << endl;

		//cout << endl;

		visitedNodes.emplace_back(headVertex);

		//get the adjacent vertices for the vertex we are currently looking at
		auto adjacentVertices=adjacencyList.at(headVertex.getData());

		//remove the vertex we were just looking at
		Q.pop();

		//go through all adjacent vertices
		for(auto & vertex : adjacentVertices)
		{	
			//if we haven't visited the vertex
			if(visited[vertex.getData()]==false)
			{
				//mark it as visited
				visited[vertex.getData()]=true;

				//cout << "Adding vertex " << vertex.getData() << " to the queue" << endl;

				//cout << endl;

				//add the vertex to the queue so we can explore it later
				Q.push(vertex);
			}
		}
	}

	cout << "Breadth first traversal of the graph:" << endl;

	for(const auto & vertex : visitedNodes)
	{
		cout << vertex.getData() << " ";
	}
	cout << endl;
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
	return adjacencyList.size();
}