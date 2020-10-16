#define _USE_MATH_DEFINES
#include "Deque.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
	void Deque::PushBack(int a)
	{
		this->lpush(a);
	}
	int Deque::PopBack()
	{
		return this->lpop();
	}
	void Deque::PushFront(int a)
	{
		this->rpush(a);
	}
	int Deque::PopFront()
	{
		return this->rpop();
	}
}
