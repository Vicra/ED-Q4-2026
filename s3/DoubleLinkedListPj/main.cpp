#include "doublelinkedlist.h"

int main(){
    DoubleLinkedList dll;
    dll.print();
    dll.pushFront(10);
    dll.pushFront(20);
    dll.pushFront(30);
    dll.print();
    dll.search(30);
    dll.search(100);
    dll.search(10);

    dll.insertAfterRef(dll.tail, 25);
    // genera memory leak
    // dll.insertarDespuesDe(new DllNode(45), 25);
    // no inserta
    // dll.insertarDespuesDe(nullptr, 25);
    dll.print();

    dll.popBack();
    dll.print();


    return 0;
}
