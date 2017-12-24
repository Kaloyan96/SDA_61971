#include "stdafx.h"
#include "BST.h"

template <typename T>
void BST<T>::deleteBST(Node<T>* &p) const {
	if (p) {
		deleteBST(p->left);
		deleteBST(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void BST<T>::copy(Node<T>* &targetNode, Node<T>* const& originNode) const {
	targetNode = NULL;
	if (originNode) {
		targetNode = new Node<T>;
		targetNode->data = originNode->data;
		copy(targetNode->left, originNode->left);
		copy(targetNode->right, originNode->right);
	}
}

template <typename T>
void BST<T>::copyBST(BST<T> const& targetTree) {
	copy(root, targetTree.root);
}

template <typename T>
void BST<T>::pr(const Node<T>* activeNode) const {
	if (activeNode) {
		pr(activeNode->left);
		cout << activeNode->data << " ";
		pr(activeNode->right);
	}
}

template <typename T>
void BST<T>::add(Node<T>* &p, T const& x)const {
	if (!p) {
		p = new Node<T>;
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	else if (x < p->data)add(p->left, x);
	else add(p->right, x);
}



template <typename T>
BST<T>::BST() {
	root = NULL;
}

template <typename T>
BST<T>::BST(BST<T> const& originTree) {
	copyBST(originTree);
}

template <typename T>
BST<T>& BST<T>::operator=(BST<T> const& originTree) {
	if (this != &originTree) {
		deleteBST(root);
		copyBST(originTree);
	}
	return *this;
}

template <typename T>
BST<T>::~BST() {
	deleteBinTree(root);
}



template <typename T>
T BST<T>::rootData()const {
	return root->data;
}

template <typename T>
Node<T>* BST<T>::getRoot() {
	return root;
}

template <typename T>
void BST<T>::addNode(T const& x) {
	add(root, x);
}

template <typename T>
void BST<T>::deleteNode(T const& x) {
	if (root) {
		T a = rootData;
		BST<T> t;

		if (x < a) {
			t = *this;
			*this = leftTree();
			deleteNode(x);
			create3(a, *this, t.rightBinTree());
		}
		else if (x>a) {
			t = *this;
			*this = rightTree();
			deleteNode(x);
			create3(a, t.leftBinTree(), *this);
		}
		else if (x == a) {
			if (!root->left) *this = rightTree;
			else if (!root->right) *this = leftTree;
			else {
				T c;
				rightTree().minTree(c, t);
				create3(c, leftTree(), t);
			}
		}
	}
}

template <typename T>
BST<T> BST<T>::leftBinTree() const {
	BST<T> t;
	copy(t.root, root->left);
	return t;
}

template <typename T>
BST<T> BST<T>::rightBinTree() const {
	BST<T> t;
	copy(t.root, root->right);
	return t;
}

template <typename T>
bool BST<T>::empty() const {
	return p == NULL;
}

template <typename T>
void BST<T>::print() const {
	pr(root);
	//cout << endl;
}

template <typename T>
void BST<T>::create() {
	createBin3(root);
}

template <typename T>
void BST<T>::create3(T data, BST<T> leftTree, BST<T> rightTree) {
	root = new Node<T>;
	root->data = data;
	copy(root->left, leftTree.root);
	copy(root->right, rightTree.root);
}

template <typename T>
void BST<T>::minTree(T &x, BST<T> &mint)const {
	T a = rootData;
	if (!root->left) {
		x = a;
		mint = rightTree();
	}
	else {
		BST<T> t;
		leftTree().minTree(x, t);
		mint.create3(a, t, rightTree());
	}
}