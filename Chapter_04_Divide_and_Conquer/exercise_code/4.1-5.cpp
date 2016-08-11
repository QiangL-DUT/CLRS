#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<int> FindMaxSubarrayLinear(const vector<int>& A, int low, int high) {
	int sum = INT_MIN;
	int cur_sum = INT_MIN;
	int left, right;
	int cur_left, cur_right;
	for (int i = low; i <= high; ++i) {
		if (cur_sum > 0) {
			cur_sum += A[i];
			cur_right = i;
		}
		else {
			cur_sum = A[i];
			cur_left = i;
			cur_right = i;
		}
		if (cur_sum > sum) {
			sum = cur_sum;
			left = cur_left;
			right = cur_right;
		}
	}
	vector<int> result = { left, right, sum };
	return result;
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
		A[i] = rand() % 100 - 50;
	}
	Print(A);
	clock_t start, stop;
	start = clock();
	vector<int> result_recur = FindMaxSubarrayLinear(A, 0, A.size() - 1);
	stop = clock();
	cout << "Index: from " << result_recur[0] << " to " << result_recur[1] << endl;
	cout << "Sum: " << result_recur[2] << endl;
	cout << "Time: " << double(stop - start) / CLOCKS_PER_SEC << endl;
	return 0;
}

