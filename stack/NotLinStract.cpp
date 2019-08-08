#include <iostream>
#include "CustomStack.h"

using namespace std;

// #define MAX 1000
// class Stack
// {
// private:

	// int data[MAX];
	// int count;

// public:
	// Stack();

	// void print_st();

	// void push(int e);

	// int get_top() { return data[MAX - count];}

	// int pop();

	// int len() { return count; }
// };

// Stack::Stack()
// {
	// this->count = 0;

// }

// void Stack::print_st()
// {
	// for(int i = MAX - count+1; i < MAX; i++)
	// {
		// std::cout << i << " : " << data[i] << std::endl;
	// }
// }

// void Stack::push(int e)
// {
	// if (MAX > count) {
		// count++;
		// data[MAX - count] = e;
	// }
	// else
	// {
		// std::cout << "stack overflow" << std::endl;
	// }
// }

// int Stack::pop()
// {
	// if (count > 0) {
		// int e = data[MAX - count];
		// count--;
		// return e;
	// }
	// else 
	// {	
		// std::cout << "Stack is empty" << std::endl;
		// return 0;
	// }
// }


// class CustomStack
// {
// private:

	// Stack stack;

// public:
	// CustomStack();
	// ~CustomStack();

	// int get_item (int i);
	
	// void set_item (int ind, int value);

	// void push(int e) { stack.push(e); }

	// int pop() { return stack.pop(); }

	// void pr() { stack.print_st(); }//для отладки
	
	// int length() {	stack.len(); }
	
// };

// void CustomStack::set_item(int ind, int value)
// {
	// Stack boof;
	// for (int i = 0; i < ind; i++)
	// {
		// boof.push(stack.pop());
	// }
	// stack.pop();
	// stack.push(value);
	// for (int i = 0; i < ind; i++)
	// {
		// stack.push(boof.pop());
	// }
// }

// int CustomStack::get_item(int ind)
// {
	// if (ind >= 0 && ind < stack.len()) {
		// Stack boof;
		// for (int i = 0; i < ind; i++)
		// {
			// boof.push(stack.pop());
		// }
		// int e = stack.get_top();
		// for (int i = 0; i < ind; i++)
		// {
			// stack.push(boof.pop());
		// }
		// return e;
	// }
	// else
	// {
		// std::cout << "out of range "<< std::endl;
		// return 0;
	// }
// }



void sorts(int *in, int*out, int u, int v, int n)
{
	int *count = new int [v+1];
	for(int i = 0; i < n; i++)
		count[i] = 0;
	
	for(int i = 0; i < n; i++)
		count[in[i]]++;
	
	for(int i = u+1; i <= v; i++)
		count[i] += count[i-1];
	
	int i = 0;
	for(int j = n-1; j >= 0; j--)
	{
		i = count[in[j]];
		out[i-1] = in[j];
		count[in[j]] = --i;
	}
}

void sort(CustomStack &in, CustomStack &out, int u, int v, int n)
{
	CustomStack count;
	for(int i = 0; i < n; i++)
		count.push(0);
	
	for(int i = 0; i < n; i++)
		count.set_item(in.get_item(i), count.get_item(in.get_item(i)) + 1);
	
	for(int i = u+1; i <= v; i++)
		count.set_item(i, count.get_item(i) + count.get_item(i-1));
	
	int i = 0;
	for(int j = n-1; j >= 0; j--)
	{
		i = count.get_item(in.get_item(j));
		out.set_item(i-1, in.get_item(j));
		count.set_item(in.get_item(j), i-1);
	}	
}


int main()
{
	/////////////
 	CustomStack toSort;
	CustomStack out;
	
	int n = 10;
	int u = 1;
	int v = 5;
	int data[] = {2,5,1,2,2,4,1,1,1,3};
	for(int i = 0; i < n; i++)
	{
		toSort.push(data[i]);
		out.push(0);
	}
	
	cout << "in:  ";
	for (int i = 0; i< n; i++)
		cout << toSort.get_item(i) << ' ';
	cout << endl;

	sort(toSort, out, u, v, n);
	
	cout << "out: ";
	for (int i = 0; i< n; i++)
		cout << out.get_item(i) << ' ';
	cout << endl;

	return 0;
}
