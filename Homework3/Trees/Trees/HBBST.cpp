#include "stdafx.h"
#include "HBBST.h"

template <typename T>
void HBBST<T>::deleteHBBST(Node<T>* &p) const {
	if (p) {
		deleteHBBST(p->left);
		deleteHBBST(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
void HBBST<T>::copy(Node<T>* &targetNode, Node<T>* const& originNode) const {
	targetNode = NULL;
	if (originNode) {
		targetNode = new Node<T>;
		targetNode->data = originNode->data;
		targetNode->height = originNode->height;
		copy(targetNode->left, originNode->left);
		copy(targetNode->right, originNode->right);
	}
}

template <typename T>
void HBBST<T>::copyHBBST(HBBST<T> const& targetTree) {
	copy(root, targetTree.root);
}

template <typename T>
void HBBST<T>::pr(const Node<T>* activeNode) const {
	if (activeNode) {
		pr(activeNode->left);
		cout << activeNode->data << " ";
		pr(activeNode->right);
	}
}

template <typename T>
void HBBST<T>::add(Node<T>* &p, T const& x)const {
	if (!p) {
		p = new Node<T>;
		p->data = x;
		p->height = 0;
		p->left = NULL;
		p->right = NULL;
	}
	else if (x < p->data) {
		add(p->left, x);
	}
	else {
		add(p->right, x);
	}
	calculateHeight(p);
	calculateBalance(p);
	rotationCogitator(p);
}

template <typename T>
int HBBST<T>::calculateHeight(Node<T>* const& p) const {
	if (p->right && p->left) p->height = max(calculateHeight(p->left), calculateHeight(p->right)) + 1;
	else if (p->right) p->height = p->right->height + 1;
	else if (p->left) p->left = p->left->height + 1;
	else p->height = 1;
	return p->height;
}

template <typename T>
int HBBST<T>::calculateBalance(Node<T>* const& p) const {
	if (p->right && p->left) res = p->right->height - p->left->height;
	else if (p->right) res = p->right->height;
	else if (p->left) res = - p->left->height;
	else p->balance = 0;
	return p->balance;
}

template <typename T>
void HBBST<T>::rotationCogitator(Node<T>* &p) {
	if (p->balance > 1) {
		if (p->right->balance > 0) rotateLeft(p);
		else if (p->right->balnce < 0) rotateRightLeft(p);
		else return;//this should be an unreachable block. IF it is reached then there is a calculation error somewhere
	}
	else if (p->balance < 1) {
		if (p->left->balance < 0) rotateRight(p);
		else if (p->left->balnce > 0) rotateLeftRight(p);
		else return;//this should be an unreachable block. IF it is reached then there is a calculation error somewhere
	}
}

template <typename T>
void HBBST<T>::rotateLeft(Node<T>* &p) {
	Node<T>* b;
	Node<T>* t;
	b = p->right;
	t = NULL;
	if (b)t = b->left;

	p->right = t;
	calculateBalance(p);

	b->left = p;
	calculateBalance(p);
	p = b;//might disapear at function call end
}

template <typename T>
void HBBST<T>::rotateRight(Node<T>* &p) {
	Node<T>* b;
	Node<T>* t;
	b = p->left;
	t = NULL;
	if (b)t = b->right;

	p->left = t;
	calculateBalance(p);

	b->right = p;
	calculateBalance(p);
	p = b;//might disapear at function call end
}

template <typename T>
void HBBST<T>::rotateLeftRight(Node<T>* &p) {//could be way too wrong
	rotateLeft(p->left);
	rotateRight(p);//mainly by this line
}

template <typename T>
void HBBST<T>::rotateRightLeft(Node<T>* &p) {//could be way too wrong
	rotateRight(p->right);
	rotateLeft(p);//mainly by this line
}



template <typename T>
HBBST<T>::HBBST() {
	root = NULL;
}

template <typename T>
HBBST<T>::HBBST(HBBST<T> const& originTree) {
	copyHBBST(originTree);
}

template <typename T>
HBBST<T>& HBBST<T>::operator=(HBBST<T> const& originTree) {
	if (this != &originTree) {
		deleteHBBST(root);
		copyHBBST(originTree);
	}
	return *this;
}

template <typename T>
HBBST<T>::~HBBST() {
	deleteBinTree(root);
}



template <typename T>
T HBBST<T>::rootData()const {
	return root->data;
}

template <typename T>
Node<T>* HBBST<T>::getRoot() {
	return root;
}

template <typename T>
void HBBST<T>::addNode(T const& x) {
	add(root, x);
}

template <typename T>
void HBBST<T>::deleteNode(T const& x) {
	if (root) {
		T a = rootData;
		HBBST<T> t;

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
		calculateHeight(p);
		calculateBalance(p);
		rotationCogitator(p);//honestly I jave no point what I am doing at this idea
	}
}

template <typename T>
HBBST<T> HBBST<T>::leftBinTree() const {
	HBBST<T> t;
	copy(t.root, root->left);
	return t;
}

template <typename T>
HBBST<T> HBBST<T>::rightBinTree() const {
	HBBST<T> t;
	copy(t.root, root->right);
	return t;
}

template <typename T>
bool HBBST<T>::empty() const {
	return p == NULL;
}

template <typename T>
void HBBST<T>::print() const {
	pr(root);
	//cout << endl;
}

template <typename T>
void HBBST<T>::create() {
	createBin3(root);
}

template <typename T>
void HBBST<T>::create3(T data, HBBST<T> leftTree, HBBST<T> rightTree) {
	root = new Node<T>;
	root->data = data;
	copy(root->left, leftTree.root);
	copy(root->right, rightTree.root);
}

template <typename T>
void HBBST<T>::minTree(T &x, HBBST<T> &mint)const {
	T a = rootData;
	if (!root->left) {
		x = a;
		mint = rightTree();
	}
	else {
		HBBST<T> t;
		leftTree().minTree(x, t);
		mint.create3(a, t, rightTree());
	}
}