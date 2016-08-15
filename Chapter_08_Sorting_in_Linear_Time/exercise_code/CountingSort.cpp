/***  Counting Sort nondecreasing  ***/
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

void CountingSort(vector<int>& A, vector<int>& B, int k) {
	vector<int> C(k + 1, 0);
	for (int j = 0; j < A.size(); ++j) {
		++C[A[j]];
	}
	for (int j = 1; j <= k; ++j) {
		C[j] += C[j - 1];
	}
	for (int j = A.size() - 1; j >= 0; --j) {
		B[C[A[j]] - 1] = A[j];
		--C[A[j]];
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	srand((int)time(NULL));
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 100;
	}
	CountingSort(A, B, 100);
	cout << "A: ";
	Print(A);

	cout << "After CountingSort(A): ";
	Print(B);

	return 0;
}
