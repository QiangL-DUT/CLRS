#include <iostream>
#include <vector>
#include <time.h>
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
		if (A[j] <= x) {
			swap(A[++i], A[j]);
		}
	}
	swap(A[++i], A[r]);
	return i;
}

int RandomizedPartition(vector<int>& A, int p, int r) {
	int i = rand() % (r - p + 1) + p;
	swap(A[i], A[r]);
	return Partition(A, p, r);
}

int RandomizedSelect(vector<int>& A, int p, int r, int i) {
	if (p == r) {
		return A[p];
	}
	int q = RandomizedPartition(A, p, r);
	int k = q - p + 1;
	if (i == k) {
		return A[q];
	}
	else if (i < k) {
		return RandomizedSelect(A, p, q - 1, i);
	}
	else {
		return RandomizedSelect(A, q + 1, r, i - k);
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	srand((int)time(NULL));
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 100;
	}
	cout << "A: ";
	Print(A);
	cout << "RandomizedSelect(A, 3): " << RandomizedSelect(A, 0, A.size() - 1, 3);
	return 0;
}
