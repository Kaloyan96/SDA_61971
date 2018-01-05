#include "Graph.h"

template<typename T>
Node<T>* Graph<T>::getPoint(T targetPoint, Graph<T> &g) {
	getPoint(T targetPoint, g.graph);
}

template<typename T>
Node<T>* Graph<T>::getPoint(T targetPoint, LinkedList<LinkedList<T>> &g) {
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
void Graph<T>::addPoint(T newData, Graph<T> &g) {
	addPoint(newData, g.graph);
}

template<typename T>
void Graph<T>::addPoint(T newData, LinkedList<LinkedList<T>> &g) {
	LinkedList<T> l;
	l.pushToEnd(newData);
	g.pushToEnd(l);
}

template<typename T>
void Graph<T>::addRib(T from, Graph<T> &g) {//YOU ARE HERE
	addRib(newData, g.graph);
}


