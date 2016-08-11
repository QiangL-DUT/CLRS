#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

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

bool PairExist(vector<int>& S, int x) {
	MergeSort(S, 0, S.size() - 1);
	int l = 0, r = S.size() - 1;
	while (l < r) {
		if (S[l] + S[r] == x) {
			return true;
		}
		else if (S[l] + S[r] < x) {
			++l;
		}
		else {
			--r;
		}
	}
	return false;
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	vector<int> S(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		S[i] = rand() % 20;
	}
	cout << "A: " << endl;
	Print(S);
	for (int i = 0; i < 3; ++i) {
		int x = rand() % 40;
		cout << "Target: " << x << "\t Search result(index):" << PairExist(S, x) << endl;
	}
	return 0;
}

