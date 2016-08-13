void HeapIncreaseKey(vector<int>& A, int i, int key) {
	if (key < A[i]) {
		cout << "New key is smaller than current key!" << endl;
		exit(0);
	}
	while ((i > 0) && (A[Parent(i)] < key)) {
		A[i] = A[Parent(i)];
		i = Parent(i);
	}
	A[i] = key;
}
