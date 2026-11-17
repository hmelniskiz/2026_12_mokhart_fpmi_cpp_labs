#include <iostream>
#include <cstdlib>

int const maxsize = 1000;

bool vvod(int& n) {
	if (!(std::cin >> n)) {
		std::cout << "ne chislo";
		return false;
	}
	return true;
}

void randv(int(&a)[maxsize], int n, int c, int b) {
	for (int i = 0; i < n; i++) {
		a[i] = c + rand() % (b - c + 1);
	}
}

int main() {
	std::string s;
	int n, maxleft = 0, maxright = 0;
	std::cout << "vvedite razmer" << std::endl;
	if (!(vvod(n))) {
		return 1;
	}
	std::cout << "Vyberite 'random' ili 'vvesti'" << std::endl;
	std::cin >> s;
	int a[maxsize];
	if (s == "random") {
		int c, b;
		std::cout << "Vvedite diapazon";
		std::cin >> c >> b;
		if (c > b) {
			int te = c;
			c = b;
			b = te;
		}
		randv(a, n, c, b);
	}
	else if (s == "vvesti") {
		std::cout << "vvedite elementi" << std::endl;
		for (int i = 0; i < n; i++) {
			if (!(vvod(a[i]))) {
				return 1;
			}
		}
	}
	else {
		std::cout << "error";
		return 1;
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