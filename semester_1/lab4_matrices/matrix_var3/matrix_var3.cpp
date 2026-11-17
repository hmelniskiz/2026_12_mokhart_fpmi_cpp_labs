#include <iostream>
#include <cstdlib>

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

void randv(int** matrix, int n, int m, int c, int b) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = c + rand() % (b - c + 1);
		}
	}
}

int main() {
	std::cout << "Vvedite razmer matrix";
	std::string s;
	int n, m;
	std::cin >> n >> m;
	int** matrixA = nullptr;
	int** matrixB = nullptr;
	matr(matrixA, n, m);
	matr(matrixB, n, m);
	std::cout << "Vyberite 'random' ili 'vvesti'" << std::endl;
	std::cin >> s;
	if (s == "random") {
		int c, b;
		std::cout << "Vvedite diapazon";
		std::cin >> c >> b;
		if (c > b) {
			int te = c;
			c = b;
			b = te;
		}
		randv(matrixA, n, m, c, b);
		
	}
	else if (s == "vvesti") {
		std::cout << "vvedite elementi" << std::endl;
		scan(matrixA, n, m);
	}
	else {
		std::cout << "error";
		dlt(matrixA, n);
		dlt(matrixB, n);
		return 1;
	}
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