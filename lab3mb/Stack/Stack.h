#pragma once
#include "../Vector/Vector.h"

namespace mathTools
{

    class Stack : public Vector{

    private:
        using Vector::lpush;
        using Vector::rpush;
        using Vector::lpop;
        using Vector::rpop;

    public:
        void Push(int a);
        int Pop();
    };

}
