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
    return 0;
}
