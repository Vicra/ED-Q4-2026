#include <QCoreApplication>
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int a = 10;
    cout << "Direccion de a: " << &a << endl;

    int b = 20;
    cout << "Direccion de b: " << &b<< endl;

    int * p = &a;
    int * q = p;

    cout << "Valor de a atraves de desreferencia: " << *q << endl;

    // desreferencia para acceder al valor que apunto
    *q = 30;

    cout << "a: " << a << " b: " << b<< endl;
    cout << "Address of p " << &p << endl;
    cout << "Address of q " << &q << endl;

}
