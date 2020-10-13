#define _USE_MATH_DEFINES
#include "Stack.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{
    void Stack::copy(const Stack& other) {
        this->size = other.size;
        int* newStack = new int[this->size];
        for (int i = 0; i < this->size; i++)
            newStack[i] = other.m_data[i];
        if (this->m_data != nullptr) delete[] this->m_data;
        this->m_data = newStack;
    }

    Stack::Stack() { //стандартный конструктор
        this->m_data = nullptr;
        this->size = 0;
    }

    Stack::Stack(const Stack& other) { // конструктор копирования
        copy(other);
    }


    Stack::~Stack() { //деструктор
        if (this->m_data != nullptr) delete[] this->m_data;
    }

    Stack& Stack::operator=(const Stack& other) //подмена понятий
    {
        copy(other);
        return *this;
    }

    void Stack::Print() {
        for (int i = 0; i < this->size; i++)
            printf("%d ", this->m_data[i]);
        printf("\n");
    }

    void Stack::Push(int a) { //добавить элемент
        int* newStack = new int[this->size + 1];
        if (this->m_data != nullptr) {
            for (int i = 0; i < this->size; i++)
                newStack[i] = this->m_data[i];
            delete[] this->m_data;
        }
        this->m_data = newStack;
        this->size++;
        this->m_data[this->size - 1] = a;
    }

    int Stack::Pop() { //убрать элемент
        if (this->size <= 0) throw "выход за границы";
        int a = m_data[this->size - 1];
        if (this->size == 1) {
            delete[] this->m_data;
            this->m_data = nullptr;
        }
        else {
            int* newStack = new int[this->size - 1];
            for (int i = 0; i < this->size - 1; i++)
                newStack[i] = this->m_data[i];
            delete[] this->m_data;
            this->m_data = newStack;
        }
        this->size--;
        return a;
    }

    int Stack::Top() { // проверить верхний элемент
        if (this->size <= 0) throw "выход за границы";
        return m_data[this->size - 1];
    }

    bool Stack::IsEmpty() { // проверка на пустоту
        return (this->m_data != nullptr) ? false : true;
    }
	

}
