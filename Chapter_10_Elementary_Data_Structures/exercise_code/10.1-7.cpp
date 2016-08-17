#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Stack {
	queue<int> Q_1;
	queue<int> Q_2;
}Stack;

bool EmptyStack(const Stack& S) {
	return S.Q_1.empty() && S.Q_2.empty();
}

void Push(Stack& S, int x) {
	if (S.Q_1.empty()) {
		S.Q_1.push(x);
		while (!S.Q_2.empty()) {
			int temp = S.Q_2.front();
			S.Q_1.push(temp);
			S.Q_2.pop();
		}
	}
	else {
		S.Q_2.push(x);
		while (!S.Q_1.empty()) {
			int temp = S.Q_1.front();
			S.Q_2.push(temp);
			S.Q_1.pop();
		}
	}
}

int Pop(Stack& S) {
	if (EmptyStack(S)) {
		cout << "underflow!" << endl;
		return 0;
	}
	int x;
	if (S.Q_1.empty()) {
		x = S.Q_2.front();
		S.Q_2.pop();
	}
	else{
		x = S.Q_1.front();
		S.Q_1.pop();
	}
	return x;
}

int main() {
	Stack S;
	Push(S, 1);
	Push(S, 2);
	cout << Pop(S) << " ";
	Push(S, 3);
	cout << Pop(S) << " ";
	cout << Pop(S) << " ";
	return 0;
}
