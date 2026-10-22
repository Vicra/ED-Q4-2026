#include "queue.h"

int main(){
    Queue q;
    q.enqueue("A");
    q.enqueue("B");
    q.enqueue("C");
    q.print();
    // esto se hace ahora en el destructor
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // q.print();
    return 0;
}
