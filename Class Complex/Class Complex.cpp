// Class Complex.cpp: определяет точку входа для консольного приложения.
//by emilien23

#include "stdafx.h"
#include "iostream"
#include "Complex.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Complex c1(8.0,2.3), c2(23.8,5.6), c3;
	cin >> c3;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	if (c1 == c3)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "c1 - c2 = " << c1 - c2 << endl;
	cout << "c1 * c2 = " << c1 * c2 << endl;
	cout << "c1 / c2 = " << c1 / c2 << endl;
	cout << "c1 = c3 = " << endl;
	cout << c1 << endl;
	return 0;
}

