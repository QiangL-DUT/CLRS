#include <iostream>
using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int val_ = 0, Node* next_ = NULL) : val(val_), next(next_) {}
}Node;

typedef struct List{
	Node* head;
	List(Node* head_ = NULL) : head(head_) {}
}List;

typedef struct Stack{
	List L;
}Stack;

void Push(Stack& S, int x) {
	Node* node = new Node(x, NULL);
	node->next = S.L.head;
	S.L.head = node;
}

int Pop(Stack& S) {
	if (S.L.head == NULL) {
		cout << "underflow!" << endl;
		exit(0);
	}
	Node* node = S.L.head;
	int x = node->val;
	S.L.head = node->next;
	delete node;
	return x;
}

void Print(const Stack& S) {
	Node* cur = S.L.head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

const int N = 5;

int main() {
	Stack S;
	Push(S, 0);
	Push(S, 1);
	Push(S, 2);
	Print(S);
	Pop(S);
	Print(S);
	Push(S, 3);
	Print(S);
	return 0;
}
