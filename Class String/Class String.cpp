// Class String.cpp: ���������� ����� ����� ��� ����������� ����������.
//By emilien_23

#include "stdafx.h"
#include "iostream"
#include "String.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	String str1("er"),str2("string"), str3(str2); //3 �������� ���������� �������� ������ ������
	cout << "������� ������ ����� 3" << endl;
	cin >> str3;
	str3 = str1; //������������� ������� � ������� ���������� ��������
	cout << str3 << endl; //����� ������ ����� ������������
	cout << str3[1] << endl; //����� ������� ������ ����� 3 ���������� � �������(����������� ���������� ��������)
	cout << !(str1) << endl; //������ �� ������ ����� 1
	cout << str2.GetLength() << endl; //����� ����� ������ 2
	cout << "s2 == s1 : " << (str2 == str1) << endl; //�������� ������������� �������� ���������
	cout << "s2 <= s1 : " << (str2 <= str1) << endl;
	cout << "s2 >= s1 : " << (str2 >= str1) << endl;
	cout << "s2 > s1 : " << (str2 > str1) << endl;
	cout << "s2 < s1 : " << (str2 < str1) << endl;
	cout << "s2 != s1 : " << (str2 != str1) << endl;
	str2 += str1; //��������� �����
	cout << str2 << endl;
	cout << str2(0, 4) << endl; //����� ���������
	return 0;
}

