#include "stdafx.h"
#include "TripleArrayTree.h"

template <typename T>
bool TripleArrayTree<T>::full() {
	return size == capacity - 1;
}

template <typename T>
void TripleArrayTree<T>::copy(T const* targetDataArray, int const* targetLeftLeafArray, int const* targetRightLeafArray) {
	for (int i = 0; i < size; i++) {
		dataArray[i] = targetDataArray[i];
		leftLeafArray[i] = targetLeftLeafArray[i];
		rightLeafArray[i] = targetRightLeafArray[i];
	}
}

template <typename T>
void TripleArrayTree<T>::copy3(TripleArrayTree<T> const& target3) {
	size = target3.size;
	capcity = target3.capacity;
	dataArray = new T[capacity];
	leftLeafArray = new int[capacity];
	rightLeafArray = new int[capacity];
	copy(target3.dataArray, target3.leftLeafArray, target3.rightLeafArray);
}

template <typename T>
void TripleArrayTree<T>::erase3() {
	delete[] dataArray;
	delete[] leftLeafArray;
	delete[] rightLeafArray;
}

template <typename T>
void TripleArrayTree<T>::downsize() {
	T* oldDataArray = dataArray;
	int* oldLeftLeafArray = leftLeafArray;
	int* oldRightLeafArray = rightLeafArray;

	capacity /= RESIZE_FACTOR;
	dataArray = new T[capacity];
	leftLeafArray = new int[capacity];
	rightLeafArray = new int[capacity];

	copy(oldDataArray, oldLeftLeafArray, oldRightLeafArray);
	delete[] oldDataArray;
	delete[] oldLeftLeafArray;
	delete[] oldRightLeafArray;
}

template <typename T>
void TripleArrayTree<T>::upsize() {
	T* oldDataArray = dataArray;
	int* oldLeftLeafArray = leftLeafArray;
	int* oldRightLeafArray = rightLeafArray;

	capacity *= RESIZE_FACTOR;
	dataArray = new T[capacity];
	leftLeafArray = new int[capacity];
	rightLeafArray = new int[capacity];

	copy(oldDataArray, oldLeftLeafArray, oldRightLeafArray);
	delete[] oldDataArray;
	delete[] oldLeftLeafArray;
	delete[] oldRightLeafArray;
}

template <typename T>
void TripleArrayTree<T>::pr(int pos) {
	if (leftLeafArray[pos] != -1)pr(leftLeafArray[pos]);
	cout << dataArray[pos];
	if (rightLeafArray[pos] != -1)pr(rightLeafArray[pos]);
}

template <typename T>
void TripleArrayTree<T>::create3Array3(int pos) {
	T x;
	char c;
	cout << "root: ";
	cin >> x;

	if (full)upsize;
	dataArray[pos] = x;
	leftLeafArray[pos] = -1;
	rightLeafArray[pos] = -1;

	cout << "Left leaf of: " << x << "y/n? ";
	cin >> c;
	if (c == 'y') {
		leftLeafArray[pos] = size++;
		create3Array3(leftLeafArray[pos]);
	}

	cout << "Right leaf of: " << x << "y/n? ";
	cin >> c;
	if (c == 'y') {
		rightLeafArray[pos] = size++;
		create3Array3(rightLeafArray[pos]);
	}
}


template <typename T>
TripleArrayTree<T>::TripleArrayTree(){
	size = 0;
	capacity = DEF_SIZE;
	dataArray = new T[capacity];
	leftLeafArray = new int[capacity];
	rightLeafArray = new int[capacity];
}

template <typename T>
TripleArrayTree<T>::TripleArrayTree(TripleArrayTree<T> const& targetTree) {
	copy3(targetTree);
}

template <typename T>
TripleArrayTree<T>& TripleArrayTree<T>::operator=(TripleArrayTree<T> const& targetTree) {
	if (this != *targetTree) {
		erase3();
		copy3(targetTree);
	}
	return *this;
}

template <typename T>
TripleArrayTree<T>::~TripleArrayTree(){
	erase3();
}


template <typename T>
bool TripleArrayTree<T>::empty() {
	return size == 0;
}

template <typename T>
void TripleArrayTree<T>::print() {
	pr(0);
	cout << endl;
}

template <typename T>
void TripleArrayTree<T>::create() {
	create3Array3(0);
}
