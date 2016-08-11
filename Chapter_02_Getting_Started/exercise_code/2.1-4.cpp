#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

vector<int> AddBinary(vector<int>& A, vector<int>& B){
	int n = A.size();
	vector<int> C(n + 1, 0);
	int carry = 0;
	for (int i = 0; i < n; ++i){
		C[i] = (A[i] + B[i] + carry) % 2;
		carry = (A[i] + B[i] + carry) / 2;
	}
	C[n] = carry;
	return C;
}

void PrintBinary(const vector<int>& v){
	for (auto i : v) cout << i << " ";
	cout << endl;
}

const int N = 5;

int main(){
	vector<int> A(N, 0);
	vector<int> B(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i) {
		A[i] = rand() % 2;
		B[i] = rand() % 2;
	}
	vector<int> C = AddBinary(A, B);
	cout << "A: ";
	PrintBinary(A);
	cout << "B: ";
	PrintBinary(B);
	cout << "C: ";
	PrintBinary(C);
	system("pause");
	return 0;
}

