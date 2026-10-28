#ifndef DLLNODE_H
#define DLLNODE_H

class DllNode
{
public:
    //properties
    DllNode*prev;
    DllNode*next;
    int value;

    // constructor
    DllNode(int val);
};

#endif // DLLNODE_H
