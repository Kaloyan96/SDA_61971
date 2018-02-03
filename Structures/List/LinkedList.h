#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T>* next;
};

template <typename T>
class LinkedList{
private:
	Node<T>* start;
	Node<T>* end;
	Node<T>* current;

	void deleteList();
	void copyList(LinkedList<T> const&);
public:
	LinkedList();
	LinkedList(LinkedList<T> const&);
	LinkedList& operator= (LinkedList<T> const&);
	~LinkedList();

	void iterStart(Node<T> *p = NULL);
	Node<T>* iterate();

	void pushToEnd(T const&);
	void insertAfter(Node<T>*, T const &);
	void insertBefore(Node<T>*, T const &);

	bool deleteAfter(Node<T>*, T &);
	bool deleteBefore(Node<T>*, T &);
	void deleteTarget(Node<T>*, T &);

	bool hasElement(T const&);
	void print();
	int length();
	void concat(LinkedList<T> const&);
};
