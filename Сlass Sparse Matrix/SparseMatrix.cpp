// 3nomer3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "SMatrix.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;





int main(int argc, char** argv)
{
	Sparse_Matrix k(3, 5, -1);
	k.w_access(2, 3) = -7;
	cout << k.w_access(2, 3) << endl;
	k.print();
	cout << k.r_access(0, 1) << endl;
	k.w_access(2, 4) = -5;
	k.print();
	k.w_access(2, 1) = -4; k.w_access(2, 0) = -4;
	k.print();
	k.w_access(0, 1) = -8; k.w_access(1, 3) = -9;
	k.print();
	for (int i = 0; i<3; i++)
		for (int j = 0; j<5; j++)
			k.w_access(i, j) = i + j;
	k.print();
	//cout << k.r_access(0, 0);
	system("PAUSE");
	return 0;
}


