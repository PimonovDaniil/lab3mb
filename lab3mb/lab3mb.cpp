/*Наглый программист в больнице превращает очередь в стек*/
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include <iostream>
using namespace mathTools;
using namespace std;

class Vector {
private:
    int* m_data;
    int size;
    int csize;
    int reserve;
    int begin;
    int end;
    int cbegin;
    int cend;
    void copy(const Vector& other) {
        if(this->m_data != nullptr) {
            delete[] this->m_data;
        }

        this->size = other.size;
        this->csize = other.csize;
        this->reserve = other.reserve;
        this->begin = other.begin;
        this->end = other.end;
        this->cbegin = other.cbegin;
        this->cend = other.cend;
        this->m_data = new int[this->csize];

        for (int i = 0; i < this->csize; i++)
            this->m_data[i] = other.m_data[i];
    }

protected:
    Vector() {
        this->reserve = 10;
        this->m_data = new int[this->reserve * 2];
        this->size = 0;
        this->csize = this->reserve * 2;
        this->begin = this->reserve;
        this->end = this->reserve - 1;
        this->cbegin = 0;
        this->cend = this->reserve * 2 - 1;
    }

    /*конструктор копирования*/
    Vector(Vector& other) {
        this->m_data = nullptr;
        //this->numObj = ++this->num;
        copy(other);
        //if (debug) std::cout << "(матрица " << this->numObj << ", " << "конструктор копирования)" << std::endl;
    }



    ~Vector() {
        if (this->m_data != nullptr) delete[] this->m_data;
    }

    void Reserve(int a) {
        this->reserve = a;
    }

    /*подмена понятий (перегрузка)*/
    Vector& operator=(const Vector& other)
    {
        // Проверка на самоприсваивание
        if (this != &other) copy(other);
        return *this;
    }

    void memoryAdd() {
        if (this->end > this->cend) {
            int* new_m_data = new int[this->size + this->reserve]();
            for (int i = 0; i < this->csize; i -= -1) 
                new_m_data[i] = this->m_data[i];
            this->cend += this->reserve;
            this->csize += this->reserve;
            delete[] this->m_data;
            this->m_data = new_m_data;
        }
        else if (this->begin < this->cbegin) {
            int* new_m_data = new int[this->size + this->reserve]();
            for (int i = 0; i < this->csize; i -= -1) 
                new_m_data[this->reserve + i] = this->m_data[i];
            delete[] this->m_data;

            
            this->csize += this->reserve;
            this->cbegin = 0;
            this->cend = this->csize - 1;
            this->m_data = new_m_data;
        }
    }

    void lpush(int a) {
        this->m_data[this->begin] = a;
        this->begin--;
        this->size++;
        this->memoryAdd();
    }

    int lpop() {
        if (this->size <= 0) throw "выход за пределы";
        this->size--;
        this->begin++;
        return this->m_data[this->begin - 1];
    }

    void rpush(int a) {
        this->m_data[this->end] = a;
        this->end++;
        this->size++;
        this->memoryAdd();
    }

    int rpop() {
        if (this->size <= 0) throw "выход за пределы";
        this->size--;
        this->begin++;
        return this->m_data[this->begin - 1];
    }

    void print() {
        for (int i = 0; i <= this->cend; i++)
            cout << this->m_data[i] << " ";
    }


};

int main()/*тесты*/
{
    /*Stack a;
    a.Push(1);
    a.Push(2);
    a.Pop();
    a.Push(3);
    Stack b;
    b = a;
    a.Push(4);
    b.Push(5);
    printf("Stack a: "); a.Print();
    printf("Stack b: "); b.Print();

    Queue c;
    c.Push(1);
    c.Push(2);
    c.Pop();
    c.Push(3);
    Queue d;
    d = c;
    c.Push(4);
    d.Push(5);
    printf("Queue c: "); c.Print();
    printf("Queue d: "); d.Print();*/
}
