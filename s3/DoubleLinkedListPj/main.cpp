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
    cout << "Remove before ref: head" << endl;
    dll.removeBeforeRef(dll.head);
    dll.print();
    dll.removeBeforeRef(dll.head->next);
    dll.print();
    dll.pushFront(30);
    dll.pushFront(40);
    dll.print();
    cout << "remove before ref tail" << endl;
    dll.removeBeforeRef(dll.tail);
    dll.print();
    return 0;
}
