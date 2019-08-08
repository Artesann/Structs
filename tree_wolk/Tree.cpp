#include "Tree.h"



void Tree::push(int key, node *curNode)
{
	if (!curNode)
	{
		if (!root)
			this->root = new node(key);
		else
			push(key, root);
	}
	else
	{
		if (key <= curNode->key)
		{
			if (!curNode->children)
				curNode->children = new node(key, curNode);
			else if (curNode->children->key == NULL)
				curNode->children->key = key;
			else
				push(key, curNode->children);
		}
		else
		{
			if (curNode->children)
			{
				if (!curNode->children->brother)
					curNode->children->brother = new node(key, NULL, NULL, curNode->children);
				else
					push(key, curNode->children->brother);
			}
			else
			{
				curNode->children = new node(NULL, curNode);
				curNode->children->brother = new node(key, NULL, NULL, curNode->children);
			}
		}
	}

}

void Tree::show_symmetric(node * curNode)
{
	if (!curNode)
	{
		if (root)
		{
			if (root->children)
				show_symmetric(root->children);
			std::cout << root->key << " ";
			if (root->children)
				if (root->children->brother)
					show_symmetric(root->children->brother);
		}
	}
	else
	{
		if (curNode)
		{
			if (curNode->children)
				show_symmetric(curNode->children);
			if (curNode->key)
				std::cout << curNode->key << " ";
			if (curNode->children)
				if (curNode->children->brother)
					show_symmetric(curNode->children->brother);
		}
	}

}

void Tree::show_straight(node * curNode)
{
	if (!curNode)
	{
		if (root)
		{
			std::cout << root->key << " ";
			if (root->children)
				show_straight(root->children);
			if (root->children)
				if (root->children->brother)
					show_straight(root->children->brother);
		}
	}
	else
	{
		if (curNode->key)
			std::cout << curNode->key << " ";
		if (curNode->children)
			show_straight(curNode->children);
		if (curNode->children)
			if (curNode->children->brother)
				show_straight(curNode->children->brother);
	}
}

void Tree::show_reverse(node * curNode)
{
	if (!curNode)
	{
		if (root)
		{
			if (root->children)
				show_reverse(root->children);
			if (root->children)
				if (root->children->brother)
					show_reverse(root->children->brother);
			std::cout << root->key << " ";
		}
	}
	else
	{
		if (curNode->children)
			show_reverse(curNode->children);
		if (curNode->children)
			if (curNode->children->brother)
				show_reverse(curNode->children->brother);
		if (curNode->key)
			std::cout << curNode->key << " ";
	}
}

void Tree::merging(Tree & B, node * curNode)
{
	if (!curNode)
	{
		if (B.getRoot())
		{
			if (B.getRoot()->children)
				merging(B, B.getRoot()->children);
			if (B.getRoot()->children)
				if (B.getRoot()->children->brother)
					merging(B, B.getRoot()->children->brother);
			push(B.getRoot()->key);
		}
	}
	else
	{
		if (curNode->children)
			merging(B, curNode->children);
		if (curNode->children)
			if (curNode->children->brother)
				merging(B, curNode->children->brother);
		push(curNode->key);
	}
}


