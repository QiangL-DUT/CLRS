typedef struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val_, Node* left_ = NULL, Node* right_ = NULL) : 
		val(val_), left(left_), right(right_){}
}Node;

void PreOrder(const Node* node) {
	if (node) {
		cout << node->val << " ";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}
