// Class Array.cpp: определяет точку входа для консольного приложения.
//By emilien_23

#include "stdafx.h"
#include "iostream"
#include "Array.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "Количество созданных массивов на данный момент" << endl;
	cout << Array::GetArrayCount() << endl;
	Array array1(4), array2, array3(array1); //3 варианта объявления объектов класса Массив
	cout << "Количество созданных массивов после объявления" << endl;
	cout << Array::GetArrayCount() << endl;
	cout << "Введите элементы первого массива" << endl;
	cin >> array1;
	cout << "Введите элементы второго массива" << endl;
	cin >> array2;
	cout << "Введите элементы третьего массива" << endl;
	cin >> array3;
	cout << endl;
	array2 = array1; //присванивание объекта с помощью перегрузки операций
	if (array1 == array2) //проверка двух объектов на равенство 
		cout << "Они равны" << endl;
	else
		cout << "Они не равны" << endl;
	if (array1 != array3) //проверка двух объектов на неравенство
		cout << "Они не равны" << endl;
	else
		cout << "Они равны" << endl;
	array2.Sort(); // сортировка элементов объекта
	cout << "Массив после сортировки" << endl << array2 << endl;
	int indSearch = array3.Search(18);
	if ( indSearch != -1) // Поиск элемента в объекте
		cout << "Found. Index = "<< indSearch << endl;
	else
		cout << "Not found" << endl;
	array1.DeleteElement(1);// удаление элемента в объекте
	cout << "Массив после удаления элемента" << endl << array1 << endl;
	array1.AddElement(1, 345);// добавление элемента в объект
	cout << "Массив после добавления элемента" << endl << array1 << endl;
	array3.Reverse();// перевернуть массив
	cout << "Массив после Reverse" << endl << array3 << endl;
	array2.Coup(array3); // сцепление двух массивов
	cout << "Сцепление двух массивов" << endl << array2 << endl;
	return 0;
}

