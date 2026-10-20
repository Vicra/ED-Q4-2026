#include "linkedlist.h"
#include <limits>

int main(){
    int min_val = std::numeric_limits<int>::min();

    LinkedList l;
    l.insert(10);
    l.insert(20);
    l.insert(30);

    if(l.remove(100) == min_val)
        cout << "Valor 100 no existe en la lista" << endl;

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
