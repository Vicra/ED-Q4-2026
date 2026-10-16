#ifndef NODE_H
#define NODE_H

class Node
{
public:
    // constructor
    Node(int val);

    // properties
    int value;
    Node* next;

    // destructor
    ~Node();
};

#endif // NODE_H
