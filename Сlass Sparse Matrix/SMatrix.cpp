#include "stdafx.h"
#include <iostream>
#include "SMatrix.h"


using namespace std;

Sparse_Matrix::Sparse_Matrix(int rows, int cols, int def)
{
	n_rows = rows;
	n_cols = cols;
	daf_value = def;
	Head = new Cell;
	Head->row = -1;
	Head->col = -1;

	Cell *temp = Head;  // создаем массив строк
	for (int i = 0; i<rows; i++)
	{
		Cell *tempr = new Cell;
		tempr->col = -1;
		tempr->row = i;
		tempr->right = NULL;
		temp->down = tempr;
		temp = tempr;
	}
	temp->down = NULL;
	Cell *temp1 = Head;  // создаем массив столбцов
	for (int i = 0; i<cols; i++)
	{
		Cell *tempc = new Cell;
		tempc->col = i;
		tempc->row = -1;
		tempc->down = NULL;
		temp1->right = tempc;
		temp1 = tempc;
	}
	temp1->right = NULL;

}

Sparse_Matrix::~Sparse_Matrix()
{
	Cell *temp = Head;
	int countr = n_rows + 1;
	while (countr != 0)
	{
		Cell *tempr = temp->down;
		while (temp->right != NULL)
		{
			Cell * tempc = temp->right;
			delete temp;
			temp = tempc;
		}
		countr--;
	}
}


int Sparse_Matrix::r_access(int rows, int cols) const
{
	Cell *temp = Head;
	while (temp->row < rows)
		temp = temp->down;
	while (temp->right != NULL && temp->col <= cols)
		temp = temp->right;
	if (temp->col == cols)
		return temp->data;
	else return daf_value;
}

int &Sparse_Matrix::w_access(int rows, int cols)
{
	//идем по строкам и находим нужную
	Cell *prev = Head;
	while (prev->row != rows)
		prev = prev->down;
	//идем по строкам
	while (prev->right != NULL && prev->right->col <= cols)
	{
		prev = prev->right;
	}
	if (prev->col == cols)
		return prev->data;
	else {
		Cell *temp = new Cell;
		temp->right = prev->right;
		prev->right = temp;
		Cell *tempc = Head;
		while (tempc->col != cols)
			tempc = tempc->right;
		while (tempc->down != NULL && tempc->down->row <= rows)
		{
			tempc = tempc->down;
		}
		temp->down = tempc->down;
		tempc->down = temp;
		temp->col = cols;
		temp->row = rows;
		temp->data = daf_value;
		return temp->data;
	}

}

//void Sparse_Matrix::print_c()

void Sparse_Matrix::print()
{	
	Cell *temp = Head->down;
	int count = n_rows;
	while (count != 0)
	{
		bool b = false;
		Cell *temp3 = temp;
		Cell *temp1 = temp3;
		while (temp1->right != NULL)
		{
			b = true;
			Cell *temp2 = temp1->right;
			//if (temp2->data != 0)
				cout << "[(" << temp2->row << "," << temp2->col << ") " << temp2->data << "] ";
			temp1 = temp2;
		}
		temp = temp->down;
		count--;
		if (b == true) cout << endl;
	}
}