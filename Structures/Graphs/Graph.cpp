#include "Graph.h"

template<typename T>
Node<T>* Graph<T>::getVertex(T targetPoint, Graph<T> &g) {
	getPoint(T targetPoint, g.graph);
}

template<typename T>
Node<T>* Graph<T>::getVertex(T targetPoint, LinkedList<LinkedList<T>> &g) {
	g.iterStart();
	Node<LinkedList<T>> *p;
	Node<T> *q;
	do {
		p = g.iterate();
		p->data.iterStart();
		q = p->data.iter();
	} while (q->data != targetPoint);
	return q;
}

template<typename T>
void Graph<T>::addVertex(T newData, Graph<T> &g) {
	addVertex(newData, g.graph);
}

template<typename T>
void Graph<T>::addVertex(T newData, LinkedList<LinkedList<T>> &g) {
	LinkedList<T> l;
	l.pushToEnd(newData);
	g.pushToEnd(l);
}

template<typename T>
void Graph<T>::addEdge(T from, T to, Graph<T> &g) {
	addEdge(from, to, g.graph);
}

template<typename T>
void Graph<T>::addEdge(T from, T to, LinkedList<LinkedList<T>> &g) {
	Node<T>* q = new Node<T>;
	q->data = to;
	q->next = NULL;

	Node<T>* iter = getVertex(from, g);
	while (iter->next)iter = iter->next;
	iter->next = q;
}

template<typename T>
void Graph<T>::addDoubleEdge(T from, T to, Graph<T> &g) {
	addEdge(from, to, g.graph);
	addEdge(to, from, g.graph);
}

