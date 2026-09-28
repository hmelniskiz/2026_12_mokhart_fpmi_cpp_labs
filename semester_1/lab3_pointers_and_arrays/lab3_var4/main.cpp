#include <iostream>

bool vvod(int& n) {
	if (!(std::cin >> n)) {
		std::cout << "ne chislo";
		return 0;
	}
	return 1;
}

int main() {
	int n, maxleft = 0, maxright = 0;
	int const maxsize = 1000;
	std::cout << "vvedite razmer" << std::endl;
	if (!(vvod(n))) {
		return 1;
	}
	int a[maxsize];
	std::cout << "vvedite elementi" << std::endl;
	for (int i = 0; i < n; i++) {
		if (!(vvod(a[i]))) {
			return 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int right, left;
		if (i < n - 1 && a[i] == a[i + 1]) {
			right = i + 1;
			left = i;
			while (left >= 0 && right <= n - 1 && a[left] == a[right]) {
				if ((right - left) > (maxright - maxleft)) {
					maxleft = left;
					maxright = right;
				}
				right++;
				left--;
			}
		}
		if (i < n - 2 && a[i] == a[i + 2]) {
			right = i + 2;
			left = i;
			while (left >= 0 && right <= n - 1 && a[left] == a[right]) {
				if ((right - left) > (maxright - maxleft)) {
					maxleft = left;
					maxright = right;
				}
				right++;
				left--;
			}
		}
	}
	for (int i = maxleft; i <= maxright; i++)
		std::cout << a[i] << " ";
}