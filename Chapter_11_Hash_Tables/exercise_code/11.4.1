#include <iostream>
#include <vector>
using namespace std;

const int m = 11;
const int c1 = 1;
const int c2 = 3;

void Init(vector<int>& T, int m) {
	T.resize(m, -1);
}

inline int LinearProb(int key, int i) {
	return (key + i) % m;
}

inline int QuadraticProb(int key, int i) {
	return (key + c1 * i + c2 * i * i) % m;
}

inline int DoubleProb(int key, int i) {
	return (key + i * (1 + (key % (m - 1)))) % m;
}

void Insert(int (*prob)(int, int),vector<int>& T, int key) {
	int i = 0;
	while (true) {
		int j = prob(key, i);
		if (T[j] == -1) {
			T[j] = key;
			return;
		}
		if (i == m - 1) {
			cout << "Failed insert!" << endl;
			return;
		}
		++i;
	}
}

void Print(const vector<int>& T) {
	for (auto t : T) cout << t << " ";
	cout << endl;
}

int main() {
	vector<int> Keys = { 10, 22, 31, 4, 15, 28, 17, 88, 59 };
	vector<int> LinearT, QuadraticT, DoubleT;
	Init(LinearT, m);
	Init(QuadraticT, m);
	Init(DoubleT, m);
	for (int i = 0; i < Keys.size(); ++i) {
		Insert(LinearProb, LinearT, Keys[i]);
	}
	for (int i = 0; i < Keys.size(); ++i) {
		Insert(QuadraticProb, QuadraticT, Keys[i]);
	}
	for (int i = 0; i < Keys.size(); ++i) {
		Insert(DoubleProb, DoubleT, Keys[i]);
	}
	cout << "Keys: ";
	Print(Keys);
	cout << "LinearProb: ";
	Print(LinearT);
	cout << "QuadraticProb: ";
	Print(QuadraticT);
	cout << "DoubleProb: ";
	Print(DoubleT);
	return 0;
}
