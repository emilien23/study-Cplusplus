//By emilien_23
#ifndef STRING_H
#define STRING_H
#include "iostream"
using namespace std;
class String
{	
	friend istream &operator >> (istream &input, String &str);
	friend ostream &operator << (ostream &output, String &str);
public:
	String(const char* = "");
	String(String &str);
	~String();
	String &operator = (const String &str);
	String &operator += (const String &str);
	char &operator [] (const int index) const;
	bool operator !() const;
	bool operator == (String &str) const;
	bool operator != (String &str) const;
	bool operator <= (String &str) const;
	bool operator >= (String &str) const;
	bool operator < (String &str) const;
	bool operator > (String &str) const;
	String &operator () (const int index1, const int sublength);
	int GetLength() const;
private:
	
	char *string;
	int length;
};
#endif