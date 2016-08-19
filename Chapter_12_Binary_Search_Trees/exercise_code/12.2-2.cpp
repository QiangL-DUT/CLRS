#include <iostream>
#include <vector>
#include <stack>
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

Node* TreeMinimum(Node* root) {
	if (root->left) {
		return TreeMinimum(root->left);
	}
	else {
		return root;
	}
}

Node* TreeMaximum(Node* root) {
	if (root->right) {
		return TreeMaximum(root->right);
	}
	else {
		return root;
	}
}

int main() {
	vector<int> v = { 6, 5, 2, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1 };  //Fig.12-1(a)
	int i = -1;
	Node* root = CreateTree(v, i);
	cout << "TreeMinimum: " << TreeMinimum(root)->val << endl;
	cout << "TreeMaximum: " << TreeMaximum(root)->val << endl;
	cout << endl;
	Destroy(root);
	return 0;
}
