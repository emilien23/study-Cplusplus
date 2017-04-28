// 1nomer04.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Binary_tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv)
{
	Binary_tree s(5);
	s.add(3);
	s.add(9);
	s.add(1);
	s.add(4);
	s.add(2);
	s.add(7);
	s.add(12);
	s.add(6);
	s.add(8);
	
	//s.print_in_order();
	//cout << s.sum();
	s.remove(5);
	//s.print(); 
	s.print();
	return 0;
}


