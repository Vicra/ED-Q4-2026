#include "node.h"

#include <iostream>
using std::cout;
using std::endl;

int test(){
    int n3 = 10;
}

void printList(Node* first){
    // 1er caso lista vacia
    if(first == nullptr){
        cout << "Lista vacia";
    }

    //2do caso: contiene un elemento
    Node *it = first;
    while(it != nullptr){
        cout << it->value << ", ";
        it = it->next;
    }

}

int main() {
    // nodo en stack mem
    //Node n3(3);

    test();

    // nodos en heap
    Node*n1 = new Node(1);
    Node*n2 = new Node(2);
    Node*n3 = new Node(3);
    Node*n4 = new Node(4);

    // impimir nullptr
    // cout << n1->next << endl;

    // imprimir datos
    // cout << n1->value << endl;
    // cout << n2->value << endl;

    // enlace
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;


    // imprimir
    printList(n1);

    delete n1;
    delete n2;
    return 0;
}


