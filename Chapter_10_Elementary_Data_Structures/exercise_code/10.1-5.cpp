#include <iostream>
#include <vector>
using namespace std;

typedef struct Deque {
	vector<int> v;
	int head;
	int tail;
	int length;
} Deque;

void Init(Deque& DQ, int size) {
	DQ.v.resize(size);
	DQ.head = 0;
	DQ.tail = 0;
	DQ.length = size;
}

void PushFront(Deque& DQ, int x) {
	if ((DQ.tail + 1) % DQ.length == DQ.head) {
		cout << "overflow!" << endl;
		return;
		//exit(0);
	}
	if (DQ.head == 0) {
		DQ.head = DQ.length - 1;
	}
	else {
		--DQ.head;
	}
	DQ.v[DQ.head] = x;
}

void PushBack(Deque& DQ, int x) {
	if ((DQ.tail + 1) % DQ.length == DQ.head) {
		cout << "overflow!" << endl;
		return;
		//exit(0);
	}
	DQ.v[DQ.tail] = x;
	if (DQ.tail + 1 == DQ.length) {
		DQ.tail = 0;
	}
	else {
		++DQ.tail;
	}
}

int PopFront(Deque& DQ) {
	if (DQ.tail == DQ.head) {
		cout << "underflow!" << endl;
		return 0;
		//exit(0);
	}
	int x = DQ.v[DQ.head];
	if (DQ.head == DQ.length - 1) {
		DQ.head = 0;
	}
	else {
		++DQ.head;
	}
	return x;
}

int PopBack(Deque& DQ) {
	if (DQ.tail == DQ.head) {
		cout << "underflow!" << endl;
		return 0;
	}
	if (DQ.tail == 0) {
		DQ.tail = DQ.length - 1;
	}
	else {
		--DQ.tail;
	}
	return DQ.v[DQ.tail];
}

void PrintDeque(const Deque& DQ) {
	int cur = DQ.head;
	while (cur != DQ.tail) {
		cout << DQ.v[cur] << " ";
		cur = (cur + 1) % DQ.length;
	}
	cout << endl;
}

int main() {
	Deque DQ;
	Init(DQ, 10);
	PopFront(DQ);
	PopBack(DQ);
	PushFront(DQ, 2);
	PushFront(DQ, 4);
	PushBack(DQ, 3);
	PushBack(DQ, 5);
	PrintDeque(DQ);
	PopBack(DQ);
	PrintDeque(DQ);
	PopFront(DQ);
	PrintDeque(DQ);
	return 0;
}
