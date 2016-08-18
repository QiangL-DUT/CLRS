#include <iostream>
using namespace std;

typedef struct Node{
	int val;
	Node* next;
	Node(int val_ = 0, Node* next_ = NULL) : val(val_), next(next_) {}
}Node;

typedef struct List{
	Node* nil;
}List;

void Init(List& L) {
	L.nil = new Node;
	L.nil->next = L.nil;
}

void Destroy(List& L) {
	Node* node = L.nil->next;
	while (node != L.nil) {
		L.nil->next = node->next;
		delete node;
		node = L.nil->next;
	}
	delete L.nil;
}

void Insert(List& L, int val) {
	Node* node = new Node(val);
	node->next = L.nil->next;
	L.nil->next = node;
}

void Reverse(List& L) {
	Node* cur = L.nil->next;
	L.nil->next = L.nil;
	while (cur != L.nil) {
		Node* temp = cur;
		cur = cur->next;
		temp->next = L.nil->next;
		L.nil->next = temp;
	}
}

void Print(const List& L) {
	Node* cur = L.nil->next;
	while (cur != L.nil) {
		cout << cur->val << "  ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	List L;
	Init(L);
	Insert(L, 1);
	Insert(L, 2);
	Insert(L, 3);
	Print(L);
	Reverse(L);
	Print(L);
	return 0;
}
