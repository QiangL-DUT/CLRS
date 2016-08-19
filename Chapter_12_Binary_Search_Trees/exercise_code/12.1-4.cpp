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

void InOrder(Node* root) {
	if (root) {
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}

void PreOrder(Node* root) {
	if (root) {
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(Node* root) {
	if (root) {
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}

int main() {
	vector<int> v = { 6, 5, 2, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1 };  //Fig.12-1(a)
	int i = -1;
	Node* root = CreateTree(v, i);
	cout << "InOrder: ";
	InOrder(root);
	cout << endl;
	cout << "PreOrder: ";
	PreOrder(root);
	cout << endl;
	cout << "PostOrder: ";
	PostOrder(root);
	cout << endl;
	Destroy(root);
	return 0;
}
