#include <vector>
using namespace std;

inline void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int Partition(vector<int>& A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; ++j) {
		if (A[j] < x) {
			swap(A[++i], A[j]);
		}
	}
	int k = i;
	for (int j = i + 1; j < r; ++j) {
		if (A[j] == x) {
			swap(A[j], A[++k]);
		}
	}
	swap(A[++k], A[r]);
	return (i + k + 1) / 2;
}
