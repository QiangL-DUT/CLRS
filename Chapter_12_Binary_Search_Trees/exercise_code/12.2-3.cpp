#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef struct Node {
	int val;
	Node* left;
	Node* right;
	Node * parent;
	Node(int val_ = 0, Node* left_ = NULL, Node* right_ = NULL, Node* parent_ = NULL) : 
		val(val_), left(left_), right(right_), parent(parent_) {}
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
	if (node->left) {
		node->left->parent = node;
	}
	if (node->right) {
		node->right->parent = node;
	}
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

Node* TreeMinimum(Node* root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

Node* TreeMaximum(Node* root) {
	while (root->right) {
		root = root->right;
	}
	return root;
}

Node* TreeSuccessor(Node* x) {
	if (x->right) {
		return TreeMinimum(x->right);
	}
	Node* y = x->parent;
	while ((y) && (y->left != x)) {
		x = y;
		y = y->parent;
	}
	return y;
}

Node* TreePredecessor(Node* x) {
	if (x->left) {
		return TreeMaximum(x->left);
	}
	Node* y = x->parent;
	while ((y) && (y->right != x)) {
		x = y;
		y = y->parent;
	}
	return y;
}

Node* Search(Node* root, int key) {
	if ((!root) || (root->val == key)) {
		return root;
	}
	else if (root->val < key) {
		return Search(root->right, key);
	}
	else {
		return Search(root->left, key);
	}
}

int main() {
	vector<int> v = { 6, 5, 2, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1 };  //Fig.12-1(a)
	int i = -1;
	Node* root = CreateTree(v, i);
	cout << "TreeSucessor(7): " << TreeSuccessor(Search(root, 7))->val << endl;
	cout << "TreePredecessor(7): " << TreePredecessor(Search(root, 7))->val << endl;
	cout << endl;
	Destroy(root);
	return 0;
}
