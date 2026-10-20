#include "linkedlist.h"

int main(){
    LinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.printList();
    l.pushFront(5);
    l.printList();
    l.remove(20);
    l.printList();
    l.remove(5);
    l.printList();
    l.remove(30);
    l.printList();
    return 0;
}
