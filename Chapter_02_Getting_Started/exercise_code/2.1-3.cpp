#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int LinearSearch(vector<int>& A, int v) {
	int n = A.size();
	for (int i = 0; i < n; ++i) {
		if (A[i] == v)
			return i;
	}
	return -1;
}

const int N = 10;

int main() {
	vector<int> A(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 23;
	}
	cout << "A sequence of n numbers A:" << endl;
	for (auto a : A) cout << a << " ";
	cout << endl;
	for (int i = 0; i < 3; ++i) {
		int v = rand() % 23;
		cout << "The index of "<< v <<" is : " << LinearSearch(A, v) << endl;
	}
	return 0;
}
