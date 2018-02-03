#include "LinkedList.h"

template<typename T>
void LinkedList<T>::deleteList() {
	Node<T> *p;
	while (start) {
		p = start;
		start = start->next;
		delete p;
	}
	end = NULL;
}

template<typename T>
void LinkedList<T>::copyList(LinkedList<T> const& sourceList) {
	start = end = NULL;
	if (sourceList.start) {
		Node<T>* p = sourceList.start;
		while (p) {
			pushToEnd(p->data);
			p = p->data;
		}
	}
}


template<typename T>
LinkedList<T>::LinkedList() {
	start = NULL;
	end = NULL;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> const& sourceList) {
	copyList(sourceList);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const& sourceList) {
	if (this != &sourceList) {
		deleteList();
		copyList(sourceList);
	}
	return *this;
}

template<typename T>
LinkedList<T>::~LinkedList<T>() {
	deleteList();
}



template<typename T>
void LinkedList<T>::iterStart(Node<T>* p) {
	if (p) current = p;
	else current = start;
}

template<typename T>
Node<T>* LinkedList<T>::iterate() {
	Node<T>* p = current;
	if (current) current = current->next;
	return p;
}

template<typename T>
void LinkedList<T>::pushToEnd(T const& x) {
	current = end;
	end = new Node<T>;
	end->data = x;
	end->next = NULL;
	if (current) current->next = end;
	else start = end;
}

template<typename T>
void LinkedList<T>::insertAfter(Node<T>* p, T const& x) {
	Node<T>* q = new Node<T>;
	q->data = x;
	q->next = p->next;

	if (p == end)end = q;
	p->next = q;
}

template<typename T>
void LinkedList<T>::insertBefore(Node<T>* p, T const& x) {
	Node<T>* q = new Node<T>;
	*q = *p;

	if (p == end)end = q;

	p->data = x;
	p->next = q;
}

template <typename T>
bool LinkedList<T>::deleteAfter(Node<T> *p, T & probe) {
	if (p->next) {
		Node<T>* q = p->next;
		probe = q->next;
		p->next = q->next;

		if (q == end)end = p;

		delete q;
		return 1;
	}

	return 0;
}

template <typename T>
void LinkedList<T>::deleteTarget(Node<T> *p, T & probe) {
	if (p == start) {
		probe = p->data;
		if (start == end) {
			start = end = NULL;
		}
		else start = start->next;

		delete p;
	}
	else {
		Node<T> *q = start;
		while (q->data != p) q = q->next;
		deleteAfter(q, probe);
	}
}

template<typename T>
bool LinkedList<T>::deleteBefore(Node<T>* p, T & probe) {
	if (p != start) {
		Node<T> *q = start;
		while (q->data != p) q = q->next;
		deleteTarget(q, probe);
		return 1;
	}

	return 0;
}

template<typename T>
void LinkedList<T>::print() {
	Node<T>* p = start;
	while (p) {
		std::cout << p->data << " ";
		p = p->next;
	}

	std::cout << std::endl;
}

template<typename T>
int LinkedList<T>::length() {
	int n = 0;
	Node<T>* p = start;
	while (p) {
		n++;
		p = p->next;
	}

	return n;
}

template<typename T>
void LinkedList<T>::concat(LinkedList<T> const & apendix) {
	Node<T> *p = apendix.start;
	while (p) {
		pushToEnd(p->data);
		p = p->next;
	}
}
