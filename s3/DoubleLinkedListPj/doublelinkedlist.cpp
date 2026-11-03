#include "doublelinkedlist.h"

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

int DoubleLinkedList::removeBeforeRef(DllNode*ref){
    if(ref == nullptr || head == ref){
        return -1;
    }
    this->size--;
    // es el segundo, osea borrar la cabeza
    if(head->next == ref){
        int valueToReturn = head->value;
        head = ref;
        delete ref->prev;
        ref->prev = nullptr;
        return valueToReturn;
    }else {
        // Nodo previo
        DllNode* prev = ref->prev;
        int valueToReturn = prev->value;
        ref->prev = prev->prev;
        prev->prev->next = ref;
        delete prev;
        return valueToReturn;
    }
}

int DoubleLinkedList::popBack(){
    if(this->tail == nullptr) return -1;
    int valueToReturn = this->tail->value;
    this->size--;
    if(this->tail == this->head){
        delete this->head;
        head = nullptr;
        tail = nullptr;
    } else {
        // lista contiene mas de un elemento
        DllNode* ref = this->tail;
        tail = tail->prev;
        delete ref;
        tail->next = nullptr;
    }
    return valueToReturn;
}

int DoubleLinkedList::remove(int val){
    DllNode* it = this->head;
    while(it != nullptr){
        if(it->value == val){
            DllNode* prev = it->prev;
            // 1er puntero
            prev->next = it->next;
            if(prev->next != nullptr){
                // 2do puntero
                prev->next->prev = prev;
            } else {
                // 3er puntero
                tail = tail->prev;
                // misma instruccion
                // tail = prev;
            }
            delete it;
            return val;
        } else {
            it = it->next;
        }
    }
    return -1;
}

int DoubleLinkedList::insertAfterRef(DllNode*ref, int val){
    if (ref == nullptr) return -1;
    // llegue aca, ref no es nullptr
    // 1er puntero
    DllNode* newNode = new DllNode(val);
    newNode->prev = ref;

    // 2do puntero
    newNode->next = ref->next;

    // 3er puntero
    ref->next = newNode;

    if(newNode->next != nullptr){
        // 4to puntero
        newNode->next->prev = newNode;
    } else {
        // quiero insertar despues de la cola
        tail = newNode;
    }
    this->size++;
    return val;
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
