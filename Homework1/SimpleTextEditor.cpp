// SimpleTextEditor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class TextEditor {
private:
	string text;
	stack<string> reverseMemory;
public:
	void append(string toAppend) {
		string newMemory;
		newMemory += "2";
		newMemory += to_string(toAppend.size());
		reverseMemory.push(newMemory);
		text += toAppend;
	}
	void deleet(int numOfChars) {//if I can't use delete then you'll no longer be 1337
		string newMemory;
		newMemory += "1";
		newMemory += text.substr(text.size() - numOfChars);//should get <numOfChars> last elements
		reverseMemory.push(newMemory);
		text = text.substr(0, text.size() - numOfChars);
	}
	void print(int pos) { 
		cout << text[pos-1] << endl; 
	}
	void undo() {
		if (reverseMemory.top()[0] == '1') {
			text += reverseMemory.top().substr(1);
			reverseMemory.pop();
		}
		else {
			text = text.substr(0, text.size() - stoi(reverseMemory.top().substr(1)));
			reverseMemory.pop();
		}
	}
};

int main(){
	string inputString;
	int numberOfQueries, input;
	TextEditor editor1;
	
	cin >> numberOfQueries;
	for (int i = 0; i < numberOfQueries; i++) {
		cin >> input;
		switch (input) {
		case 1: cin >> inputString; editor1.append(inputString); break;
		case 2: cin >> input; editor1.deleet(input); break;
		case 3: cin >> input; editor1.print(input); break;
		case 4: editor1.undo(); break;
		}
	}

	system("pause");
    return 0;
}

