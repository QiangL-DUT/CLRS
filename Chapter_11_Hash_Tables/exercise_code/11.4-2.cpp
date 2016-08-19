#include <iostream>
#include <vector>
using namespace std;

const int m = 11;
const int c1 = 1;
const int c2 = 3;

void Init(vector<int>& T, int m) {
	T.resize(m, -1);
}

void Insert(vector<int>& T, int key) {
	int i = 0;
	while (true) {
		int j = (key + i) % m;
		if ((T[j] == -1) || (T[j] == -2)) {
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

void Delete(vector<int>& T, int key) {
	int i = 0;
	while (true) {
		int j = (key + i) % m;
		if (T[j] == key) {
			T[j] = -2;
			return;
		}
		if ((T[j] == -1) || (i == m - 1)) {
			cout << "No such key: " << key << endl;
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
	vector<int> T, QuadraticT, DoubleT;
	Init(T, m);
	for (int i = 0; i < Keys.size(); ++i) {
		Insert(T, Keys[i]);
	}
	cout << "Keys: ";
	Print(Keys);
	cout << "T: ";
	Print(T);
	Delete(T, 22);
	cout << "After deleting key-22: ";
	Print(T);
	Delete(T, 88);
	cout << "After deleting key-88: ";
	Print(T);
	Insert(T, 11);
	cout << "After inserting key-11: ";
	Print(T);
	cout << "Delete key-2: ";
	Delete(T, 2);
	return 0;
}
