#include <iostream>
#include <vector>
using namespace std;

typedef struct Stack {
	vector<int> v;
	int top;
	int size;
} Stack;

void Init(Stack& S, int size) {
	S.v.resize(size);
	S.top = -1;
	S.size = size;
}

bool EmptyStack(const Stack& S) {
	return S.top == -1;
}

void Push(Stack& S, int x) {
	if (S.top + 1 == S.size)	{
		cout << "Overflow! The stack is full" << endl;
		return;
	}
	S.v[++S.top] = x;
}

int Pop(Stack& S) {
	if (S.top == -1) {
		cout << "Underflow! The stack is empty!" << endl;
		return 0;
	}
	return S.v[S.top--];
}

void PrintStack(const Stack& S) {
	for (int i = 0; i <= S.top; ++i) {
		cout << S.v[i] << " ";
	}
	cout << endl;
}

int main() {
	Stack S;
	Init(S, 10);
	Pop(S);
	Push(S, 4);
	PrintStack(S);
	Push(S, 1);
	PrintStack(S);
	Push(S, 3);
	PrintStack(S);
	Pop(S);
	PrintStack(S);
	Push(S, 8);
	PrintStack(S);
	Pop(S);
	PrintStack(S);
	return 0;
}
