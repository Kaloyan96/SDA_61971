// Fall Rot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Matrix {//I fraking hate 2d arrays
private:
	int* arr;
	int rows;
	int columns;
public:
	Matrix() {};
	Matrix(int rows, int columns) {
		this->rows = rows;
		this->columns = columns;
		arr = new int[rows*columns];
	};

	void set(int x, int y, int value) { arr[x*rows + y] = value; }
	int at(int x, int y){return arr[x*rows + y]; }
	int getRows() { return rows; }
	int getColumns() { return columns; }
	bool exists(int x, int y) {
		if (x >= 0 && y >= 0 && x < getRows() && y < getColumns()) return true;
		else return false;
	}
};

bool update(Matrix* targetMatrix, int x, int y) {
	if ((targetMatrix->exists(x - 1, y) && targetMatrix->at(x - 1, y) == 2) ||
		(targetMatrix->exists(x + 1, y) && targetMatrix->at(x + 1, y) == 2) ||
		(targetMatrix->exists(x, y + 1) && targetMatrix->at(x, y + 1) == 2) ||
		(targetMatrix->exists(x, y - 1) && targetMatrix->at(x, y - 1) == 2)){
		targetMatrix->set(x, y, 2);
		return true;
	}
	else return false;
}

int doStuff(Matrix* targetMatrix) {
	bool invariancy = true;//if at end of cycle invariancy is flase means no change happened so cycle solhsd break
	int result = 0;
	int n = targetMatrix->getRows();
	int m = targetMatrix->getColumns();
	while (invariancy) {
		invariancy = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (targetMatrix->at(i, j) == 1) {
					invariancy = invariancy || update(targetMatrix, i, j);
				}
			}
		}
		result++;
	}
	
	return result;
}

int main()
{
	Matrix asdfgh(5, 5);

    return 0;
}

