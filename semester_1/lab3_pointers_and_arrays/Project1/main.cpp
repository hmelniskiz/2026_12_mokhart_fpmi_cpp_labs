#include <iostream>
#include <vector>

std::vector<int> merge(int* arr, int* arr1, int size1, int size2) {
	std::vector <int> arr3(size1 + size2);
	int i = 0, j = 0, k = 0;
	while (i < size1 && j < size2) {
		
		if (arr[i] > arr1[j]) {
			arr3[k] = arr1[j];
			j++;
			k++;
			continue;
		}
		if (arr1[j] > arr[i]) {
			arr3[k] = arr[i];
			i++;
			k++;
			continue;
		}
	}
	if (i == size1) {
		for (int z = i + j;z < size1 + size2; z++) {
			arr3[z] = arr1[j];
			j++;
		}
	}
	else {
		for (int z = i + j;z < size1 + size2; z++) {
			arr3[z] = arr1[i];
			i++;
		}
	}
	return arr3;
}

int main() {
	std::vector <int> arr3;
	const int nmax = 1000, mmax = 1000;
	int arr[nmax], arr1[mmax];
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	for (int i = 0; i < m; i++)
		std::cin >> arr1[i];
	arr3 = merge(arr, arr1, n, m);
	for (int i = 0; i < arr3.size(); i++)
		std::cout << arr3[i] << " ";
	
}