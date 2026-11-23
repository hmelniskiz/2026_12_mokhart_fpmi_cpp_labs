#include "oop_complex.h"
#include <iostream>
#include <cmath>

Complex operator+(const double lef, const Complex& rig) {
    Complex temp;
    temp.Re = lef + rig.Re;
    temp.Im = rig.Im;
    return temp;
}

Complex operator-(const double lef, const Complex& rig) {
    Complex temp;
    temp.Re = lef - rig.Re;
    temp.Im = -rig.Im;
    return temp;
}

Complex operator*(const double lef, const Complex& rig) {
    Complex temp;
    temp.Re = lef * rig.Re;
    temp.Im = lef * rig.Im;
    return temp;
}

Complex operator/(const double lef, const Complex& rig) {
    Complex temp;
    if (rig.Im * rig.Im + rig.Re * rig.Re == 0) {
        std::cout << "error";
        return temp;
    }
    temp.Re = (lef * rig.Re) / (rig.Im * rig.Im + rig.Re * rig.Re);
    temp.Im = -(lef * rig.Im) / (rig.Im * rig.Im + rig.Re * rig.Re);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Complex& rig) {
    if (rig.Im > 0)
        out << rig.Re << " + " << rig.Im << "i";
    else if (rig.Im < 0)
        out << rig.Re << " - " << -rig.Im << "i";
    else
        out << rig.Re;
    return out;
}

std::istream& operator>>(std::istream& in, Complex& rig) {
    in >> rig.Re >> rig.Im;
    return in;
}