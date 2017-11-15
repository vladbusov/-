/*
Дан фрагмент последовательности скобок, состоящей из символов (){}[]. 
Требуется определить, возможно ли продолжить фрагмент в обе стороны,
 получив корректную последовательность. Длина исходной последовательности ≤ 800000.
Формат ввода
Строка, содержащая символы (){}[] и, возможно, перевод строки.
Формат вывода
Если возможно - вывести минимальную корректную 
последовательность, иначе - напечатать "IMPOSSIBLE".
*/
#include <iostream>
#include <assert.h> 
#include <string>

using namespace std;

template <class T>
class CStack {
private:
	int buffSize;
	T* buff;
public:
	int top;
	explicit CStack(int size = 1) {
		top = -1;
		buffSize = size;
		buff = new T[buffSize];
	}
	~CStack() {
		delete[] buff;
	}
	void push(T elem) {
		if (top + 1 == buffSize) {
			int newbuffSize=buffSize *2;
			T* tempBuff = new T[newbuffSize];
			for (int i = 0; i < buffSize; i++) tempBuff[i] = buff[i];
			delete[] buff;
			buffSize = newbuffSize;
			buff = tempBuff;			
		}
		++top;
		buff[top] = elem;

	}
	char pop() {
		assert(top != -1);
		return buff[top--];
	}
	bool isEmpty() {
		if (top == -1) return true;
		else return false;
	}
	int size() {
		return top+1;
	}
	void printStack(){
		int n = size();
		for (int i = 0; i < n; i++) {
			cout << pop();
		}
	}
	
};

bool checkStr(string str, CStack<char> *open, CStack<char> *close) {
	char temp;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
			switch (str[i]) {
			case '{':
				close->push('}');
				break;
			case '(':
				close->push(')');
				break;
			case '[':
				close->push(']');
				break;
			}
		}
		else {
			if (close->isEmpty()) {
				switch (str[i]) {
				case '}':
					open->push('{');
					break;
				case ')':
					open->push('(');
					break;
				case ']':
					open->push('[');
					break;
				}
			}
			else {
				temp = close->pop();
				if (temp != str[i]) {					
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	string str;
	CStack<char> open, close;
	cin >> str;
	if (checkStr(str,&open,&close)) {
		open.printStack();
		cout << str;
		close.printStack();
	}
	else cout << "IMPOSSIBLE";
	return 0;
}