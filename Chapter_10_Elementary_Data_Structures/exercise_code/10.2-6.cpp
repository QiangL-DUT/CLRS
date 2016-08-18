#include <iostream>
using namespace std;

typedef struct Node{
	int key;
	Node* next;
	Node* prev;
	Node(int key_ = 0, Node* next_ = NULL, Node* prev_ = NULL) : key(key_), next(next_), prev(prev_) {}
}Node;

typedef struct List{
	Node* nil;
}List;

void Init(List& L) {
	L.nil = new Node;
	L.nil->next = L.nil;
	L.nil->prev = L.nil;
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

void Insert(List& L, int key) {
	Node* node = new Node(key);
	node->next = L.nil->next;
	L.nil->next->prev = node;
	node->prev = L.nil;
	L.nil->next = node;
}

void Print(const List& L) {
	Node* cur = L.nil->next;
	while (cur != L.nil) {
		cout << cur->key << "  ";
		cur = cur->next;
	}
	cout << endl;
}

List Union(List& L1, List& L2) {
	List L = L1;
	L1.nil = NULL;
	if (L2.nil->next != L2.nil) {
		L.nil->prev->next = L2.nil->next;
		L2.nil->next->prev = L.nil->prev;
		L2.nil->prev->next = L.nil;
		L.nil->prev = L2.nil->prev;
	}
	delete L2.nil;
	L2.nil = NULL;
	return L;
}

int main() {
	List L, L1, L2;
	Init(L1);
	Init(L2);
	Insert(L1, 1);
	Insert(L1, 2);
	Insert(L2, 6);
	Insert(L2, 7);
	Print(L1);
	Print(L2);
	L = Union(L1, L2);
	Print(L);
	return 0;
}
