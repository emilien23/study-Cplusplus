#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "ClassEmployee.h"
#include "ComissionWorker.h"

using namespace std;

ComissionWorker::ComissionWorker(const char *n, const char *s, const float p, const int c, const int bs) : Employee(n, s)
{
	percent = p > 0 && p <= 100 ? p : 0;
	count = c;
	basesalary = bs;
}

const float ComissionWorker::GetPercent() const { return percent; }

const int ComissionWorker::GetCount() const { return count; }

const int ComissionWorker::GetBaseSalary() const{ return basesalary; }

float ComissionWorker::Earnings() { return basesalary + (percent * count); }

void ComissionWorker::SetPercent(float p)
{
	percent = p > 0 && p <= 100 ? p : 0;
}
void ComissionWorker::SetBaseSalary(int bs)
{
	basesalary = bs > 0 ? bs : 0;
}
void ComissionWorker::SetCount(int c)
{
	count = c > 0 ? c : 0;
}
void ComissionWorker::Print()
{
	cout << " омиссионный рабочий " << GetName() << " " << GetSurname() << " заработал за неделю = " << Earnings() << endl;
}