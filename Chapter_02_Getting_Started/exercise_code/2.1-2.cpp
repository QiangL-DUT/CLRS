#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& v){
	int n = v.size();
	for (int j = 1; j < n; ++j) {
		int key = v[j];
		int i = j - 1;
		while ((i >= 0) && (v[i] < key)){
			v[i + 1] = v[i];
			--i;
		}
		v[i + 1] = key;
	}
}

const int N = 10;
int main(){
	vector<int> v(N, 0);
	srand((int)time(NULL));
	for (int i = 0; i < N; ++i){
		v[i] = rand() % 100;
	}

	cout << "Before sorting:" << endl;
	for (int i = 0; i < N; ++i){
		cout << v[i] << " ";
	}
	cout << endl;

	InsertionSort(v);

	cout << "After sorting:" << endl;
	for (int i = 0; i < N; ++i){
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
