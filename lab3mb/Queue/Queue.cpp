#define _USE_MATH_DEFINES
#include "Queue.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
	void Queue::Enqueue(int a)
	{
		this->lpush(a);
	}

	int Queue::Dequeue()
	{
		return this->rpop();
	}
}
