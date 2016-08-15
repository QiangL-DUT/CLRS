#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

vector<int> C;

void Init(const vector<int>& A, int k) {
	C.resize(k + 2, 0);
	for (int i = 0; i < A.size(); ++i) {
		++C[A[i] + 1];
	}
	for (int i = 2; i < k + 2; ++i) {
		C[i] += C[i - 1];
	}
}

int Count(const vector<int>& A, int a, int b) {
	return C[b + 1] - C[a];
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

	Init(A, 100);
	cout << "Count(A, 0, 50): " << Count(A, 0, 50);

	return 0;
}
