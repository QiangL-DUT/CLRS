#include <iostream>
#include <vector>
#include <queue>
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

void Insert(List& L, Node* x) {
	x->next = L.head;
	L.head = x;
}

void Delete(List& L, Node* x) {
	if (L.head == x) {
		L.head = L.head->next;
		delete x;
	}
	else {
		Node* pre = L.head;
		while ((pre->next != NULL) && (pre->next != x)) {
			pre = pre->next;
		}
		if (pre->next == NULL) {
			cout << "No such node" << endl;
		}
		else {
			pre->next = x->next;
			delete x;
		}
	}
}

void Print(const List& L) {
	Node* cur = L.head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

const int N = 5;

int main() {
	List L;
	vector<Node*> node(N);
	for (int i = 0; i < N; ++i) {
		node[i] = new Node(i, NULL);
		Insert(L, node[i]);
	}
	Print(L);
	Delete(L, node[2]);
	Print(L);
	Delete(L, node[2]);
	return 0;
}
