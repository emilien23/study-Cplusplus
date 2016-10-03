//by emilien23
#ifndef DATE_H
#define DATE_H
#include "iostream"

using namespace std;

class Date
{
	friend ostream &operator << (ostream &output, const Date &d);
public:
	Date(int = 1, int = 1, int = 1900);
	void SetDate(int, int, int);
	Date &operator += (int); //изменение даты
	Date operator++(const int);//прибавление дня инкрементно
	Date operator++();//прибавление дня декрементно
	bool LeapYear(int yy) const;
	bool EndofMounth(int mounth);
	bool operator > (Date &d1) const;
	bool operator < (Date &d1) const;
private:
	int day;
	int mounth;
	int year;
	static int mounths[];
	void helpIncrement(Date &d1);
	
};
#endif