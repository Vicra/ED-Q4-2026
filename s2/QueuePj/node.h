#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;
class Node
{
public:
    string value;
    Node* next;
    Node(string val);
};

#endif // NODE_H
