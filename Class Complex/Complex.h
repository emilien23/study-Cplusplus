//by emilien23

#ifndef COMPLEX_H
#define COMPLEX_H
#include "iostream"

using namespace std;
class Complex
{
	friend ostream &operator << (ostream &output, Complex &complex);
	friend istream &operator >> (istream &input, Complex &complex);
public:
	Complex(double = 0.0, double = 0.0);
	Complex(const Complex &);
	Complex operator + (const Complex &) const;
	Complex operator * (const Complex &) const;
	Complex operator - (const Complex &) const;
	Complex operator / (const Complex &) const;
	Complex &operator = (const Complex &);
	bool operator == (const Complex &);
private:
	double real;
	double imanginary;
};
#endif