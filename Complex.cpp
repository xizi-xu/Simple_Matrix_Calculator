#include <iostream>
#include <iomanip>
#include <math.h> 
#include "Complex.h"

using namespace std;
//Friends implementations
//<< overloading
ostream &operator<<(ostream &output, const Complex &num) {
	char sign = '+';
	double temp = num.imag;
	if (temp < 0) {
		sign = '-';
		temp *= -1;
	}
	output << num.real << " " << sign << " i" << temp;
	return output; 
}

//>> overloading
istream &operator>>(istream &input, Complex &num) {
	char sign;
	//read real part
	input >> num.real;
	input.ignore();
	//read the sign
	input >> sign;
	input.ignore();
	//ignore "i"
	input.ignore();
	//read imag part
	input >> num.imag;

	if (sign == '-'){
		num.imag *= -1;
	}
	return input;
}

//+ overloading for double + complex
Complex operator+(double n, const Complex &num) {
    return Complex(num.real + n, num.imag);
}

//abs() function
double abs(Complex &num) {
	return sqrt(num.real*num.real + num.imag*num.imag);
}

///////////////////////////////////////////////////////////

//Class members implementations
//constructor
Complex::Complex(double x, double y){
	real = x;
	imag = y;
}

//predecrement: --complex
Complex &Complex::operator--() {
	--real;
	return *this;
}

//postdecrement: complex--
Complex Complex::operator--(int) {
	Complex temp = *this;
	--real;
	//return unchanged, saved temporary object
	return temp;
}

//* overloading
Complex Complex::operator*(const Complex &num1) {
	double result_real = num1.real * real - num1.imag * imag;
    double result_imag = num1.real * imag + real * num1.imag;
    return Complex(result_real, result_imag);
}


//+: complex + double
Complex Complex::operator+(const double &num) {
	return Complex(real+num, imag);
}

//+: complex + complex
Complex Complex::operator+(const Complex &num) {
	double result_real = real + num.real;
    double result_imaginary = imag + num.imag;
    return Complex(result_real, result_imaginary);
}
