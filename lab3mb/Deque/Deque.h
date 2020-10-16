#pragma once
#include "../Vector/Vector.h"
namespace mathTools
{

    class Deque : public Vector {
    private:
        using Vector::lpush;
        using Vector::rpush;
        using Vector::lpop;
        using Vector::rpop;

    public:
        void PushBack(int a); //добавить элемент
        int PopBack(); //убрать элемент
        void PushFront(int a); //добавить элемент
        int PopFront(); //убрать элемент
    };

}
