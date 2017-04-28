#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include "queue"
#include "Binary_tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

Binary_tree::Binary_tree()
{
	root = 0;
}

Binary_tree::Binary_tree(int x) //т.е. у нас сейчас только корень дерева
{
	root = new Tree_node;
	root->leftchild = NULL;
	root->rightchild = NULL;
	root->val = x;
}
void Binary_tree::clean(Tree_node *root)
{
	if (root)
	{
		clean(root->leftchild);
		clean(root->rightchild);
		delete root;
	}
}
Binary_tree::~Binary_tree()
{
	clean(root);
}

bool Binary_tree::add(int x)  //сoздаем элемент
{
	if (root == 0)
	{
		root = new Tree_node;
		root->leftchild = NULL;
		root->rightchild = NULL;
		root->val = x;
		return true;
	}
	Tree_node *temp = root;
	Tree_node *prev = temp;
	while (temp)
	{
		prev = temp;
		if (x<prev->val)
			temp = temp->leftchild;
		else if (x>prev->val)
			temp = temp->rightchild;
		else return false;
	}
	if (x<prev->val)
	{
		Tree_node *node = new Tree_node;
		prev->leftchild = node;
		node->leftchild = NULL;
		node->rightchild = NULL;
		node->val = x;
	}
	else
	{
		Tree_node *node = new Tree_node;
		prev->rightchild = node;
		node->leftchild = NULL;
		node->rightchild = NULL;
		node->val = x;
	}
	return true;

}

void Binary_tree::print_level_order()
{
	print_levelO(root);
	cout << endl;
}

void Binary_tree::print_levelO(Tree_node *temp)
{
	if (temp == 0)
		return;
	queue <Tree_node *> q;
	q.push(temp);
	while (!q.empty())
	{
		if (temp->leftchild)
			q.push(temp->leftchild);
		if (temp->rightchild)
			q.push(temp->rightchild);
		cout << (q.front())->val << " ";
		q.pop();
		temp = q.front();
	}
}
void Binary_tree::print_with(Tree_node * p, int level)
{
	if (p)
	{
		print_with(p->rightchild, level + 1);
		for (int i = 0; i< level; i++) cout << "   ";
		cout << p->val << endl;
		print_with(p->leftchild, level + 1);
	}
	if (!p)
	{
		for (int i = 0; i < level; i++) cout << "   ";
		cout << "@" << endl;
	}
}

void Binary_tree::print()
{
	print_with(root, 0);
	cout << endl;
}

int Binary_tree::_sum(Tree_node *root)
{
	return root ? (root->val) + (_sum(root->leftchild)) + (_sum(root->rightchild)) : 0;
}

int Binary_tree::sum()
{
	return _sum(root);
}

int Binary_tree::height()
{
	return _height(root);
}
int Binary_tree::_height(Tree_node* root){
	int l, r, h = 0;
	if (root){
		l = _height(root->leftchild);
		r = _height(root->rightchild);
		h = ((l > r) ? l : r) + 1;
	}
	return h;
}
void Binary_tree::print_inO(Tree_node *t)
{
	if (t)
	{
		print_inO(t->leftchild);
		cout << t->val << " ";
		print_inO(t->rightchild);
	}
}
void Binary_tree::print_in_order()
{
	print_inO(root);
	cout << endl;
}
void Binary_tree::print_preO(Tree_node *t)
{
	if (t)
	{
		cout << t->val << " ";
		print_preO(t->leftchild);
		print_preO(t->rightchild);
	}
}
void Binary_tree::print_pre_order()
{
	print_preO(root);
	cout << endl;
}
void Binary_tree::print_postO(Tree_node *t)
{
	if (t)
	{
		print_postO(t->leftchild);
		print_postO(t->rightchild);
		cout << t->val << " ";
	}
}
void Binary_tree::print_post_order()
{
	print_postO(root);
	cout << endl;
}

void Binary_tree::remove(int x)
{
	Tree_node *temp = root;
	Tree_node *prev = temp;
	while (temp && temp->val != x)
	{
		if (x<temp->val)
		{
			prev = temp;
			temp = temp->leftchild;
		}
		else if (x>temp->val)
		{
			prev = temp;
			temp = temp->rightchild;
		}
	}
	if (temp) //нашли такой элемент
	{
		if (!temp->rightchild && !temp->leftchild) //cлучай 1         если лист
		{
			if (prev->rightchild == temp)
				prev->rightchild = NULL;
			else
				prev->leftchild = NULL;
			delete temp;
		}
		else  if (temp->leftchild == NULL)        //случай 2  когда левый ноль
		{
			Tree_node *r = temp->rightchild;
			if (prev->rightchild == temp)
				prev->rightchild = r;
			else
				prev->leftchild = r;
			delete temp;
		}
		else if (temp->rightchild == NULL)  //случай 3  когда правый ноль
		{
			Tree_node *l = temp->leftchild;
			if (prev->rightchild == temp)
				prev->rightchild = l;
			else
				prev->leftchild = l;
			delete temp;
		}
		else                            //случай 4  когда сождержит 2 узла
		{
			Tree_node *temp2 = temp->rightchild;
			Tree_node *prev2 = temp2;
			while (temp2->leftchild)//ищем тот который надо вставить вместо удаляемого узла
			{
				prev2 = temp2;
				temp2 = temp2->leftchild;
			}
			temp->val = temp2->val;
			//сейчас нам надо удалить тот элемент, значение кот мы взяли
			Tree_node *r = temp2->rightchild;
			if (temp2 != prev2)
				prev2->leftchild = r;
			else
				temp->rightchild = r;
			delete temp2;
		}
	}
}

