typedef struct Node {
	int val;
	Node* child;
	Node* sibling;
	Node(int val_, Node* child_ = NULL, Node* sibling_ = NULL) : 
		val(val_), child(child_), sibling(sibling_){}
}Node;

void PrintTree(const Node* node) {
	if (node) {
		cout << node->val << " ";
		PrintTree(node->child);
		PrintTree(node->sibling);
	}
}
