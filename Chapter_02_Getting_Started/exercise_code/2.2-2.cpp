#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void SelectSort(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n - 1; ++i) {
		int index = i;
		for (int j = i + 1; j < n; ++j) {
			if (A[index] > A[j]) {
				index = j;
			}
		}
		int temp = A[index];
		A[index] = A[i];
		A[i] = temp;
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
	SelectSort(A);
	cout << "After sorting: " << endl;
	Print(A);
	return 0;
}

