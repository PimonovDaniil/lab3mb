#define _USE_MATH_DEFINES
#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>
using namespace std;

namespace mathTools
{
    bool Vector::debug = false;
    int Vector::num = 0; //начальное кол-во объектов класса

    Vector::Vector() {
        this->numObj = ++this->num;
        this->reserve = 10;
        this->m_data = new int[this->reserve * 2];
        this->size = 0;
        this->csize = this->reserve * 2;
        this->begin = this->reserve;
        this->end = this->reserve + 1;
        this->cbegin = 0;
        this->cend = this->reserve * 2 - 1;
        if (debug) std::cout << "(вектор " << this->numObj << ", " << "конструктор)" << std::endl;
    }

    /*конструктор копирования*/
    Vector::Vector(Vector& other) {
        this->m_data = nullptr;
        this->numObj = ++this->num;
        //copy(other);
        *this = other;
        if (debug) std::cout << "(вектор " << this->numObj << ", " << "конструктор копирования)" << std::endl;
    }

    Vector::Vector(Vector&& m) noexcept //move конструктор
    {
        this->m_data = nullptr;
        *this = std::move(m);
        this->numObj = ++this->num;
        if (debug) std::cout << "(вектор " << this->numObj << ", " << "move конструктор)" << std::endl;
    }

    Vector::~Vector() {
        if (this->m_data != nullptr) delete[] this->m_data;
        if (debug) std::cout << "(вектор " << this->numObj << ", " << "деструктор)" << std::endl;
    }

    void Vector::Reserve(int a) {
        this->reserve = a;
    }

    /*подмена понятий (перегрузка)*/
    Vector& Vector::operator=(const Vector& other)
    {
        this->numObj = ++this->num;
        // Проверка на самоприсваивание
        if (this != &other) {
            //copy(other);
            if (this->m_data != nullptr) {
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
        return *this;
    }

    Vector& Vector::operator=(Vector&& m) noexcept //move
    {
        this->numObj = ++this->num;
        //swap(m);
        std::swap(this->size, m.size);
        std::swap(this->csize, m.csize);
        std::swap(this->reserve, m.reserve);
        std::swap(this->begin, m.begin);
        std::swap(this->end, m.end);
        std::swap(this->cbegin, m.cbegin);
        std::swap(this->cend, m.cend);
        std::swap(this->m_data, m.m_data);
        return *this;
    }

    void Vector::memoryAdd() {
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

    void Vector::lpush(int a) {
        this->m_data[this->begin] = a;
        this->begin--;
        this->size++;
        this->memoryAdd();
    }

    int Vector::lpop() {
        if (this->size <= 0) throw "выход за пределы";
        this->size--;
        this->begin++;
        return this->m_data[this->begin - 1];
    }

    void Vector::rpush(int a) {
        this->m_data[this->end] = a;
        this->end++;
        this->size++;
        this->memoryAdd();
    }

    int Vector::rpop() {
        if (this->size <= 0) throw "выход за пределы";
        this->size--;
        this->end--;
        return this->m_data[this->end - 1];
    }

    void Vector::print() {
        for (int i = this->begin + 1; i <= this->end -1; i++)
            cout << this->m_data[i] << " ";
    }

    bool Vector::isEmpty()
    {
        return (this->size <= 0) ? true : false;
    }

    int Vector::Top()
    {
        if (this->size <= 0) throw "выход за пределы";
        return this->m_data[this->end+1];
    }

}
