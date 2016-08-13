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

void MaxHeapify(vector<int>& A, int i) {
	int n = A.size();
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
		MaxHeapify(A, largest);
	}
}

void BuildMaxHeap(vector<int>& A) {
	int n = A.size();
	for (int i = (n - 1) / 2; i >= 0; --i) {
		MaxHeapify(A, i);
	}
}

int main() {
	vector<int> A = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	BuildMaxHeap(A);
	return 0;
}
