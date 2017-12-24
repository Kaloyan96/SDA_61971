#include "stdafx.h"
#include "ParentalLinkTree.h"

template <typename T>
bool ParentalLinkTree<T>::full() {
	return size == capacity - 1;
}

template <typename T>
void ParentalLinkTree<T>::copy(Node<T> const* targetDataArray) {
	for (int i = 0; i < size; i++) {
		dataArray[i] = targetDataArray[i];
	}
}

template <typename T>
void ParentalLinkTree<T>::copyPLT(ParentalLinkTree<T> const& targetTree) {
	size = targetTree.size;
	capcity = targetTree.capacity;
	dataArray = new Node<T>[capacity];
	copy(targetTree.dataArray);
}

template <typename T>
void ParentalLinkTree<T>::erasePLT() {
	delete[] dataArray;
}

template <typename T>
void ParentalLinkTree<T>::upsize() {
	Node<T>* oldDataArray = dataArray;

	capacity *= RESIZE_FACTOR;
	dataArray = new Node<T>[capacity];

	copy(oldDataArray);
	delete[] oldDataArray;
}

template <typename T>
void ParentalLinkTree<T>::pr(int pos) {//output is <root-child-child> since there is no left or right
	cout << dataArray[pos]->data;
	for (int i = 0; i < size; i++) {
		if (dataArray[i]->parrentIndex == pos)pr(dataArray[i]->parrentIndex);
	}
}

template <typename T>
void ParentalLinkTree<T>::createPLT(int pos) {
	T x;
	char c;
	cout << "root: ";
	cin >> x;

	if (full)upsize;
	dataArray[pos]->data = x;

	do {
		cout << "Add child to: " << x << "y/n? ";
		cin >> c;
		if (c == 'y') {
			dataArray[size]->parentIndex = pos;
			size++;
			createPLT(size - 1);
		}
	} while (c != 'n');
}


template <typename T>
ParentalLinkTree<T>::ParentalLinkTree() {
	size = 0;
	capacity = DEF_SIZE;
	dataArray = new Node<T>[capacity];
}

template <typename T>
ParentalLinkTree<T>::ParentalLinkTree(ParentalLinkTree<T> const& targetTree) {
	copyPLT(targetTree);
}

template <typename T>
ParentalLinkTree<T>& ParentalLinkTree<T>::operator=(ParentalLinkTree<T> const& targetTree) {
	if (this != *targetTree) {
		erasePLT();
		copyPLT(targetTree);
	}
	return *this;
}

template <typename T>
ParentalLinkTree<T>::~ParentalLinkTree() {
	erasePLT();
}


template <typename T>
bool ParentalLinkTree<T>::empty() {
	return size == 0;
}

template <typename T>
void ParentalLinkTree<T>::print() {
	pr(0);
	cout << endl;
}

template <typename T>
void ParentalLinkTree<T>::create() {
	createPLT(0);
}
