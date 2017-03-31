#include "stdafx.h"
#include <iostream>


struct Cell
{
	int row;
	int col;
	int data;
	Cell *right;
	Cell *down;
};

class Sparse_Matrix
{
private:
	int n_rows;
	int n_cols;
	int daf_value;
	Cell *Head;
public:
	Sparse_Matrix(int, int, int);
	int r_access(int rows, int cols) const;
	int &w_access(int rows, int cols);
	~Sparse_Matrix();
	void print();
};