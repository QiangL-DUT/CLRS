#include <iostream>
#include <stack>
using namespace std;

typedef struct Queue {
	stack<int> S_1;
	stack<int> S_2;
}Queue;

void Init(Queue& Q) {}

void EnQueue(Queue& Q, int x) {
	Q.S_1.push(x);
}

int DeQueue(Queue& Q) { 
	if (Q.S_1.empty() && Q.S_2.empty()) {
		cout << "underflow!" << endl;
		return 0;
	}
	if (Q.S_2.empty()) {
		while (!Q.S_1.empty()) {
			int x = Q.S_1.top();
			Q.S_2.push(x);
			Q.S_1.pop();
		}
	}
	int x = Q.S_2.top();
	Q.S_2.pop();
	return x;
}

int main() {
	Queue Q;
	Init(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	cout << DeQueue(Q) << " ";
	EnQueue(Q, 3);
	cout << DeQueue(Q) << " ";
	cout << DeQueue(Q) << " ";
	return 0;
}
