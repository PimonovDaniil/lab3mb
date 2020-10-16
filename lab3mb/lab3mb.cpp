﻿/*Наглый программист в больнице превращает очередь в стек*/
#include "Stack/Stack.h"
#include "Queue/Queue.h"
#include "Vector/Vector.h"
#include <iostream>
using namespace mathTools;
using namespace std;

int main()/*тесты*/
{
    Stack a;
    a.Push(1);
    cout << "Stack a: ";  a.print(); cout << endl;
    a.Push(2);
    cout << "Stack a: ";  a.print(); cout << endl;
    a.Pop();
    cout << "Stack a: ";  a.print(); cout << endl;
    a.Push(3);
    cout << "Stack a: ";  a.print(); cout << endl;
    Stack b;
    b = a;
    a.Push(4);
    b.Push(5);
    printf("Stack a: "); a.print();
    printf("Stack b: "); b.print(); cout << endl << endl;

    Queue c;
    c.Enqueue(1);
    printf("Queue c: "); c.print(); printf("\n");
    c.Enqueue(2);
    printf("Queue c: "); c.print(); printf("\n");
    c.Dequeue();
    printf("Queue c: "); c.print(); printf("\n");
    c.Enqueue(3);
    printf("Queue c: "); c.print(); printf("\n");
    Queue d;
    d = c;
    printf("Queue c: "); c.print(); printf("Queue d: "); d.print(); printf("\n");
    c.Enqueue(4);
    printf("Queue c: "); c.print(); printf("Queue d: "); d.print(); printf("\n");
    d.Enqueue(5);
    printf("Queue c: "); c.print(); printf("Queue d: "); d.print(); printf("\n");
    
}
