// Fibonacci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int exponential(int targetNumber) {
	if (targetNumber < 3)return 1;//targetNumber==3 return 2;
	else return exponential(targetNumber - 1) + exponential(targetNumber - 2);
}


int linearIteration(int targetNumber, int currentNumber, int accumulatorAlpha, int accumulatorBravo) {
	if (targetNumber == currentNumber)return accumulatorAlpha + accumulatorBravo;//change if parametres if nescessery
	else return linearIteration(targetNumber, currentNumber + 1, accumulatorAlpha + accumulatorBravo, accumulatorAlpha);
}

int linear(int targetNumber) {
	if (targetNumber < 3)return 1;//targetNumber==3 return 2;
	return linearIteration(targetNumber, 3, 1, 1);//tweak starting parametres
}


void matrixMultiplier(int** matrixAlpha, int** matrixBravo) {
	int c00, c01, c10, c11;
	c00 = matrixAlpha[0][0] * matrixBravo[0][0] + matrixAlpha[0][1] * matrixBravo[1][0];
	c01 = matrixAlpha[0][0] * matrixBravo[0][1] + matrixAlpha[0][1] * matrixBravo[1][1];
	c10 = matrixAlpha[1][0] * matrixBravo[0][0] + matrixAlpha[1][1] * matrixBravo[1][0];
	c11 = matrixAlpha[1][0] * matrixBravo[0][1] + matrixAlpha[1][1] * matrixBravo[1][1];

	matrixAlpha[0][0] = c00;
	matrixAlpha[0][1] = c01;
	matrixAlpha[1][0] = c10;
	matrixAlpha[1][1] = c11;
}

void matrixPower(int** targetMatrix, int power) {
	if (power == 0 || power == 1)
		return;
	int** auxMatrix = new int*;
	auxMatrix[0] = new int[2];
	auxMatrix[1] = new int[2];

	auxMatrix[0][0] = 1;
	auxMatrix[0][1] = 1;
	auxMatrix[1][0] = 1;
	auxMatrix[1][1] = 0;

	matrixPower(targetMatrix, power / 2);
	matrixMultiplier(targetMatrix, targetMatrix);

	if (power % 2 != 0) {
		matrixMultiplier(targetMatrix, auxMatrix);
	}
}

int logarithmic(int targetNumber) {
	if (targetNumber == 0)return 0;
	if (targetNumber < 3)return 1;

	//int mainMatrix[2][2] = { {1,1},{1,0} };
	int** mainMatrix = new int*;
	mainMatrix[0] = new int[2];
	mainMatrix[1] = new int[2];

	mainMatrix[0][0] = 1;
	mainMatrix[0][1] = 1;
	mainMatrix[1][0] = 1;
	mainMatrix[1][1] = 0;

	matrixPower(mainMatrix, targetNumber - 1);
	return mainMatrix[0][0];
}


int main(){
	cout << "Choose function:\n1: Full recursion\n2: Tail recursion\n3: Matrix power\n";
	int input;
	cin >> input;
	switch (input) {
	case 1:cin >> input; cout << "The number is: " << exponential(input) << endl; break;
	case 2:cin >> input; cout << "The number is: " << linear(input) << endl; break;
	case 3:cin >> input; cout << "The number is: " << logarithmic(input) << endl; break;
	}
	system("pause");
    return 0;
}

