
#include <iostream>
using std::cout;
using std::endl;

#include "stack.h"

Stack::Stack() {
    this->top=nullptr;
}

void Stack::empty(){
    while(this->top != nullptr){
        this->pop();
    }
}

void Stack::print(){
    if(this->top == nullptr){
        cout<< "Lista vacia"<< endl;
        return;
    }
    Node*it = this->top;
    cout << "TOP" <<endl;
    while(it!= nullptr){
        cout << it->value << endl << "|" << endl;
        it = it->next;
    }
    cout << "null" << endl << endl;
}

int Stack::peek(){
    if(this->top != nullptr)
        return this->top->value;
    else
        return -1;
}

void Stack::push(int val){
    Node*newNode = new Node(val);
    if(this->top == nullptr) {
        this->top = newNode;
        return;
    }
    else {
        newNode->next = this->top;
        this->top = newNode;
    }
}

int Stack::pop(){
    if(this->top == nullptr) return -1;
    int valueToReturn = this->top->value;
    Node* tmp = this->top->next;
    delete this->top;
    this->top = tmp;
    return valueToReturn;
}
