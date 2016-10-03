// Class Date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "Date.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	Date d(30, 9, 2016), d1;
	d += 40;
	cout << d << endl;
	cout << d++ << endl;
	cout << ++d << endl;
	if (d1 > d)
		cout << "d1 > d" << endl;
	else
		cout << "d1 <= d" << endl;
	return 0;
}

