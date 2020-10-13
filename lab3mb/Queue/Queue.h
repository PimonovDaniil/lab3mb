#pragma once
#include "../Stack/Stack.h"
namespace mathTools
{

    class Queue : public Stack {
    public:
        void Push(int a) override; //добавить элемент
    };

}
