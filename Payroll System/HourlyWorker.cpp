#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "ClassEmployee.h"
#include "HourlyWorker.h"

using namespace std;

HourlyWorker::HourlyWorker(const char *n, const char *s, const float r, const int h) : Employee(n, s)
{
	rate = r;
	hours = h;
}

const float HourlyWorker::GetRate() const { return rate; }
const int HourlyWorker::GetHours() const { return hours; }

float HourlyWorker::Earnings() { return rate * hours; }

void HourlyWorker::SetRate(float r)
{
	rate = r > 0 ? r : 0;
}
void HourlyWorker::SetHours(int h)
{
	hours = h > 0 ? h : 0;
}
void HourlyWorker::Print() 
{
	cout << "ѕочасовой рабочий  " << GetName() << " " << GetSurname() << " заработал за неделю = " << Earnings() << endl;
}
