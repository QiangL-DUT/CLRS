#include <iostream>
#include <vector>
using namespace std;

inline int Left(int i) {
	return i * 2 + 1;
}

inline int Right(int i) {
	return (i + 1) * 2;
}

inline int Parent(int i) {
	return (i - 1) / 2;
}

inline void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void MaxHeapify(vector<int>& A, int n, int i) {
	if (n <= 0) {
		return;
	}
	int l = Left(i);
	int r = Right(i);
	int largest = i;
	if ((l < n) && (A[l] > A[i])) {
		largest = l;
	}
	if ((r < n) && (A[r] > A[largest])) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		MaxHeapify(A, n, largest);
	}
}

int HeapMaximum(const vector<int>& A) {
	return A[0];
}

int HeapExtractMax(vector<int>& A) {
	if (A.empty()) {
		cout << "Heap underflow!" << endl;
		exit(0);
	}
	int max = A[0];
	A[0] = A[A.size() - 1];
	A.pop_back();
	MaxHeapify(A, A.size(), 0);
	return max;
}

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

void MaxHeapInsert(vector<int>& A, int key) {
	A.push_back(INT_MIN);
	HeapIncreaseKey(A, A.size() - 1, key);
}

void HeapDelete(vector<int>& A, int i) {
	A[i] = A[A.size() - 1];
	A.pop_back();
	if ((i > 0) && (A[Parent(i)] < A[i])) {
		HeapIncreaseKey(A, i, A[i]);
	}
	else {
		MaxHeapify(A, A.size(), i);
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

int main() {
	vector<int> A = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
	cout << "A: ";
	Print(A);
	
	cout << "Heap-Maximumu: " << HeapMaximum(A) << endl;
	
	HeapExtractMax(A);
	cout << "After calling HeapExtractMax(A): ";
	Print(A);
	
	HeapIncreaseKey(A, 7, 13);
	cout << "After calling HeapIncreaseKey(A, 7, 13): ";
	Print(A);
	
	MaxHeapInsert(A, 15);
	cout << "After calling MaxHeapInsert(A, 15): ";
	Print(A);
	
	HeapDelete(A, 1);
	cout << "After calling HeapDelete(A, 1): ";
	Print(A);
	
	return 0;
}
