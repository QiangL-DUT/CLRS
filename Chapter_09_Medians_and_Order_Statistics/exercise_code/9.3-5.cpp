#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

inline void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int Partition(vector<int>& A, int p, int r, int x) {
	for (int k = p; k < r; ++k) {
		if (A[k] == x) {
			swap(A[k], A[r]);
			break;
		}
	}
	int i = p - 1;
	for (int k = p; k < r; ++k) {
		if (A[k] < x) {
			swap(A[++i], A[k]);
		}
	}
	swap(A[++i], A[r]);
	return i;
}

int BlackBoxMedian(const vector<int>& A, int p, int r) {
	vector<int> B(A.begin() + p, A.begin() + r + 1);
	sort(B.begin(), B.end());
	return B[(B.size() - 1) / 2];
}

int Select(vector<int>& A, int p, int r, int i) {
	if (p == r) {
		return A[p];
	}
	int median = BlackBoxMedian(A, p, r);
	int q = Partition(A, p, r, median);
	int k = q - p + 1;
	if (k == i) {
		return A[q];
	}
	else if (k < i) {
		return Select(A, q + 1, r, i - k);
	}
	else {
		return Select(A, p, q - 1, i);
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

int main() {
	vector<int> A = { 3, 5, 6 , 9, 8, 7, 1, 2, 4};
	cout << "Select(A, 2): " << Select(A, 0, A.size() - 1, 2) << endl;
	return 0;
}
