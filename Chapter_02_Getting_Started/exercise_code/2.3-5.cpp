#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

int BinarySearch(vector<int>& A, int v) {
	int low = 0;
	int high = A.size() - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == v) {
			return mid;
		}
		else if (A[mid] < v) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return -1;
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	vector<int> A(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 20;
	}
	cout << "A: " << endl;
	Print(A);
	for (int i = 0; i < 3; ++i) {
		int v = rand() % 20;
		cout << "Target: " << v << "\t Search result(index):" << BinarySearch(A, v) << endl;
	}
	return 0;
}

