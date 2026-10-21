#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using std::cout;
using std::endl;

#include "node.h"

class LinkedList
{
public:
    // properties
    Node* head;
    Node* tail;

    // functions
    LinkedList();

    int insert(int newValue); // pushBack
    void printList();
    int pushFront(int value);

    // borrar el primer elemento que encuentra con ese valor, no borra duplicados
    int remove(int value);

    // returns index of first element found, -1 when not found
    int search(int value);
};

#endif // LINKEDLIST_H
