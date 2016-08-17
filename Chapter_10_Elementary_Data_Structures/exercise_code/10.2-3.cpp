#include <iostream>
using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int val_ = 0, Node* next_ = NULL) : val(val_), next(next_) {}
}Node;

typedef struct List{
	Node* head;
	Node* tail;
	List(Node* head_ = NULL, Node* tail_ = NULL) : head(head_), tail(tail_) {}
}List;

typedef struct Queue{
	List L;
}Queue;

void EnQueue(Queue& Q, int x) {
	Node* node = new Node(x, NULL);
	if (Q.L.head == NULL) {
		Q.L.head = node;
		Q.L.tail = node;
	}
	else {
		Q.L.tail->next = node;
		Q.L.tail = node;
	}
}

int DeQueue(Queue& Q) {
	if (Q.L.head == NULL) {
		cout << "underflow!" << endl;
		return 0;
	}
	Node* node = Q.L.head;
	int x = node->val;
	Q.L.head = node->next;
	if (Q.L.tail == node) {
		Q.L.tail = NULL;
	}
	return x;
}

void Print(const Queue& Q) {
	Node* cur = Q.L.head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	Queue Q;
	EnQueue(Q, 0);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	Print(Q);
	DeQueue(Q);
	Print(Q);
	return 0;
}
