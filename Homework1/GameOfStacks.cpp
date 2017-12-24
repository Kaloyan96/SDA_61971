// GameOfStacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <iostream>

using namespace std;

void removeOneOfAlphas(stack<int> &elementsFromAlpha, int &sum, int& score) {
	if (!elementsFromAlpha.empty()) {
		sum -= elementsFromAlpha.top();
		elementsFromAlpha.pop();
		score--;
	}
}

int biggerOfTwo(int first, int second) {
	if (first > second)return first;
	else return second;
}

void initStack(stack<int> &sourceStack, stack<int> &scoreStack, int &sum, int &score, int limit) {
	while (!sourceStack.empty() && sourceStack.top() + sum < limit) {
		sum += sourceStack.top();
		scoreStack.push(sourceStack.top());
		sourceStack.pop();
		score++;
	}
}

void saturateScore(stack<int> &sourceStack, int &sum, int &score, int limit) {
	while (!sourceStack.empty() && sourceStack.top() + sum < limit) {
		sum += sourceStack.top();
		sourceStack.pop();
		score++;
	}
}


int playTheGame(stack<int> stackAlpha, stack<int> stackBravo, int limit) {//might be doable with a "greedy" algorythm
	//nope. It's not doable with a greedy algorythm.
	stack<int> elementsFromAlpha;//size of auxStack is NOT current score
	int sum = 0, score = 0, maxScore = 0;

	initStack(stackAlpha, elementsFromAlpha, sum, score, limit);
	saturateScore(stackBravo, sum, score, limit);

	maxScore = biggerOfTwo(score, maxScore);

	while (!elementsFromAlpha.empty()) {
		removeOneOfAlphas(elementsFromAlpha, sum, score);

		saturateScore(stackBravo, sum, score, limit);
		maxScore = biggerOfTwo(score, maxScore);
	}

	return maxScore;
}

void fillStack(stack<int> &targetStack, int stackSize) {
	stack<int> reverseStack;

	for (int i = 0; i < stackSize; i++) {
		int input;
		cin >> input;
		reverseStack.push(input);
	}
	for (int i = 0; i < stackSize; i++) {
		targetStack.push(reverseStack.top());
		reverseStack.pop();
	}
}

int main() {
	int numberOfGames;
	cin >> numberOfGames;
	int* gameResults = new int[numberOfGames];
	for (int gameIterator = 0; gameIterator < numberOfGames; gameIterator++) {
		int stackAlphaSize, stackBravoSize, limit;
		stack<int> inputStack, stackAlpha, stackBravo;
		cin >> stackAlphaSize >> stackBravoSize >> limit;

		fillStack(stackAlpha, stackAlphaSize);
		fillStack(stackBravo, stackBravoSize);

		gameResults[gameIterator] = playTheGame(stackAlpha, stackBravo, limit);
	}

	for (int i = 0; i < numberOfGames; i++) {
		cout << gameResults[i] << endl;
	}
		
	return 0;
}