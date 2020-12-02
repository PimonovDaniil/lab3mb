#pragma once

namespace mathTools
{

    class Vector {
    private:
        int* m_data;
        int size; //размер заполненой части векора
        int csize; //весь размер выделенной памяти
        int reserve; //сколько зарезервировать
        int begin; //начало заполненной части вектора
        int end; //конец заполненной части вектора
        int cbegin;//начало выделенной памяти
        int cend;//конец выделенной памяти
        int numObj;
        static int num;

        void memoryAdd(); //добавляет память если надо
    protected:
        Vector();

        /*конструктор копирования*/
        Vector(Vector& other);

        Vector(Vector&& m) noexcept; //move конструктор

        ~Vector();

        /*подмена понятий (перегрузка)*/
        Vector& operator=(const Vector& other);

        Vector& operator=(Vector&& m) noexcept; //move

        void lpush(int a);

        int lpop();

        void rpush(int a);

        int rpop();

    public:
        static bool debug;

        void Reserve(int a);

        void print();

        bool isEmpty();

        int Top();
    };

}
