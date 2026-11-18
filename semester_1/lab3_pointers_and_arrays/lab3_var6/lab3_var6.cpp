#include <iostream>

void prov(int& a, int& b) {
	if (a > b)
		std::swap(a, b);
}

int main() {
	int n, a, b, i1;
	std::cout << "vvedite razmer\n";
	std::cin >> n;
	std::cout << "vvedite a i b\n";
	std::cin >> a >> b;
	prov(a, b);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	for (int i = a; i <= b; i++) {
		i1 = a;
		for (int j = a + 1; j < n; j++) {
			std::swap(arr[i1], arr[j]);
			i1++;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}