#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex{
//friends:
	//<< and >> overloading
	friend std::ostream &operator<<(std::ostream &, const Complex &);
	friend std::istream &operator>>(std::istream &, Complex &);
	//+ overloading
	friend Complex operator+(double, const Complex &);
	//abs function
	friend double abs(Complex &);
	//friend double operator+(Complex);

public:
	//constructor
	Complex(double x = 0, double y = 0);
	//predecrement: --complex
	Complex &operator--();
	//postdecrement: complex--
	Complex operator--(int);
	//* overloading
	Complex operator*(const Complex &);
	//+: complex + double
	Complex operator+(const double &);
	//+: complex + complex
	Complex operator+(const Complex &);
	

private:
	double real;
	double imag;
};

#endif
