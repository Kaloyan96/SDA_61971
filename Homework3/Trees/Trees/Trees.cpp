// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinaryTree.cpp"
#include <iostream>
#include <queue>

using namespace std;

const int LEAF_HEIGHT = 0;//Task requiers that a leaf has height of 0 not 1

template <typename T>
int height(Node<T>*);
template <typename T>
void printLevel(Node<T>*, int);
template <typename T>
void levelOrderTraversal(Node<T>*);
template <typename T>
int minBST(Node<T>*);
template <typename T>
int maxBST(Node<T>*);
template <typename T>
bool checkBSTaux(Node<T>*, int, int);
template <typename T>
bool checkBST(Node<T>*);
template <typename T>
Node<T>* lowestCommonAncestor(Node<T>*, int, int);
template <typename T>
Node<T>* lcaAux(Node<T>*, int, int);
template <typename T>
bool find(Node<T>*, int);
template <typename T>
queue<Node<T>*> findPath(Node<T>*, int);
template <typename T>
Node<T>* lcaDynamic(Node<T>*, int, int);
template <typename T>
Node<T>* lcaFinal(Node<T>*, int, int);
template <typename T>
void swapLevel(Node<T>*,int);
//---------------Exercise 1-------------------

//Task 1 is to create a binary tree. Check file BST.h

//Task 2
template <typename T>
int height(Node<T>* root) {
	if (!root) return LEAF_HEIGHT; 
	else return return max(height(root->left), height(root->right)) + 1;//Task requiers that a leaf has height of 0 not 1
}

//Task 3
template <typename T>
void printLevel(Node<T>* p, int level) {
	if (level == 0)cout << p->data;
	else {
		if (p->left)printLevel(p->left, level - 1);
		if (p->right)printLevel(p->right, level - 1);
	}
}

template <typename T>
void levelOrderTraversal(Node<T>* root) {
	int n = height(root);
	for (int i = 0; i <= n; i++)printLevel(root, i);
}

//Task 4
template <typename T>
int minBST(Node<T>* p) {
	if (!p->left) return p->data;
	else return minBST(p->left);
}

template <typename T>
int maxBST(Node<T>* p) {
	if (!p->right) return p->data;
	else return maxBST(p->right);
}

template <typename T>
bool checkBSTaux(Node<T>* p, int min, int max) {
	if (!p) return true;
	else if (p->data<min || p->data>max) return false;
	else return checkBSTaux(p->left, min, p->data - 1) &&
				checkBSTaux(p->right, p->data + 1, max);
}

template <typename T>
bool checkBST(Node<T>* p) {
	return checkBSTaux(p, minBST(p), maxBST(p));
}

//---------------Exercise 2-------------------

//Task 1
//Time should be logN * logN which is logN
template <typename T>
bool find(Node<T>* p, int val) {
	if (!p)return false;
	else if (p->data > val)return find(p->left, val);
	else if (p->data < val)return find(p->right, val);
	else return true;
}

template <typename T>
Node<T>* lcaAux(Node<T>* p, int lv, int rv) {
	if (find(p->left, lv) && find(p->left, rv)) return lcaAux(p->left, lv, rv);
	else if (find(p->right, lv) && find(p->right, rv)) return lcaAux(p->left, lv, rv);
	else return p;
}

template <typename T>
Node<T>* lowestCommonAncestor(Node<T>* root, int p1, int p2) {
	if (p1 < p2)return lcaAux(root, p1, p2);
	else return lcaAux(root, p2, p1);
}

//Task 1 with dynamic programing
template <typename T>
queue<Node<T>*> findPath(Node<T>* root, int val) {
	Node<T>* p = root;
	queue<Node<T>*> path;
	
	while(true){
		if (!p)break;
		else {
			path.push(p);
			if (p->data > val)p = p->left;
			else if (p->data < val)p = p->right;
			else break;
		}
	}
	return path;
}

template <typename T>
Node<T>* lcaDynamic(Node<T>* root, int v1, int v2) {
	queue<Node<T>*> path1 = findPath(root, v1);
	queue<Node<T>*> path2 = findPath(root, v2);
	Node<T>* res = NULL;

	while (path1.front() == path2.front()) {
		res = path1.front();
		path1.pop();
		path2.pop();
	}
	
	return res;
}
//Task 1 but with less idiocity
//Best speed(log N), constant memory
template <typename T>
Node<T>* lcaFinal(Node<T>* root, int v1, int v2) {
	Node<T>* p = root;

	while (p) {
		if (p->data > v1 && p->data > v2) p = p->left;
		else if (p->data < v1 && p->data < v2) p = p->right;
		else break;
	}

	return p;
}

//Task 2
template <typename T>
void swapLevel(Node<T>* p, int level) {
	if (level == 0) {
		Node<T>* temp = p->left;
		p->left = p->right;
		p->right = p->left;
	}
	else {
		if (p->left)swapLevel(p->left, level - 1);
		if (p->right)swapLevel(p->right, level - 1);
	}
}

int main()
{
    return 0;
}

