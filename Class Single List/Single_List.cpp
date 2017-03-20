// 2nomer02.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <windows.h> 


using namespace std;

struct Single_node
{
	Single_node * Next;
	int val;
};

class Single_list
{
private:
	Single_node * Head;
	Single_node * Tail;
public:
	Single_list();
	Single_list(int);
	~Single_list(); 
	bool empty(); 
	void push_front(int); 
	void pop_front(); 
	int size(); 
	void clear(); 
	int &front(); 
	void print(); 
};

Single_list::Single_list()
{
	Tail = new Single_node();
	Head = Tail;
}
Single_list::Single_list(int x)
{
	Single_list();
	push_front(x);
}
void Single_list::print()
{
	Single_node *temp = Head;
	while (temp != Tail)
	{
		cout << temp->val << endl;
		temp = temp->Next;
	}
}
int Single_list::size()
{
	Single_node *temp = Head;
	int size = 0;
	while (temp != Tail)
		size++;
	return size;
}
bool Single_list::empty()
{
	return Head == Tail ? true : false;
}
Single_list::~Single_list()
{
	clear();
}
void Single_list::clear()
{
	while (Head != Tail)
		pop_front();
}


void Single_list::push_front(int x)
{
	Single_node *temp = new Single_node;
	temp->val = x;
	temp->Next = Head;
	Head = temp;
}
void Single_list::pop_front()
{
	Single_node *temp = Head->Next;
	delete Head;
	Head = temp;
}
int &Single_list::front()
{
	return Head->val;
}




int _tmain(int argc, _TCHAR* argv[])
{int n;
	int x;
	Single_list l;

	cout << "dlina spiska" <<endl;
	cin >> n;
	cout << l.empty() << endl;
	for (int i = 0; i<n; i++)
	{
		cout << "x" << i+1<< ": ";
		cin >> x;
		l.push_front(x);
	}
	l.print();
	int h = l.front();
	cout << h << endl;
	return 0;
}

