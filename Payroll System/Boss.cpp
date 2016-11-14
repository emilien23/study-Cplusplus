#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "ClassEmployee.h"
#include "Boss.h"

using namespace std;

Boss::Boss(const char *n, const char *s, const int sal) : Employee(n, s)
{
	salary = sal > 0 ? sal : 0;
}

const int Boss::GetSalary() const { return salary; }

float Boss::Earnings() { return salary; }

void Boss::SetSalary(int s)
{
	s = s > 0 ? s : 0;
}
void Boss::Print()
{
	cout << "Начальник отдела  " << GetName() << " " << GetSurname() << " заработал за неделю = " << Earnings() << endl;
}