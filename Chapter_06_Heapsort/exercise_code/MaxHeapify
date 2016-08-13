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

int main() {
	vector<int> A = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
	MaxHeapify(A, 2);
	return 0;
}

