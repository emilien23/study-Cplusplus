#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "ClassEmployee.h"
#include "PieceWorker.h"

using namespace std;

PieceWorker::PieceWorker(const char *n, const char *s, const float per, const int c) : Employee(n, s)
{
	wagePerPiece = per;
	count = c;
}

const float PieceWorker::GetWage() const { return wagePerPiece; }
const int PieceWorker::GetCount() const { return count; }

float PieceWorker::Earnings() { return wagePerPiece * count; }

void PieceWorker::SetWage(float per)
{
	wagePerPiece = per > 0 && wagePerPiece <= 100 ? per : 0;
}
void PieceWorker::SetCount(int c)
{
	count = c > 0 ? c : 0;
}
void PieceWorker::Print()
{
	cout << "Рабочий cо сдельной зарплатой " << GetName() << " " << GetSurname() << " заработал за неделю = " << Earnings() << endl;
}