#pragma once
#include "LinkedList.cpp"

template<typename T>
class Graph {
private:
	LinkedList<LinkedList<T>> graph;
public:
	Graph();
	~Graph();

	Node<T>* getVertex(T, Graph<T> &);
	Node<T>* getVertex(T, LinkedList<LinkedList<T>> &);

	void addVertex(T, Graph<T> &);
	void addVertex(T, LinkedList<LinkedList<T>> &);

	void addEdge(T, T, Graph<T> &);
	void addEdge(T, T, LinkedList<LinkedList<T>> &);
	void addDoubleEdge(T, T, Graph<T> &);
};
