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

Node* TreeInsert(Node* root, int key) {
	Node* x = root;
	Node* y = NULL; 
	Node* z = new Node(key);
	while (x) {
		y = x;
		if (x->val < key) {
			x = x->right;
		}
		else {
			x = x->left;
		}
	}
	if (y == NULL) {
		return z;
	}
	else if (y->val < key){
		y->right = z;
		z->parent = y;
		return root;
	}
	else {
		y->left = z;
		z->parent = y;
		return root;
	}
}

Node* Transplant(Node* root, Node* u, Node* v) {
	if (u->parent == NULL) {
		return v;
	}
	if (u == u->parent->left) {
		u->parent->left = v;
	}
	else {
		u->parent->right = v;
	}
	if (v != NULL) {
		v->parent = u->parent;
	}
	return root;
}

Node* TreeDelete(Node* root, Node* z) {
	Node* temp = z;
	if (z->left == NULL) {
		root = Transplant(root, z, z->right);
	}
	else if (z->right == NULL) {
		root = Transplant(root, z, z->left);
	}
	else {
		Node* y = TreeMinimum(z->right);
		if (y->parent != z) {
			root = Transplant(root, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		root = Transplant(root, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
	if (temp != NULL) {
		delete temp;
	}
	return root;
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

void InOrder(Node* root) {
	if (root) {
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}

int main() {
	vector<int> v = { 6, 5, 2, -1, -1, 5, -1, -1, 7, -1, 8, -1, -1 };  //Fig.12-1(a)
	int i = -1;
	Node* root = CreateTree(v, i);
	cout << "TreeInsert(3): ";
	root = TreeInsert(root, 3);
	InOrder(root);
	cout << endl;
	cout << "TreeInsert(4): ";
	root = TreeInsert(root, 4);
	InOrder(root);
	cout << endl;
	cout << "TreeDelete(7): ";
	root = TreeDelete(root, Search(root, 7));
	InOrder(root);
	cout << endl;
	cout << "TreeDelete(5): ";
	root = TreeDelete(root, Search(root, 5));
	InOrder(root);
	cout << endl;
	cout << "TreeDelete(6): ";
	root = TreeDelete(root, Search(root, 6));
	InOrder(root);
	Destroy(root);
	return 0;
}
