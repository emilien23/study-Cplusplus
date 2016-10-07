//by emilien23

#include "stdafx.h"
#include "iostream"
#include "Complex.h"

using namespace std;

Complex::Complex(double r, double i)
{
	real = r;
	imanginary = i;
}
Complex::Complex(const Complex &c)
{
	real = c.real;
	imanginary = c.imanginary;
}


Complex Complex::operator+(const Complex &complex) const
{
	Complex sum;
	sum.real = real + complex.real;
	sum.imanginary = imanginary + complex.imanginary;
	return sum;
}
Complex Complex::operator-(const Complex &complex) const
{
	Complex diff;
	diff.real = real - complex.real;
	diff.imanginary = imanginary - complex.imanginary;
	return diff;
}
Complex &Complex::operator=(const Complex &complex)
{
	real = complex.real;
	imanginary = complex.imanginary;
	return *this;
}

ostream &operator << (ostream &output, Complex &complex)
{
	output << '(' << complex.real << ',' << complex.imanginary << ')';
	return output;
}
istream &operator >> (istream &input, Complex &complex)
{
	input.ignore(1);
	input >> complex.real;
	input.ignore(1);
	input >> complex.imanginary;
	input.ignore(1);
	return input;

}
Complex Complex::operator*(const Complex &complex) const
{
	Complex mul;
	mul.real = (real * complex.real) - (imanginary* complex.imanginary);
	mul.imanginary = (real * complex.imanginary) + (imanginary* complex.real);
	return mul;
}
Complex Complex::operator/(const Complex &complex) const
{
	Complex div;
	div.real = ((real * complex.real) + (imanginary* complex.imanginary))/(complex.real* complex.real + complex.imanginary * complex.imanginary);
	div.imanginary = ((imanginary* complex.real) - (real * complex.imanginary)) / (complex.real* complex.real + complex.imanginary * complex.imanginary);
	return div;
}
bool Complex::operator == (const Complex &c) const
{
	if (real == c.real && imanginary == c.imanginary)
		return true;
	return false;
}