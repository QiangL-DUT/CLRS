#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

typedef struct Pos{
	int row;
	int col;
	int size;
	Pos(int row_, int col_, int size_) :row(row_), col(col_), size(size_) {}
} Pos;

void Strassen(const vector<vector<int>>& A, Pos pos_a, 
	const vector<vector<int>>& B, Pos pos_b,
	vector<vector<int>>& C, Pos pos_c) {
	int n = pos_a.size;
	int block_size = n / 2;
	if (n == 1) {
		C[pos_c.row][pos_c.col] = A[pos_a.row][pos_a.col] * B[pos_b.row][pos_b.col];
	}
	else {
		vector<vector<vector<int>>> S(10);
		for (int i = 0; i < 10; ++i) {
			S[i].resize(block_size);
			for (int j = 0; j < block_size; ++j) {
				S[i][j].resize(block_size);
			}
		}
		for (int i = 0; i < block_size; ++i) {
			for (int j = 0; j < block_size; ++j) {
				S[0][i][j] = B[pos_b.row + i][pos_b.col + block_size + j] - B[pos_b.row + block_size + i][pos_b.col + block_size + j];
				S[1][i][j] = A[pos_a.row + i][pos_a.col + j] + A[pos_a.row + i][pos_a.col + block_size + j];
				S[2][i][j] = A[pos_a.row + block_size + i][pos_a.col + j] + A[pos_a.row + block_size + i][pos_a.col + block_size + j];
				S[3][i][j] = B[pos_b.row + block_size + i][pos_b.col + j] - B[pos_b.row + i][pos_b.col + j];
				S[4][i][j] = A[pos_a.row + i][pos_a.col + j] + A[pos_a.row + block_size + i][pos_a.col + block_size + j];
				S[5][i][j] = B[pos_b.row + i][pos_b.col + j] + B[pos_b.row + block_size + i][pos_b.col + block_size + j];
				S[6][i][j] = A[pos_a.row + i][pos_a.col + block_size + j] - A[pos_a.row + block_size + i][pos_a.col + block_size + j];
				S[7][i][j] = B[pos_b.row + block_size + i][pos_b.col + j] + B[pos_b.row + block_size + i][pos_b.col + block_size + j];
				S[8][i][j] = A[pos_a.row + i][pos_a.col + j] - A[pos_a.row + block_size + i][pos_a.col + j];
				S[9][i][j] = B[pos_b.row + i][pos_b.col + j] + B[pos_b.row + i][pos_b.col + block_size + j];
			}
		}

		vector<vector<vector<int>>> P(7);
		for (int i = 0; i < 7; ++i) {
			P[i].resize(block_size);
			for (int j = 0; j < block_size; ++j) {
				P[i][j].resize(block_size);
			}
		}
		Strassen(A, Pos(pos_a.row, pos_a.col, block_size), S[0], Pos(0, 0, block_size), P[0], Pos(0, 0, block_size));
		Strassen(S[1], Pos(0, 0, block_size), B, Pos(pos_b.row + block_size, pos_b.col + block_size, block_size), P[1], Pos(0, 0, block_size));
		Strassen(S[2], Pos(0, 0, block_size), B, Pos(pos_b.row, pos_b.col, block_size), P[2], Pos(0, 0, block_size));
		Strassen(A, Pos(pos_a.row + block_size, pos_a.col + block_size, block_size), S[3], Pos(0, 0, block_size), P[3], Pos(0, 0, block_size));
		Strassen(S[4], Pos(0, 0, block_size), S[5], Pos(0, 0, block_size), P[4], Pos(0, 0, block_size));
		Strassen(S[6], Pos(0, 0, block_size), S[7], Pos(0, 0, block_size), P[5], Pos(0, 0, block_size));
		Strassen(S[8], Pos(0, 0, block_size), S[9], Pos(0, 0, block_size), P[6], Pos(0, 0, block_size));

		for (int i = 0; i < block_size; ++i) {
			for (int j = 0; j < block_size; ++j) {
				C[pos_c.row + i][pos_c.col + j] = P[4][i][j] + P[3][i][j] - P[1][i][j] + P[5][i][j];
				C[pos_c.row + i][pos_c.col + block_size + j] = P[0][i][j] + P[1][i][j];
				C[pos_c.row + block_size + i][pos_c.col + j] = P[2][i][j] + P[3][i][j];
				C[pos_c.row + block_size + i][pos_c.col + block_size + j] = P[4][i][j] + P[0][i][j] - P[2][i][j] - P[6][i][j];
			}
		}
	}
}

const int N = 2;

int main() {
	vector<vector<int>> A(N), B(N), C(N);
	A[0] = { 1, 3 };
	A[1] = { 7, 5 };
	B[0] = { 6, 8 };
	B[1] = { 4, 2 };
	for (int i = 0; i < N; ++i) {
		C[i].resize(N);
	}
	Strassen(A, Pos(0, 0, N), B, Pos(0, 0, N), C, Pos(0, 0, N));
	return 0;
}

