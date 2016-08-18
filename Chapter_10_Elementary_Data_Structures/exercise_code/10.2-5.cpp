#include <iostream>
using namespace std;

typedef struct Node{
	int key;
	int val;
	Node* next;
	Node(int key_ = 0, int val_ = 0, Node* next_ = NULL) : key(key_), val(val_), next(next_) {}
}Node;

typedef struct List{
	Node* nil;
}List;

void Init(List& L) {
	L.nil = new Node;
	L.nil->next = L.nil;
}

Node* Search(const List& L, int key) {
	Node* cur = L.nil->next;
	L.nil->key = key;
	while (cur->key != key) {
		cur = cur->next;
	}
	if (cur != L.nil) {
		return cur;
	}
	else {
		return NULL;
	}
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

void Insert(List& L, int key, int val) {
	Node* node = Search(L, key);
	if (node != NULL) {
		node->val = val;
	}
	else {
		node = new Node(key, val, NULL);
		node->next = L.nil->next;
		L.nil->next = node;
	}
}

bool Delete(List& L, int key) {
	Node* cur = L.nil->next;
	if (cur == L.nil) {
		cout << "No such key: " << key<< endl;
		return false;
	}
	else if (cur->key == key) {
		L.nil->next = cur->next;
		delete cur;
		return true;
	}
	else {
		L.nil->key = key;
		while (cur->next->key =! key) {
			cur = cur->next;
		}
		if (cur->next == L.nil) {
			cout << "No such key: " << key << endl;
			return false;
		}
		else {
			Node* temp = cur->next;
			cur->next = temp->next;
			delete temp;
			return true;
		}
	}
}

void Print(const List& L) {
	Node* cur = L.nil->next;
	while (cur != L.nil) {
		cout << "(" << cur->key << ", " << cur->val << ")" << "  ";
		cur = cur->next;
	}
	cout << endl;
}

int main() {
	List L;
	Init(L);
	Insert(L, 1, 1);
	Insert(L, 2, 2);
	Print(L);
	Delete(L, 2);
	Print(L);
	Insert(L, 3, 3);
	Print(L);
	Destroy(L);
	return 0;
}
