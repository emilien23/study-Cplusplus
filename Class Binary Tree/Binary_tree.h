#include "stdafx.h"
#include <iostream>

struct Tree_node
{
	int val;
	Tree_node *leftchild;
	Tree_node *rightchild;
};

class Binary_tree
{
private:
	Tree_node *root; // корень дерева
public:
	Binary_tree();
	Binary_tree(int);
	~Binary_tree(); // делаем через post_order
	void clean(Tree_node*);
	bool add(int);
	void print_pre_order();
	void print_preO(Tree_node *);
	void print_in_order();
	void print_inO(Tree_node*);
	void print_post_order();
	void print_postO(Tree_node *);
	void print_level_order();
	void print_levelO(Tree_node *);
	void print();
	int height();
	int _height(Tree_node *);
	int sum();
	int _sum(Tree_node *);
	void print_with(Tree_node *, int);
	void remove(int);
	void _remove(int, Tree_node *, Tree_node *);//правильный красивый принт с @
	int findMin();
	Tree_node* _findMin(Tree_node *);
};
