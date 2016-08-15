class CountInterval {
public:
	void Init(const vector<int>& A, int k);
	int Count(const vector<int>& A, int a, int b) {
		return C[b + 1] - C[a];
	}
private:
	vector<int> C;
};

void CountInterval::Init(const vector<int>& A, int k) {
	C.resize(k + 2, 0);
	for (int i = 0; i < A.size(); ++i) {
		++C[A[i] + 1];
	}
	for (int i = 2; i < k + 2; ++i) {
		C[i] += C[i - 1];
	}
}
