#include <iostream>
#include <vector>
using namespace std;

typedef struct Queue {
	vector<int> v;
	int head;
	int tail;
	int length;
} Queue;

void Init(Queue& Q, int size) {
	Q.v.resize(size);
	Q.head = 0;
	Q.tail = 0;
	Q.length = size;
}

void EnQueue(Queue& Q, int x) {
	if ((Q.tail + 1) % Q.length == Q.head) {
		cout << "underflow!" << endl;
		return;
		//exit(0);
	}
	Q.v[Q.tail] = x;
	if (Q.tail + 1 == Q.length) {
		Q.tail = 0;
	}
	else {
		++Q.tail;
	}
}

int DeQueue(Queue& Q) {
	if (Q.tail == Q.head) {
		cout << "overflow!" << endl;
		return 0;
		//exit(0);
	}
	int x = Q.v[Q.head];
	if (Q.head == Q.length - 1) {
		Q.head = 0;
	}
	else {
		++Q.head;
	}
	return x;
}

void PrintQueue(const Queue& Q) {
	int cur = Q.head;
	while (cur != Q.tail) {
		cout << Q.v[cur] << " ";
		cur = (cur + 1) % Q.length;
	}
	cout << endl;
}

int main() {
	Queue Q;
	Init(Q, 3);
	DeQueue(Q);
	EnQueue(Q, 4);
	PrintQueue(Q);
	EnQueue(Q, 1);
	PrintQueue(Q);
	EnQueue(Q, 3);
	PrintQueue(Q);
	DeQueue(Q);
	PrintQueue(Q);
	EnQueue(Q, 8);
	PrintQueue(Q);
	DeQueue(Q);
	PrintQueue(Q);
	return 0;
}
