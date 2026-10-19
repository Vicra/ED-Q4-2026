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
};

#endif // LINKEDLIST_H
