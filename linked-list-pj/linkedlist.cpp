#include "linkedlist.h"

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::printList(){
    if(this->head == nullptr){
        cout << "Lista vacia" << endl;
        return;
    }
    Node* it = this->head;
    while(it != nullptr){
        cout << it->value << ",";
        it = it->next;
    }
    cout << "null";
}


int LinkedList::insert(int newValue){
    // crear instancia
    Node* newNode = new Node(newValue);

    // 1er caso: lista vacia
    if(this->head == nullptr && this->tail == nullptr){
        this->head = newNode;
        this->tail = newNode;
        return newValue;
    }

    // 2do caso: no esta vacia
    else {
        // asignar el nuevo ultimo(insertar)
        tail->next = newNode;

        // reasignar la cola
        tail = tail->next;
        // tail = newNode;
    }
}
