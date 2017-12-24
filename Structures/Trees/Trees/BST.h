#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right;
};

template <typename T>
class BST {
private:
	Node<T> *root;

	void deleteBST(Node<T>* &)const;
	void copy(Node<T>* &, Node<T>* const&) const;
	void copyBST(BST<T> const&);
	void pr(const Node<T>*) const;
	void add(Node<T> *&,T const&)const;
public:
	BST();
	BST(BST<T> const&);
	BST& operator=(BST<T> const&);
	~BST();

	T rootData()const;
	Node<T>* getRoot();

	void addNode(T const&);
	void deleteNode(T const&);

	BST<T> leftBinTree() const;
	BST<T> rightBinTree() const;

	bool empty() const;
	void print() const;
	void create();
	void create3(T, BST<T>, BST<T>);

	void minTree(T &, BST<T> &)const;
};

