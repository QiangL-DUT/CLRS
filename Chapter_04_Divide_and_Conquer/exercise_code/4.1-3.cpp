#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

// Implemented by brute-force Θ(n^2)
vector<int> FindMaxSubarrayLoop(const vector<int>& A, int low, int high) {
	int sum = INT_MIN;
	int left, right;
	for (int i = low; i <= high; ++i) {
		int current_sum = 0;
		for (int j = i; j <= high; ++j) {
			current_sum += A[j];
			if (current_sum > sum) {
				left = i;
				right = j;
				sum = current_sum;
			}
		}
	}
	vector<int> result = { left, right, sum };
	return result;
}

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
vector<int> FindMaxSubarrayRecur(const vector<int>& A, int low, int high) {
	if (low == high) {
		vector<int> result = { low, high, A[low] };
		return result;
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

//Implemented by divide-and-conquer (using threshold)
extern const int T;
vector<int> FindMaxSubarrayRecurN(const vector<int>& A, int low, int high) {
	if (high - low <= T) {       //brute-force, if high - low <= T
		vector<int> result = FindMaxSubarrayLoop(A, low, high);
		return result;
	}
	int mid = (low + high) / 2;
	vector<int> left_result = FindMaxSubarrayRecurN(A, low, mid);
	vector<int> right_result = FindMaxSubarrayRecurN(A, mid + 1, high);
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

const int N = 20000;
const int T = 20;

int main() {
	vector<int> A(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 100 - 40;
	}
	clock_t start_loop, stop_loop;
	start_loop = clock();
	vector<int> result_loop = FindMaxSubarrayLoop(A, 0, A.size() - 1);
	stop_loop = clock();
	cout << "Method: brute-force." << endl;
	cout << "Time: " << double(stop_loop - start_loop) / CLOCKS_PER_SEC << endl;
	cout << "Index: from " << result_loop[0] << " to " << result_loop[1] << endl;
	cout << "Sum:" << result_loop[2] << endl << endl;

	clock_t start_recur, stop_recur;
	start_recur = clock();
	vector<int> result_recur = FindMaxSubarrayRecur(A, 0, A.size() - 1);
	stop_recur = clock();
	cout << "Method: divide and conquer." << endl;
	cout << "Time: " << double(stop_recur - start_recur) / CLOCKS_PER_SEC << endl;
	cout << "Index: from " << result_recur[0] << " to " << result_recur[1] << endl;
	cout << "Sum: " << result_recur[2] << endl << endl;

	clock_t start_recur_n, stop_recur_n;
	start_recur_n = clock();
	vector<int> result_recur_n = FindMaxSubarrayRecurN(A, 0, A.size() - 1);
	stop_recur_n = clock();
	cout << "Method: divide and conquer(by threshold)" << endl;
	cout << "Time:" << double(stop_recur_n - start_recur_n) / CLOCKS_PER_SEC << endl;
	cout << "Index: from " << result_recur_n[0] << " to " << result_recur_n[1] << endl;
	cout << "Sum: " << result_recur_n[2] << endl << endl;
	return 0;
}

