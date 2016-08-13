#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

inline int Left(int i) {
	return i * 2 + 1;
}

inline int Right(int i) {
	return (i + 1) * 2;
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

void BuildMaxHeap(vector<int>& A) {
	int n = A.size();
	for (int i = (n - 1) / 2; i >= 0; --i) {
		MaxHeapify(A, n, i);
	}
}

void HeapSort(vector<int>& A) {
	BuildMaxHeap(A);
	int n = A.size();
	for (int i = n - 1; i > 0; --i) {
		swap(A[0], A[i]);
		MaxHeapify(A, i, 0);
	}
}

int main() {
	vector<int> A = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
	HeapSort(A);
	return 0;
}
