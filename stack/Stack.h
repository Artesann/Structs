#pragma once
#include <iostream>
#define MAX 1000
class Stack
{
private:

	int data[MAX];
	int count;

public:
	Stack();
	~Stack();

	void print_st();

	void push(int e);

	int get_top() { return data[MAX - count];}

	int pop();

	int len() { return count; }
	
};

