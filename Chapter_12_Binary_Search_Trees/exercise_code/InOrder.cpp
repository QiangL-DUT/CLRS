#include <iostream>
#include <vector>
using namespace std;

typedef struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val_ = 0, Node* left_ = NULL, Node* right_ = NULL) : 
		val(val_), left(left_), right(right_) {}
}Node;

Node* CreateTree(const vector<int> v, int& i) {
	++i;
	if (i >= v.size()) {
		return NULL;
	}
	if (v[i] == -1) {
		return NULL;
	}
	Node* node = new Node(v[i]);
	node->left = CreateTree(v, i);
	node->right = CreateTree(v, i);
	return node;
}

void Destroy(Node* root) {
	if (root) {
		if (root->left) {
			Destroy(root->left);
		}
		if (root->right) {
			Destroy(root->right);
		}
		delete root;
	}
}

void InOrder(Node* root) {
	if (root) {
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}

int main() {
	vector<int> v = { 6, 5, 2, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1 };
	int i = -1;
	Node* root = CreateTree(v, i);
	InOrder(root);
	Destroy(root);
	return 0;
}
