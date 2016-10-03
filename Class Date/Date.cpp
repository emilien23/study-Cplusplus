//by emilien23
#include "stdafx.h"
#include "iostream"
#include "Date.h"

using namespace std;

int Date::mounths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(const int day1, const int mounth1, const int year1) { SetDate(day1, mounth1, year1); }

void Date::SetDate(int dd, int mm, int yy)
{
	mounth = (mm > 0 && mm <= 12) ? mm : 1;
	year = (yy > 0 && yy < 2100) ? yy : 1900;
	if (mounth == 2 && LeapYear(yy))
		day = (dd > 0 && dd <= 29) ? dd : 1;
	else
		day = (dd > 0 && dd <= mounths[mounth]) ? dd : 1;

}

bool Date::LeapYear(int yy) const
{
	if (yy % 400 == 0 || (yy % 100 == 0 && yy % 4 == 0))
		return true;
	else return false;
}
ostream &operator << (ostream &output, const Date &d)
{
	output << d.day << "/" << d.mounth << "/" << d.year;
	return output;
}
Date &Date::operator += (int addday)
{
	for (int i = 1; i <= addday;i++)
		helpIncrement(*this);
	return *this;
}
void Date::helpIncrement(Date &d)
{
	if (EndofMounth(d.day) && d.mounth == 12)
	{
		d.year++;
		d.day = 1;
		d.mounth = 1;
	}
	else if (EndofMounth(d.day))
	{
		d.mounth++;
		d.day = 1;
	}
	else
		d.day++;
}
bool Date::EndofMounth(int dd)
{
	return (day == mounths[mounth]) ? true : false;
}
Date Date::operator ++ ()
{
	helpIncrement(*this);
	return *this;
}
Date Date::operator ++ (int)
{
	Date temp = *this;
	helpIncrement(*this);
	return temp;
}
bool Date::operator > (Date &d1) const
{
	if (year < d1.year)
		return false;
	if (year > d1.year)
		return true;
	if (mounth < d1.mounth)
		return false;
	if (mounth > d1.mounth)
		return true;
	if (day > d1.day)
		return true;
	else
		return false;
}

bool Date::operator < (Date &d1) const
{
	if (year > d1.year)
		return false;
	if (year < d1.year)
		return true;
	if (mounth > d1.mounth)
		return false;
	if (mounth < d1.mounth)
		return true;
	if (day < d1.day)
		return true;
	else
		return false;
}