#pragma once
#include <iostream>
class Tree
{
private:
	class node
	{
	public:
		node *parent;
		node *children;
		node *brother;
		int key;

		node(int key, node *parent = NULL, node *children = NULL, node *brother = NULL)
		{
			this->key = key;
			this->parent = parent;
			this->children = children;
			this->brother = brother;
		}
	};
	node * root;
public:
	Tree() { this->root = NULL; }
	node* getRoot() { return root; }
	void push(int key, node *curNode = NULL);
	void show_symmetric(node *curNode = NULL);
	void show_straight(node *curNode = NULL);
	void show_reverse(node *curNode = NULL);
	void merging(Tree & B, node *curNode = NULL);
	~Tree() {};
};

