#include <iostream>
#include <cstdlib>
#include <string>

void prov(int& a, int& b) {
	if (a > b)
		std::swap(a, b);
}

void randv(int *a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand();
	}
}

int main() {
	std::string s;
	int n, a, b, i1;
	std::cout << "vvedite razmer\n";
	std::cin >> n;
	std::cout << "vvedite a i b\n";
	std::cin >> a >> b;
	prov(a, b);
	int* arr = new int[n];

	std::cout << "Vyberite 'random' ili 'vvesti'" << std::endl;
	std::cin >> s;
	if (s == "random") {
		randv(arr, n);
	}
	else if (s == "vvesti") {
		std::cout << "vvedite elementi" << std::endl;
		for (int i = 0; i < n; i++) {
			std::cin >> arr[i];
		}
	}
	else {
		std::cout << "error";
		delete[] arr;
		return 1;
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