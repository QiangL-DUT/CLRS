typedef struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val_, Node* left_ = NULL, Node* right_ = NULL) : 
		val(val_), left(left_), right(right_){}
}Node;

void PreOrder(const Node* node) {
	stack<const Node*> S;
	S.push(node);
	while (!S.empty()) {
		node = S.top();
		S.pop();
		cout << node->val << " ";
		if (node->right) {
			S.push(node->right);
		}
		if (node->left) {
			S.push(node->left);
		}
	}
}
