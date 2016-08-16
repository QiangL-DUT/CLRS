#include <iostream>
#include <vector>
#include <math.h>
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

vector<int> KClosest(vector<int>& S, int k) {
	int median = RandomizedSelect(S, 0, S.size() - 1, (S.size() + 1) / 2);
	vector<int> C(S.size());
	for (int i = 0; i < S.size(); ++i) {
		C[i] = abs(S[i] - median);
	}
	int kth = RandomizedSelect(C, 0, C.size() - 1, k);
	vector<int> closest(k);
	int count = 0;
	for (int i = 0; i < S.size(); ++i) {
		if (abs(S[i] - median) <= kth) {
			closest[count++] = S[i];
			if (count == k) {
				return closest;
			}
		}
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

int main() {
	vector<int> S = { 3, 5, 6 , 9, 8, 7, 1, 2, 4};
	vector<int> closest = KClosest(S, 3);
	cout << "MedianOfTwo(A, B): ";
	Print(closest);

	return 0;
}
