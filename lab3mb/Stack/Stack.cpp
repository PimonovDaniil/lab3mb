#define _USE_MATH_DEFINES
#include "Stack.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
	void Stack::Push(int a)
	{
		this->rpush(a);
	}
	int Stack::Pop()
	{
		return this->rpop();
	}
}
