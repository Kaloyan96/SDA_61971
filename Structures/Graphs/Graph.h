#pragma once
#include "LinkedList.cpp"

template<typename T>
class Graph{
private:
	LinkedList<LinkedList<T>> graph;
public:
	Graph();
	~Graph();

	Node<T>* getPoint(T, Graph<T> &);
	Node<T>* getPoint(T, LinkedList<LinkedList<T>> &);

	void addPoint(T, Graph<T> &);
	void addPoint(T, LinkedList<LinkedList<T>> &);

	void addRib(T, T, Graph<T> &);
	void addRib(T, T, LinkedList<LinkedList<T>> &);

	void createGraph(Graph<T> &);
	void createGraph(LinkedList<LinkedList<T>> &);
};

