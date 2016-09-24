// Class Array.cpp: ���������� ����� ����� ��� ����������� ����������.
//By emilien_23

#include "stdafx.h"
#include "iostream"
#include "Array.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "���������� ��������� �������� �� ������ ������" << endl;
	cout << Array::GetArrayCount() << endl;
	Array array1(4), array2, array3(array1); //3 �������� ���������� �������� ������ ������
	cout << "���������� ��������� �������� ����� ����������" << endl;
	cout << Array::GetArrayCount() << endl;
	cout << "������� �������� ������� �������" << endl;
	cin >> array1;
	cout << "������� �������� ������� �������" << endl;
	cin >> array2;
	cout << "������� �������� �������� �������" << endl;
	cin >> array3;
	cout << endl;
	array2 = array1; //������������� ������� � ������� ���������� ��������
	if (array1 == array2) //�������� ���� �������� �� ��������� 
		cout << "��� �����" << endl;
	else
		cout << "��� �� �����" << endl;
	if (array1 != array3) //�������� ���� �������� �� �����������
		cout << "��� �� �����" << endl;
	else
		cout << "��� �����" << endl;
	array2.Sort(); // ���������� ��������� �������
	cout << "������ ����� ����������" << endl << array2 << endl;
	int indSearch = array3.Search(18);
	if ( indSearch != -1) // ����� �������� � �������
		cout << "Found. Index = "<< indSearch << endl;
	else
		cout << "Not found" << endl;
	array1.DeleteElement(1);// �������� �������� � �������
	cout << "������ ����� �������� ��������" << endl << array1 << endl;
	array1.AddElement(1, 345);// ���������� �������� � ������
	cout << "������ ����� ���������� ��������" << endl << array1 << endl;
	array3.Reverse();// ����������� ������
	cout << "������ ����� Reverse" << endl << array3 << endl;
	array2.Coup(array3); // ��������� ���� ��������
	cout << "��������� ���� ��������" << endl << array2 << endl;
	return 0;
}

