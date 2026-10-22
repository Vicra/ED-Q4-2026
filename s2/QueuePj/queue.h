#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue
{
public:
    Node* head;
    Node* tail;
    Queue();
    ~Queue();

    // functions
    void print();
    void enqueue(string val);
    void dequeue();
private:
    string dequeueMain();
};

#endif // QUEUE_H
