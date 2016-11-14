#ifndef BOSS_H
#define BOSS_H
#include "ClassEmployee.h"

class Boss : public Employee
{
public:
	Boss(const char *name, const char *surname, const int salary);
	const int GetSalary() const;
	void SetSalary(int);
	float virtual Earnings();
	void virtual Print();
private:
	int salary;
};

#endif