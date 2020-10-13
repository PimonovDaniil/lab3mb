#pragma once

namespace mathTools
{

    class Stack {
    protected:
        int* m_data;
        int size;

    private:
        void copy(const Stack& other);

    public:
        Stack(); //стандартный конструктор

        Stack(const Stack& other); // конструктор копирования

        ~Stack(); //деструктор

        Stack& operator=(const Stack& other); //подмена понятий

        void Print(); //вывод на экран(для отладки)

        virtual void Push(int a); //добавить элемент

        int Pop(); //убрать элемент

        int Top(); // проверить верхний элемент

        bool IsEmpty(); // проверка на пустоту
    };

}
