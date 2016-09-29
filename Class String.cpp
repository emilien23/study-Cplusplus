// Class String.cpp: определяет точку входа для консольного приложения.
//By emilien_23

#include "stdafx.h"
#include "iostream"
#include "String.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	String str1("er"),str2("string"), str3(str2); //3 варианта объявления объектов класса Строка
	cout << "Введите строку номер 3" << endl;
	cin >> str3;
	str3 = str1; //присванивание объекта с помощью перегрузки операции
	cout << str3 << endl; //вывод строки после присваивания
	cout << str3[1] << endl; //вывод символа строки номер 3 обращением к индексу(реализована перегрузка операции)
	cout << !(str1) << endl; //пустая ли строка номер 1
	cout << str2.GetLength() << endl; //вывод длины строки 2
	cout << "s2 == s1 : " << (str2 == str1) << endl; //проверка перегруженных операций отношений
	cout << "s2 <= s1 : " << (str2 <= str1) << endl;
	cout << "s2 >= s1 : " << (str2 >= str1) << endl;
	cout << "s2 > s1 : " << (str2 > str1) << endl;
	cout << "s2 < s1 : " << (str2 < str1) << endl;
	cout << "s2 != s1 : " << (str2 != str1) << endl;
	str2 += str1; //сцепление строк
	cout << str2 << endl;
	cout << str2(0, 4) << endl; //вывод подстроки
	return 0;
}

