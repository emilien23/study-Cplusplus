//By emilien_23
#ifndef ARRAY_H
#define ARRAY_H

#include "iostream"
using namespace std;

class Array
{
	friend istream &operator >> (istream &input, Array &ar);
	friend ostream &operator << (ostream &output, Array &ar);
public:
	Array(int = 10); //по умолчанию размера массива равен 10
	Array(Array &ar); //создает копию элемента
	~Array();
	Array operator = (const Array &ar);
	int operator == (const Array &ar) const;
	int operator != (const Array &ar) const;
	int &operator [] (int value) const;
	static int GetArrayCount();
	void Sort(); 
	int Search(const int value) const; //поиск по массиву
	Array DeleteElement(const int index); //удаление 
	Array AddElement(const int index, const int value);//добавление
	Array Reverse();//перевернуть массив
	Array Coup(Array &ar);//coup - сцепление
	
private:
	int *ptr;
	int size;
	static int count;
	bool Choose();
};
#endif