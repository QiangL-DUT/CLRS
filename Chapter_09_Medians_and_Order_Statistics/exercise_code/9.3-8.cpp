#include <iostream>
#include <vector>
using namespace std;

int MedianOfTwo(const vector<int>& A, int p_a, int r_a, const vector<int>& B, int p_b, int r_b) {
	if (p_a == r_a) {
		return A[p_a];
	}
	int mid = (r_a - p_a) / 2;
	if (A[p_a + mid] <= B[p_b + mid]) {
		return MedianOfTwo(A, r_a - mid, r_a, B, p_b, p_b + mid);
	}
	else {
		return MedianOfTwo(A, p_a, p_a + mid, B, r_b - mid, r_b);
	}
}

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

int main() {
	srand((int)time(NULL));
	vector<int> A = { 3, 5, 6 };
	vector<int> B = { 4, 7, 9 };

	cout << "MedianOfTwo(A, B): " << MedianOfTwo(A, 0, A.size() - 1, B, 0, B.size() - 1);

	return 0;
}
