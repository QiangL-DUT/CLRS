#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<int> FindMaxCrossSubarray(const vector<int>& A, int low, int mid, int high) {
	int left_sum = INT_MIN;
	int sum = 0;
	int max_left;
	for (int i = mid; i >= low; --i) {
		sum += A[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}
	int right_sum = INT_MIN;
	sum = 0;
	int max_right;
	for (int i = mid + 1; i <= high; ++i) {
		sum += A[i];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = i;
		}
	}
	if (left_sum + right_sum < 0) {
		vector<int> result = { mid, mid, 0 };
		return result;
	}
	else {
		vector<int> result = { max_left, max_right, left_sum + right_sum };
		return result;
	}
}

// Implemented by divide-and-conquer Θ(nlgn)
vector<int> FindMaxSubarrayRecur(const vector<int>& A, int low, int high) {
	if (low == high) {
		if (A[low] < 0) {
			vector<int> result = { low, low, 0 };
			return result;
		}
		else {
			vector<int> result = { low, high, A[low] };
			return result;
		}
	}
	int mid = (low + high) / 2;
	vector<int> left_result = FindMaxSubarrayRecur(A, low, mid);
	vector<int> right_result = FindMaxSubarrayRecur(A, mid + 1, high);
	vector<int> cross_result = FindMaxCrossSubarray(A, low, mid, high);
	if ((left_result[2] > right_result[2]) && (left_result[2] > cross_result[2])) {
		return left_result;
	}
	else if (right_result[2] > cross_result[2]) {
		return right_result;
	}
	else {
		return cross_result;
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
		A[i] = rand() % 100 - 100;
	}
	cout << "A: ";
	Print(A);
	vector<int> result_recur = FindMaxSubarrayRecur(A, 0, A.size() - 1);
	cout << "Index: from " << result_recur[0] << " to " << result_recur[1] << endl;
	cout << "Sum: " << result_recur[2] << endl << endl;
	return 0;
}

