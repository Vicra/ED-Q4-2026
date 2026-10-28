#include "dllnode.h"

DllNode::DllNode(int val) {
    this->next = nullptr;
    this->prev = nullptr;
    this->value = val;
}
