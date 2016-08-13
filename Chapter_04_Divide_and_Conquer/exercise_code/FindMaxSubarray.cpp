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
	vector<int> result = { max_left, max_right, left_sum + right_sum };
	return result;
}

// Implemented by divide-and-conquer Θ(nlgn)
vector<int> FindMaxSubarray(const vector<int>& A, int low, int high) {
	if (low == high) {
		vector<int> result = { low, high, A[low] };
		return result;
	}
	int mid = (low + high) / 2;
	vector<int> left_result = FindMaxSubarray(A, low, mid);
	vector<int> right_result = FindMaxSubarray(A, mid + 1, high);
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
