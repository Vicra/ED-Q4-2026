#include "doublelinkedlist.h"

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

// destructor
DoubleLinkedList::~DoubleLinkedList(){
    while(this->head != nullptr){
        cout << "Limpiando..."
             << this->popFront()
             << endl;
    }
}

void DoubleLinkedList::search(int val){
    int index = this->searchMain(val);
    if(index == -1){
        cout << "Element " << val << " not found" << endl;
    } else{
        cout << "Element " << val << " found at index: " << index
             << endl;
    }
}

int DoubleLinkedList::searchMain(int val){
    // busqueda de derecha a izquierda (empiezo
    // en la cola (tail)
    DllNode*it = this->tail;
    int index = this->size - 1;

    while(it != nullptr){
        if(it->value == val){
            return index;
        } else {
            it = it->prev;
            index--;
        }
    }
    return -1;
}

int DoubleLinkedList::popFront(){
    // 1er caso lista vacia
    if(this->head == nullptr) return -1;

    // 2do caso lista contiene solo elemento
    int valueToReturn = this->head->value;
    this->size--;
    if(this->head == this->tail){
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        return valueToReturn;
    }
    // 3er caso lista contiene mas de un elemento
    this->head = this->head->next;
    delete this->head->prev;
    this->head->prev = nullptr;
    return valueToReturn;
}

int DoubleLinkedList::pushFront(int val){
    DllNode* newNode = new DllNode(val);
    // 1er caso: lista vacia
    if(this->head == nullptr){
        this->head = this->tail = newNode;
    }
    // 2do caso: lista no vacia
    else{
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    this->size++;
    return val;
}

void DoubleLinkedList::print(){
    // 1er caso lista vacia
    if(this->head == nullptr){
        cout << "Lista vacia" << endl;
    }
    // 2do caso lista no vacia
    else {
        cout << "null <-";
        DllNode*it = this->head;
        while(it!= nullptr){
            cout << it->value;
            if(it->next != nullptr){
                cout << "<=>";
            }
            it = it->next;
        }
        cout << "-> null" << endl;
        cout << "Head: "<< this->head->value <<endl;
        cout << "Tail: "<< this->tail->value <<endl;
        cout << "Size: " << this->size << endl;
    }
}
