#pragma once
#include <iostream>

using namespace std;
const int DEF_SIZE = 128;
const int RESIZE_FACTOR = 2;

template <typename T>
class TripleArrayTree {
private:
	T* dataArray;
	int* leftLeafArray;
	int* rightLeafArray;
	int size;
	int capacity;

	bool full();
	void copy(T const*, int const*, int const*);
	void copy3(TripleArrayTree<T> const&);
	void erase3();
	void upsize();
	void downsize();//useless. no item deletion
	void pr(int);
	void create3Array3(int);
public:
	TripleArrayTree();
	TripleArrayTree(TripleArrayTree<T> const&);
	TripleArrayTree& operator=(TripleArrayTree<T> const&);
	~TripleArrayTree();

	bool empty();
	void print();
	void create();
};

