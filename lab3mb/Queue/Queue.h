#pragma once
#include "../Vector/Vector.h"
namespace mathTools
{

    class Queue : public Vector {
    private:
        using Vector::lpush;
        using Vector::rpush;
        using Vector::lpop;
        using Vector::rpop;

    public:
        void Enqueue(int a); //добавить элемент
        int Dequeue(); //добавить элемент
    };

}
