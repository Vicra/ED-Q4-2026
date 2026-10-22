#ifndef STACK_H
#define STACK_H
#include "node.h"
class Stack
{
public:
    // properties
    Node* top;
    Stack();

    // functions
    void push(int val);
    int pop();
    int peek();
    void print();
    void empty();
};

#endif // STACK_H
