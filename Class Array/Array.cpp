//By emilien_23
#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "algorithm"
#include "Array.h"

using namespace std;

int Array::count = 0;
Array::Array(int arraysize)
{
	++count;
	size = arraysize;
	ptr = new int [size];
	assert(ptr != 0);
	for (int i = 0; i < size; i++)
		ptr[i] = 0;
}

Array::Array(Array &ar)
{
	++count;
	size = ar.size;
	ptr = new int[size];
	assert(ptr != 0);

	for (int i = 0; i < size; i++)
		ptr[i] = ar.ptr[i];
}

Array::~Array(){ --count; delete[]ptr; }

int Array::GetArrayCount() { return count; }

Array Array::operator=(const Array &ar)
{
	if (&ar != this)
	{
		delete[]ptr;
		size = ar.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++)
			ptr[i] = ar.ptr[i];
	}
	return *this;
}
int Array::operator==(const Array &ar) const
{
	if (size != ar.size)
		return 0;
		for (int i = 0; i < size; i++)
			if (ptr[i] != ar.ptr[i])
				return 0;
		return 1;
}
int Array::operator!=(const Array &ar) const
{
	if (size != ar.size)
		return 1;
	for (int i = 0; i < size; i++)
		if (ptr[i] != ar.ptr[i])
			return 1;
	return 0;
}
int &Array::operator[] (int value) const
{
	assert(0 <= value && value < size);
	return ptr[value];
}
istream &operator >> (istream &input, Array &ar)
{
	for (int i = 0; i < ar.size; i++)
		input >> ar.ptr[i];
	return input;
}
ostream &operator << (ostream &output, Array &ar)
{
	for (int i = 0; i < ar.size; i++)
		output << ar.ptr[i] << " ";
	return output;
}

void Array::Sort() { sort(ptr, ptr + size); }


int Array::Search(const int value) const
{
	for (int i = 0; i < size; i++)
		if (ptr[i] == value)
			return i;
	return -1;

}

Array Array::DeleteElement(const int index)
{
	assert(index >= 0 && index < size);
	if (size == 1)
	{
		if (!Choose())
			return *this;
		cout << "An array of removed." << endl;
		
	}
	Array ar(*this);
	delete[]ptr;
	ptr = new int[size - 1];
	size--;
	int i = 0;
	while (i != index)
	{
		ptr[i] = ar.ptr[i];
		i++;
	}
	while (i <= size)
	{
		ptr[i] = ar.ptr[i+1];
		i++;
	}
	return *this;
}
bool Array::Choose()
{
	int choose;
		cout << "You remove the last element in the array. Do you agree?" << endl;
		cout << "1 - Yes" << endl << "2 - No" << endl;
		cin >> choose;
		while (choose != 1 && choose != 2)
		{
			cout << "Invalid input. Try again:" << endl;
			cin >> choose;
		}
		if (choose == 1)
			return true;
		else
			return false;
}

Array Array::AddElement(const int index, const int value)
{
	assert(index >= 0 && index <= size);
	
	Array ar(*this);
	delete[]ptr;
	ptr = new int[size + 1];
	
	if (index == size)
	{
		for (int i = 0; i < size; i++)
			ptr[i] = ar.ptr[i];
		ptr[size] = value;
		
	}
	else
	{
		for (int i = 0; i < index; i++)
			ptr[i] = ar.ptr[i];
		ptr[index] = value;
		for (int i = index + 1; i <= size; i++)
			ptr[i] = ar.ptr[i - 1];
	}
	size++;
	return *this;
}

Array Array::Reverse()
{
	Array ar(*this);
	int j = size - 1;
	for (int i = 0; i < size; i++)
	{
		ptr[i] = ar.ptr[j];
		j--;
	}
	return *this;
}
Array Array::Coup(Array &ar)
{
	Array array(*this);
	int coupsize = size + ar.size;

	delete[]ptr;
	ptr = new int[coupsize];
	size = coupsize;
	int i = 0;
	while (i < array.size)
	{
		ptr[i] = array.ptr[i];
		i++;
	}
	for (int j = 0; i < coupsize; i++, j++)
		ptr[i] = ar.ptr[j];
	return *this;
}




