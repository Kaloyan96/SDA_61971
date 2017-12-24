#pragma once
#include <iostream>

using namespace std;
const int DEF_SIZE = 128;
const int RESIZE_FACTOR = 2;

template <typename T>
struct Node {
	T data;
	int parentIndex;
};

template <typename T>
class ParentalLinkTree {
private:
	Node<T>* dataArray;
	int size;
	int capacity;

	bool full();
	void copy(Node<T> const*);
	void copyPLT(ParentalLinkTree<T> const&);
	void erasePLT();
	void upsize();
	void pr(int);
	void createPLT(int);
public:
	ParentalLinkTree();
	ParentalLinkTree(ParentalLinkTree<T> const&);
	ParentalLinkTree& operator=(ParentalLinkTree<T> const&);
	~ParentalLinkTree();

	bool empty();
	void print();
	void create();
};