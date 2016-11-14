

#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "ClassEmployee.h"

using namespace std;

Employee::Employee(const char *n,const char *s)
{
	name = new char[strlen(n) + 1];
	assert(name != 0);
	surname = new char[strlen(s) + 1];
	assert(surname != 0);
	strcpy_s(name, strlen(n) + 1, n);
	strcpy_s(surname, strlen(s) + 1, s);
}
Employee::~Employee()
{
	delete[] name;
	delete[] surname;
}
const char *Employee::GetName() const { return name;  }
const char *Employee::GetSurname() const { return surname; }

