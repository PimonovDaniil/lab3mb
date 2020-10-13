/*Наглый программист в больнице превращает очередь в стек*/
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include <iostream>
using namespace mathTools;



int main()/*тесты*/
{
    Stack a;
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
    printf("Queue d: "); d.Print();
}
