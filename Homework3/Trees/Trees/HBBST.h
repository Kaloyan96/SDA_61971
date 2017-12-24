#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	int height;
	Node<T> *left, *right;
};

template <typename T>
class HBBST {//Height balanced tree
private:
	Node<T> *root;

	void deleteHBBST(Node<T>* &)const;
	void copy(Node<T>* &, Node<T>* const&) const;
	void copyHBBST(HBBST<T> const&);
	void pr(const Node<T>*) const;
	void add(Node<T> *&, T const&)const;

	int calculateHeight(Node<T>* const&) const;
	int calculateBalance(Node<T>* const&) const;

	void rotationCogitator(Node<T>* &);

	void rotateLeft(Node<T>* &);
	void rotateRight(Node<T>* &);
	void rotateLeftRight(Node<T>* &);
	void rotateRightLeft(Node<T>* &);
public:
	HBBST();
	HBBST(HBBST<T> const&);
	HBBST& operator=(HBBST<T> const&);
	~HBBST();

	T rootData()const;
	Node<T>* getRoot();

	void addNode(T const&);
	void deleteNode(T const&);

	HBBST<T> leftBinTree() const;
	HBBST<T> rightBinTree() const;

	bool empty() const;
	void print() const;
	void create();
	void create3(T, HBBST<T>, HBBST<T>);

	void minTree(T &, HBBST<T> &)const;
};