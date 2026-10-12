#include <iostream>

void matr(int**& matrix, int n, int m) {
	matrix = new int*[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
}

void scan(int** matrix, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}
}

void dlt(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	int** matrixA = nullptr;
	int** matrixB = nullptr;
	matr(matrixA, n, m);
	matr(matrixB, n, m);
	scan(matrixA, n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrixB[i][j] = 0;
				for (int k = i - 1; k < i + 2; k++) {
					for (int z = j - 1; z < j + 2; z++) {
						if ((k<0 || k>n - 1) || (z<0 || z>m - 1) || (k == i && z == j)){
							continue;
						}
						matrixB[i][j] += matrixA[k][z];
					}
				}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			std::cout << matrixB[i][j] << " ";
		}
		std::cout << std::endl;
	}
	dlt(matrixA, n);
	dlt(matrixB, n);
	return 0;
	}