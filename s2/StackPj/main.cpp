#include <iostream>
#include "stack.h"
using std::cout;
using std::endl;

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.print();
    cout << "Popped: " << s.pop() << endl;
    s.print();
    cout << "Peek: " << s.peek() << endl;
    s.print();

    s.empty();
    s.print();
    return 0;
}
