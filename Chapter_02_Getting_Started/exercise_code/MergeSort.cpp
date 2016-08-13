#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void Merge(vector<int>& A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	vector<int> L(A.begin() + p, A.begin() + q + 1);
	vector<int> R(A.begin() + q + 1, A.begin() + r + 1);
	int i = 0, j = 0, k = p;
	while ((i < n1) && (j < n2)) {
		if (L[i] <= R[j]) {
			A[k++] = L[i++];
		}
		else {
			A[k++] = R[j++];
		}
	}
	while (i < n1) {
		A[k++] = L[i++];
	}
	while (j < n2) {
		A[k++] = R[j++];
	}
}

void MergeSort(vector<int>& A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

void Print(const vector<int>& v) {
	for (auto a : v) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	vector<int> A(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 100;
	}
	cout << "Before sorting: " << endl;
	Print(A);
	MergeSort(A, 0, N - 1);
	cout << "After sorting: " << endl;
	Print(A);
	return 0;
}

