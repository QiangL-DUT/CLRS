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

void MinHeapify(vector<int>& A, int i) {
	int n = A.size();
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
		MinHeapify(A, smallest);
	}
}

int main() {
	vector<int> A = { 17, 7, 9, 8, 10, 10, 13, 11, 15, 12, 14 };
	MinHeapify(A, 0);
	return 0;
}
