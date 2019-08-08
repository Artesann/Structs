#include "CustomStack.h"


CustomStack::CustomStack()
{
}


CustomStack::~CustomStack()
{
}

void CustomStack::set_item(int ind, int value)
{
	

		Stack boof;
		for (int i = 0; i < ind; i++)
		{
			boof.push(stack.pop());
		}
		stack.pop();
		stack.push(value);
		for (int i = 0; i < ind; i++)
		{
			stack.push(boof.pop());
		}

	//	std::cout << "out of range"<<ind<<" - "<<stack.len() << std::endl;
	
}

int CustomStack::get_item(int ind)
{
	if (ind >= 0 && ind < stack.len()) {
		Stack boof;
		for (int i = 0; i < ind; i++)
		{
			boof.push(stack.pop());
		}
		int e = stack.get_top();
		for (int i = 0; i < ind; i++)
		{
			stack.push(boof.pop());
		}
		return e;
	}
	else
	{
		std::cout << "out of range "<< std::endl;
		return 0;
	}
}
