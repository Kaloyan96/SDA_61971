#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node<T> *left, *right;
};

template <typename T>
class BinaryTree {
private:
	Node<T> *root;

	void deleteBin3(Node<T>* &)const;
	void copy(Node<T>* &,Node<T>* const&) const;
	void copyBin3(BinaryTree<T> const&);
	void pr(const Node<T>*) const;
	void createBin3(Node<T> *&)const;
public:
	BinaryTree();
	BinaryTree(BinaryTree<T> const&);
	BinaryTree& operator=(BinaryTree<T> const&);
	~BinaryTree();

	T rootData()const;
	Node<T>* getRoot();

	BinaryTree<T> leftBinTree() const;
	BinaryTree<T> rightBinTree() const;

	bool empty() const;
	void print() const;
	void create();
	void create3(T, BinaryTree<T>, BinaryTree<T>);
};
