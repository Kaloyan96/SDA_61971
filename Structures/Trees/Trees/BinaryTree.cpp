#include "stdafx.h"
#include "BinaryTree.h"

template <typename T>
void BinaryTree<T>::deleteBin3(Node<T>* &p) const{
	if (p) {
		deleteBin3(p->left);
		deleteBin3(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void BinaryTree<T>::copy(Node<T>* &targetNode, Node<T>* const& originNode) const {
	targetNode = NULL;
	if (originNode) {
		targetNode = new Node<T>;
		targetNode->data = originNode->data;
		copy(targetNode->left, originNode->left);
		copy(targetNode->right, originNode->right);
	}
}

template <typename T>
void BinaryTree<T>::copyBin3(BinaryTree<T> const& targetTree) {
	copy(root, targetTree.root);
}

template <typename T>
void BinaryTree<T>::pr(const Node<T>* activeNode) const {
	if (activeNode) {
		pr(activeNode->left);
		cout << activeNode -> data << " ";
		pr(activeNode->right);
	}
}

template <typename T>
void BinaryTree<T>::createBin3(Node<T> *&activeNode)const {
	T x;
	char c;
	cout << "root: ";
	cin >> x;

	activeNode = new Node<T>;
	activeNode->data = x;
	activeNode->left = NULL;
	activeNode->right = NULL;

	cout << "left BinTree of: " << x << "y/n? ";
	cin >> c;
	if (c == 'y')createBin3(activeNode->left);

	cout << "left BinTree of: " << x << "y/n? ";
	cin >> c;
	if (c == 'y')createBin3(activeNode->right);
}



template <typename T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> const& originTree) {
	copyBin3(originTree);
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> const& originTree) {
	if (this != &originTree) {
		deleteBin3(root);
		copyBin3(originTree);
	}
	return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	deleteBinTree(root);
}



template <typename T>
T BinaryTree<T>::rootData()const {
	return root->data;
}

template <typename T>
Node<T>* BinaryTree<T>::getRoot() {
	return root;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::leftBinTree() const {
	BinaryTree<T> t;
	copy(t.root, root->left);
	return t;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::rightBinTree() const {
	BinaryTree<T> t;
	copy(t.root, root->right);
	return t;
}

template <typename T>
bool BinaryTree<T>::empty() const {
	return p == NULL;
}

template <typename T>
void BinaryTree<T>::print() const {
	pr(root);
	//cout << endl;
}

template <typename T>
void BinaryTree<T>::create() {
	createBin3(root);
}

template <typename T>
void BinaryTree<T>::create3(T data, BinaryTree<T> leftTree, BinaryTree<T> rightTree) {
	root = new Node<T>;
	root->data = data;
	copy(root->left, leftTree.root);
	copy(root->right, rightTree.root);
}