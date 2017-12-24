#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class SQueue {
private:
	stack<T> mainStack;
	stack<T> auxStack;
public:
	SQueue() {};
	~SQueue() {};

	void enqueue(T data) {
		while (!mainStack.empty()) {
			auxStack.push(mainStack.top());
			mainStack.pop();
		}

		mainStack.push(data);

		while (!auxStack.empty()) {
			mainStack.push(auxStack.top());
			auxStack.pop();
		}
	}

	T dequeue() {
		T result = front();
		if (!mainStack.empty())mainStack.pop();
		return result;
	}

	T front() {
		if (!mainStack.empty())return mainStack.top();
		else return 0;
	}
};

int main() {
	double numberOfQueries;
	cin >> numberOfQueries;
	SQueue<int> taskQueue;

	for (double i = 0; i < numberOfQueries; i++) {
		int input;
		cin >> input;
		switch (input) {
		case 1: cin >> input; taskQueue.enqueue(input); break;
		case 2: taskQueue.dequeue(); break;
		case 3: cout << taskQueue.front() << endl; break;
		}
		//cin.ignore(INT_MAX);
	}

	return 0;
}