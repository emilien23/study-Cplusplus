#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H
#include "ClassEmployee.h"

class ComissionWorker : public Employee
{
public:
	ComissionWorker(const char *name, const char *surname, const float percent, const int count, const int basesalary);
	const float GetPercent() const;
	const int GetBaseSalary() const;
	void SetBaseSalary(int);
	const int GetCount() const;
	void SetPercent(float);
	void SetCount(int);
	float virtual Earnings();
	void virtual Print();
private:
	int percent;
	int count;
	int basesalary;
};

#endif