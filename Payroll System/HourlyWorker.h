#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H
#include "ClassEmployee.h"

class HourlyWorker : public Employee
{
public:
	HourlyWorker(const char *name, const char *surname, const float rate, const int hours);
	const float GetRate() const;
	const int GetHours() const;
	void SetRate(float);
	void SetHours(int);
	float virtual Earnings();
	void virtual Print();
private:
	float rate;
	int hours;
};

#endif