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
		cout << "overflow!" << endl;
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
		cout << "underflow!" << endl;
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
