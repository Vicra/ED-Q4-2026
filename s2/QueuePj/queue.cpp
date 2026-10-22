#include <iostream>
using std::cout;
using std::endl;
#include "queue.h"

Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
}

Queue::~Queue() {
    while(this->head!=nullptr){
        this->dequeue();
    }
}

void Queue::print(){
    if(this->head == nullptr) return;
    Node*it = this->head;
    while(it!=nullptr){
        cout << it->value << " -> ";
        it = it->next;
    }
    cout << "null" << endl << endl;
}

void Queue::enqueue(string val){
    Node*newNode = new Node(val);
    if(this->head == nullptr){
        this->head = newNode;
        this->tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
    return;
}

string Queue::dequeueMain(){
    if(this->head == nullptr) return "";
    string valueToReturn = this->head->value;

    // tmp para saber quien sigue
    Node*tmp = this->head->next;
    delete this->head;
    head = tmp;
    if(head == nullptr)
        tail = nullptr;
    return valueToReturn;
}

void Queue::dequeue(){
    string valueToPrint = this->dequeueMain();
    if(valueToPrint == "")
        cout << "Nothing to dequeue" << endl;
    else
        cout << "Dequeued: "<< valueToPrint << endl;
}
