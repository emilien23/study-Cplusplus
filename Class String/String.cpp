//By emilien_23
#include "stdafx.h"
#include "iostream"
#include "String.h"
#include "assert.h"

using namespace std;


String::String(const char* s)
{
		length = strlen(s);
		string = new char[length + 1];
		assert(string != 0);
		strcpy_s(string, length + 1, s);
}

String::String(String &str)
{
	if (this != &str)
	{
		delete[]string;
		string = new char[str.length + 1];
		assert(string != 0);
		length = str.length;
		strcpy_s(string, length + 1, str.string);
	}
}

istream &operator >> (istream &input, String &str)
{
	char *buffer = new char[str.length + 1];
	input >> buffer;
	str = buffer;
	delete buffer;
	return input;
}

ostream &operator << (ostream &output, String &str)
{
	output << str.string;
		return output;
}
String &String::operator = (const String &str)
{
	if (this != &str)
	{	
		delete[]string;
		length = str.length;
		string = new char[length + 1];
		assert(string != 0);
		strcpy_s(string, length + 1, str.string);
	}
	return *this;
}

int String::GetLength() const { return length;  }

String::~String()
{
	length = 0;
	delete[]string;
}

String &String::operator += (const String &str)
{	
	char *s = string;
	length += str.length;
	string = new char[length + 1];
	assert(string != 0);
	strcpy_s(string, strlen(s)+ 1, s);
	strcat_s(string, length + 1, str.string);
	
	return *this;
}

char &String::operator [] (const int index) 
{ 
	assert(index >= 0 && index < length);
	return string[index];
}

bool String::operator !() const
{
	return (length == 0) ? true : false;
}

bool String::operator == (String &str) const
{
	if (length != str.length)
		return false;
	for (int i = 0; i < length; i++)
		if (string[i] != str.string[i])
			return false;
	return true;

}

bool String::operator != (String &str) const
{
	if (length != str.length)
		return true;
	for (int i = 0; i < length; i++)
		if (string[i] != str.string[i])
			return true;
	return false;

}

bool String::operator < (String &str) const
{
	if (length < str.length)
		return true;
	if (length > str.length)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (string[i] > str.string[i])
			return false;
		if (string[i] < str.string[i])
			return true;
	}
	return false;

}

bool String::operator > (String &str) const
{
	if (length < str.length)
		return false;
	if (length > str.length)
		return true;
	for (int i = 0; i < length; i++)
	{
		if (string[i] < str.string[i])
			return false;
		if (string[i] > str.string[i])
			return true;
	}
	return false;

}

bool String::operator >= (String &str) const
{
	if (length < str.length)
		return false;
	if (length > str.length)
		return true;
	for (int i = 0; i < length; i++)
	{
		if (string[i] < str.string[i])
			return false;
		if (string[i] > str.string[i])
			return true;
	}
	return true;


}
bool String::operator <= (String &str) const
{
	if (length < str.length)
		return true;
	if (length > str.length)
		return false;
	for (int i = 0; i < length; i++)
	{
		if (string[i] > str.string[i])
			return false;
		if (string[i] < str.string[i])
			return true;
	}
	return true;
}

String &String::operator () (const int index, const int sublength)
{
	assert(sublength >= 0 && index >= 0 && index < length);
	char* substring;
	if (sublength == 0 || index + sublength > length)
		substring = new char[length - index + 1];
	else
		substring = new char[sublength + 1];
	assert(substring != 0);
	strncpy_s(substring, strlen(substring), &string[index], sublength);
	length = strlen(substring);
	delete[]string;
	string = new char[length + 1];
	strcpy_s(string, length + 1, substring);
	
	return *this;
}