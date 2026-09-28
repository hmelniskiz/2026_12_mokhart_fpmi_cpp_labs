#include <iostream>

int main() {
    int a, b, pr;
    std::cin >> a >> b;
    for (int i = a; a <= b; i++) {
        int povt = i;
        while (povt) {
            pr = povt % 10;
            povt = povt / 10;
            if (pr % 2 == 0)
                break;
            if (povt)
                std::cout << i;
        }
    }
}