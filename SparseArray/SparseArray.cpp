// 4nomer02.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

struct Cell
{
	int cal;
	Cell * right;
	int data;
};

class Sparse_Array
{
private:
	Cell *Head;
	int default_value;
public:
	Sparse_Array(int);
	~Sparse_Array();
	int &operator[] (int);
	void print();
};

Sparse_Array::Sparse_Array(int x)
{
	default_value = x;
	Head = new Cell();
	Head->cal = -1;
	Head->right = 0;
}

Sparse_Array::~Sparse_Array()
{
	while (Head != 0)   
	{
		Cell *temp = Head->right;
		Cell *t = temp->right;
		delete temp;
		Head->right = t;

	}
	delete Head;
}


void Sparse_Array::print()
{
	Cell *te = Head->right;
	while (te != 0)  
	{
		cout << "[" << te->cal << "," << te->data << "]" << " ";
		te = te->right;
	}
}


int &Sparse_Array::operator[] (int index)
{
		Cell *count = Head->right; 
		Cell *prev = Head;        
		while ( count && count->cal <= index) 
		{
			prev = prev->right;
			count = count->right;
		}
		if (prev->cal == index)
			return prev->data;
		else {
			Cell *t = new Cell;
			t->right = count;
			prev->right = t;
			t->cal = index;
			t->data = default_value;
			return t->data;
			}
}

int main(int argc, char** argv)
{
	Sparse_Array A(-1);
	cout << A[9] << endl;
	A[23] = 80;
	A[1000] = A[23] + A[16];
	A.print();
	system("PAUSE");
	return 0;
}

