#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
using std::cout;
using std::endl;
#include "dllnode.h"

class DoubleLinkedList
{
public:
    // properties
    DllNode*head;
    DllNode*tail;
    unsigned int size;

    DoubleLinkedList();
    ~DoubleLinkedList();

    // functions
    int pushFront(int val);
    void print();
    int popFront(); // borrar el primer elemento

    // retorna el indice donde lo encontro
    void search(int val);

    int insertAfterRef(DllNode*ref, int val);
    // retorna -1 si no lo encuentra
    // retorn el valor si lo borro
    int remove(int val);

    int popBack();

private:
    int searchMain(int val);
};

#endif // DOUBLELINKEDLIST_H
