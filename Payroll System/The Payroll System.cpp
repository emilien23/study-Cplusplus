// The Payroll System.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "ClassEmployee.h"
#include "ComissionWorker.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"
#include "Boss.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	Employee *ptr, *ptr1, *ptr2, *ptr3;
	Boss boss("Иван", "Кабанов", 50000);
	ptr = &boss;
	ptr->Print();
	cout << endl;
	HourlyWorker hourly("Петр", "Петров", 120, 40);
	ptr1 = &hourly;
	ptr1->Print();
	cout << endl;
	PieceWorker piece("Аркадий", "Власов", 120, 30);
	ptr2 = &piece;
	ptr2->Print();
	cout << endl;
	ComissionWorker comission("Владимир", "Карчинский", 4.0, 250, 2500);
	ptr3 = &comission;
	ptr3->Print();
	cout << endl;
	return 0;
}

