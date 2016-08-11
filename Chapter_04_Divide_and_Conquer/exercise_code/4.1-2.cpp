#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<int> FindMaxSubarray(const vector<int>& A, int low, int high) {
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

void Print(const vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

const int N = 10;

int main() {
	vector<int> A(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 50 - 20;
	}
	cout << "A: ";
	Print(A);
	vector<int> result = FindMaxSubarray(A, 0, A.size() - 1);
	cout << endl << "Maximum-subarray: " << endl;
	cout << "Index : from " << result[0] << " to " << result[1] << endl;
	cout << "The sum is " << result[2] << endl;
	return 0;
}

