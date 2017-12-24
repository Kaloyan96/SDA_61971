// MaxInStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;


int maxElement(stack<int> &targetStack) {
	stack<int> auxStack;
	int max = 0;
	while (!targetStack.empty()) {
		if (max < targetStack.top())max = targetStack.top();
		auxStack.push(targetStack.top());
		targetStack.pop();
	}

	while (!auxStack.empty()) {
		targetStack.push(auxStack.top());
		auxStack.pop();
	}

	return max;
}


int main(){
	int input, numberOfQueries;
	stack<int> mainStack;
	cin >> numberOfQueries;
	for (int i = 0; i < numberOfQueries; i++) {
		cin >> input;
		switch (input) {
		case 1: cin >> input; mainStack.push(input); break;
		case 2: mainStack.pop(); break;
		case 3: cout << maxElement(mainStack) << endl; break;
		}
	}

    return 0;
}

