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

void MinHeapify(vector<int>& A, int n, int i) {
	if (n <= 0) {
		return;
	}
	int l = Left(i);
	int r = Right(i);
	int smallest = i;
	if ((l < n) && (A[l] < A[i])) {
		smallest = l;
	}
	if ((r < n) && (A[r] < A[smallest])) {
		smallest = r;
	}
	if (smallest != i) {
		swap(A[i], A[smallest]);
		MinHeapify(A, n, smallest);
	}
}

int HeapMinimum(const vector<int>& A) {
	return A[0];
}

int HeapExtractMin(vector<int>& A) {
	if (A.empty()) {
		cout << "Heap underflow!" << endl;
		exit(0);
	}
	int min = A[0];
	A[0] = A[A.size() - 1];
	A.pop_back();
	MinHeapify(A, A.size(), 0);
	return min;
}

void HeapDecreaseKey(vector<int>& A, int i, int key) {
	if (key > A[i]) {
		cout << "New key is larger than current key!" << endl;
		exit(0);
	}
	A[i] = key;
	while ((i > 0) && (A[Parent(i)] > A[i])) {
		swap(A[i], A[Parent(i)]);
		i = Parent(i);
	}
}

void MinHeapInsert(vector<int>& A, int key) {
	A.push_back(INT_MAX);
	HeapDecreaseKey(A, A.size() - 1, key);
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

int main() {
	vector<int> A = { 1, 2, 4, 3, 9, 7, 8, 10, 14, 16 };
	cout << "A: ";
	Print(A);
	
	cout << "Heap-Minimumu: " << HeapMinimum(A) << endl;
	
	HeapExtractMin(A);
	cout << "After calling HeapExtractMin(A): ";
	Print(A);
	
	HeapDecreaseKey(A, 7, 0);
	cout << "After calling HeapDecreaseKey(A, 7, 0): ";
	Print(A);
	
	MinHeapInsert(A, 1);
	cout << "After calling MinHeapInsert(A, 1): ";
	Print(A);
	
	return 0;
}
