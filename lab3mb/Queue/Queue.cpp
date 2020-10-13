#define _USE_MATH_DEFINES
#include "Queue.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
    void Queue::Push(int a) { //добавить элемент
        int* newStack = new int[this->size + 1];
        if (this->m_data != nullptr) {
            for (int i = 1; i < this->size + 1; i++)
                newStack[i] = this->m_data[i - 1];
            delete[] this->m_data;
        }
        this->m_data = newStack;
        this->size++;
        this->m_data[0] = a;
    }

}
