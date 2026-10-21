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
    l.insert(40);
    l.insert(50);
    l.insert(60);
    l.insert(60);
    l.insert(70);
    l.printList();
    int index1 = l.search(60);
    if(index1 >= 0)
        cout << "Element found in index: " << index1 << endl;
    else
        cout << "Element not found" << endl;
    return 0;

    // l.insertAt(pos, value)
    // l.deleteAt(pos)
    // l.deleteFront()
    // l.deleteTail()
    // l.size()
    // l.empty()
}
