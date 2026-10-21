#include "linkedlist.h"
#include <limits>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

int LinkedList::search(int value){
    int index = 0;
    Node* it = this->head;
    while(it != nullptr){
        if(it->value == value)
            return index;
        else {
            it = it->next;
            index++; // index = index + 1
        }
    }
    return -1;
}

int LinkedList::remove(int value){
    int min_val = std::numeric_limits<int>::min();

    // 1er caso: no hay nada que borrar
    if(this->head == nullptr) return min_val;

    // 2do caso: se requiere borrar el unico elemento de la lista
    // if (this.head.next == nullptr)
    if(this->head == this->tail){
        if(value == this->head->value){
            delete this->head;
            this->head = nullptr;
            this->tail = nullptr;
        } else {
            return min_val;
        }
    }

    // 3er caso hay mas de un elemento , borrar la cabeza
    if(this->head->value == value){
        Node* newHead = this->head->next;
        delete this->head;
        this->head = newHead;
        return value;
    }

    // 4to caso, buscar en toda la lista
    Node* it = this->head;
    // comenzar en el segundo
    while(it != nullptr){
        if(it->next!=nullptr && it->next->value == value){
            Node* tmp = it->next;

            // alternativa 1
            it->next = tmp->next;


            // alternativa 2
            // it->next = it->next->next;

            // verificar si el nodo a borrar es la cola
            if(tmp == this->tail){
                this->tail = it;
            }

            delete tmp;
            return value;
        } else {
            it = it->next;
        }
    }
    return min_val;
}

int LinkedList::pushFront(int value){
    Node* newNode = new Node(value);
    if(this->head == nullptr){
        this->head = newNode;
        this->tail = newNode;
    } else {
        newNode->next = this->head;
        this->head = newNode;
    }
    return value;
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
    cout << "null" << endl;
    if(head!=nullptr)
        cout << "Head: " << this->head->value << endl;
    if(tail!=nullptr)
        cout << "Tail: " << this->tail->value << endl << endl;
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
