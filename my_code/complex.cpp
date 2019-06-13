#include <iostream>
#include <istream>
#include <iomanip>
#include <cmath>
#include "complex.h"

using namespace std;

//Constructor
Complex::Complex(double r, double i) :
    real(r), imag(i) {}

//Input to create a Complex Number
istream& operator>> (istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

//Output
ostream& operator<< (ostream& os, const Complex& c) {
    /*
     * Outputting a `Complex` instance, while illustrating some of the
     * capabilities of I/O streams: `setprecision` gives us a fixed
     * number of decimal places, while `showpos` turns on the plus
     * sign for positive numbers.
     * */
    os << fixed << setprecision(1) << c.get_real() << " + " << 
    fixed << setprecision(1) << c.get_imag() << "i";
    return os;
}

//Comparison Overloading
bool operator== (const Complex& c1, const Complex& c2) {
    double margin = 0.001; //wasn't working with direct comparison, I believe due to c++ error
    if (abs(c1.get_real() - c2.get_real()) <= margin && abs(c1.get_imag() - c2.get_imag()) <= margin) {
        return true;
    }
    else {
        return false;
    }
}

//Boolean Overloading
Complex::operator bool() const {
    if (real != 0 || imag != 0) {return true;}
    else {return false;}
}

//++c Overloading
Complex& Complex::operator++() {
    real += 1;
    return *this;
}

//c++ Overloading
Complex Complex::operator++(int dummy) { // how do i return the old value with *this???????
    Complex val_before = *this;
    real += 1;
    return val_before;
}

//--c Overloading
Complex& Complex::operator--() {
    real -= 1;
    return *this;
}

//c-- Overloading
Complex Complex::operator--(int dummy) { // how do i return the old value with *this???????
    Complex val_before = *this;
    real -= 1;
    return val_before;
}


//Gets real number portion
double Complex::get_real() const {
    return real;
}

//Gets imaginary portion
double Complex::get_imag() const {
    return imag;
}

//Multiplies by a scalar
Complex Complex::operator*(const int i) {
    real *= i;
    imag *= i;
    return *this;
}

//Subtracts by another complex number
 Complex Complex::operator-(const Complex& c){
     return Complex(real - c.get_real(), imag - c.get_imag());
 }

//Subtracts by another number and assigns difference to self
Complex Complex::operator-=(const Complex& c){
    real -= c.get_real();
    imag -= c.get_imag();
    return *this;
}

//Addition with another complex number
 Complex Complex::operator+(const Complex& c){
     return Complex(real + c.get_real(), imag + c.get_imag());
 }

