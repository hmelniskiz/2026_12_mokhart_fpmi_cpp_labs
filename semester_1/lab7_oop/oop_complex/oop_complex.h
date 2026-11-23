#pragma once

#include <iostream>
#include <cmath>

class Complex {
private:
    double Re;
    double Im;

public:
    Complex(double Re = 0, double Im = 0) {
        this->Re = Re;
        this->Im = Im;
    }

    Complex(const Complex& other) {
        Re = other.Re;
        Im = other.Im;
    }

    Complex& operator=(const Complex& other) {
        Re = other.Re;
        Im = other.Im;
        return *this;
    }

    bool operator==(const Complex& other) const {
        if (Re == other.Re && Im == other.Im)
            return true;
        return false;
    }

    bool operator!=(const Complex& other) const {
        if (Re != other.Re || Im != other.Im)
            return true;
        return false;
    }

    Complex operator+() const {
        return *this;
    }

    Complex operator-() const {
        Complex a;
        a.Re = -Re;
        a.Im = -Im;
        return a;
    }

    Complex operator+(const Complex& other) const {
        Complex a;
        a.Re = Re + other.Re;
        a.Im = Im + other.Im;
        return a;
    }

    Complex operator+(double scalar) const {
        Complex a;
        a.Re = Re + scalar;
        a.Im = Im;
        return a;
    }

    Complex operator-(const Complex& other) const {
        Complex a;
        a.Re = Re - other.Re;
        a.Im = Im - other.Im;
        return a;
    }

    Complex operator-(double scalar) const {
        Complex a;
        a.Re = Re - scalar;
        a.Im = Im;
        return a;
    }

    Complex operator*(const Complex& other) const {
        Complex a;
        a.Re = Re * other.Re - Im * other.Im;
        a.Im = Re * other.Im + Im * other.Re;
        return a;
    }

    Complex operator*(double scalar) const {
        Complex a;
        a.Re = Re * scalar;
        a.Im = Im * scalar;
        return a;
    }

    Complex operator/(const Complex& other) const {
        Complex a;
        if (other.Re * other.Re + other.Im * other.Im == 0) {
            std::cout << "delenie na 0";
            return a;
        }
        a.Re = (Re * other.Re + Im * other.Im) / (other.Re * other.Re + other.Im * other.Im);
        a.Im = (Im * other.Re - Re * other.Im) / (other.Re * other.Re + other.Im * other.Im);
        return a;
    }

    Complex operator/(double scalar) const {
        Complex a;
        if (scalar == 0) {
            std::cout << "delenie na 0";
            return a;
        }
        a.Re = Re / scalar;
        a.Im = Im / scalar;
        return a;
    }

    Complex& operator+=(const Complex& other) {
        Re = Re + other.Re;
        Im = Im + other.Im;
        return *this;
    }

    Complex& operator+=(double scalar) {
        Re = Re + scalar;
        return *this;
    }

    Complex& operator-=(const Complex& other) {
        Re = Re - other.Re;
        Im = Im - other.Im;
        return *this;
    }

    Complex& operator-=(double scalar) {
        Re = Re - scalar;
        return *this;
    }

    Complex& operator*=(const Complex& other) {
        Complex a;
        a.Re = Re * other.Re - Im * other.Im;
        a.Im = Re * other.Im + Im * other.Re;
        *this = a;
        return *this;
    }

    Complex& operator*=(double scalar) {
        Re = Re * scalar;
        Im = Im * scalar;
        return *this;
    }

    Complex& operator/=(const Complex& other) {
        Complex a;
        if (other.Re * other.Re + other.Im * other.Im == 0) {
            std::cout << "delenie na 0";
            return *this;
        }
        a.Re = (Re * other.Re + Im * other.Im) / (other.Re * other.Re + other.Im * other.Im);
        a.Im = (Im * other.Re - Re * other.Im) / (other.Re * other.Re + other.Im * other.Im);
        *this = a;
        return *this;
    }

    Complex& operator/=(double scalar) {
        if (scalar == 0) {
            std::cout << "delenie na 0";
            return *this;
        }
        Re = Re / scalar;
        Im = Im / scalar;
        return *this;
    }

    double Real() const {
        return Re;
    }

    void Real(double Re) {
        this->Re = Re;
    }

    double Imag() const {
        return Im;
    }

    void Imag(double Im) {
        this->Im = Im;
    }

    double Abs() const {
        return sqrt(Re * Re + Im * Im);
    }

    friend Complex operator+(const double lef, const Complex& rig);
    friend Complex operator-(const double lef, const Complex& rig);
    friend Complex operator*(const double lef, const Complex& rig);
    friend Complex operator/(const double lef, const Complex& rig);
    friend std::ostream& operator<<(std::ostream& out, const Complex& rig);
    friend std::istream& operator>>(std::istream& in, Complex& rig);
};