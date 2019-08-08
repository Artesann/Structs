#include "Stack.h"


Stack::Stack()
{
	this->count = 0;

}


Stack::~Stack()
{
}


void Stack::print_st()
{
	for(int i = MAX - count+1; i < MAX; i++)
	{
		std::cout << i << " : " << data[i] << std::endl;
	}
}

void Stack::push(int e)
{
	if (MAX > count) {
		count++;
		data[MAX - count] = e;
	}
	else
	{
		std::cout << "stack overflow" << std::endl;
	}
}

int Stack::pop()
{
	if (count > 0) {
		int e = data[MAX - count];
		count--;
		return e;
	}
	else 
	{	
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}
	
}
