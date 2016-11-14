#ifndef PIECEWORKER_H
#define PIECEWORKER_H
#include "ClassEmployee.h"

class PieceWorker : public Employee
{
public:
	PieceWorker(const char *name, const char *surname, const float wagePerPiece, const int count);
	const float GetWage() const;
	const int GetCount() const;
	void SetWage(float);
	void SetCount(int);
	float virtual Earnings();
	void virtual Print();
private:
	float wagePerPiece; //ставка за шт
	int count; //количетсво продаж
};

#endif