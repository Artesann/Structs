#pragma once
#include "Stack.h"


class CustomStack
{
private:

	Stack stack;

public:
	CustomStack();
	~CustomStack();

	int get_item (int i);
	
	void set_item (int ind, int value);

	void push(int e) { stack.push(e); }

	int pop() { return stack.pop(); }

	void pr() { stack.print_st(); }//для отладки
	
	int length() {	stack.len(); }
	
};

