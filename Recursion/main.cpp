#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int countDigits(int n){
    // caso base
    if(n >=0 && n <=9) return 1;

    // caso recursivo
    return 1 + countDigits(n/10);
}

int binarySearch(vector<int> data, int lo, int high, int x){
    if(lo > high) return -1;
    int mid = lo + (high - lo) / 2;
    // esta el elemento que busco en mid?
    if(data[mid] == x){
        return mid;
    }

    else if(x > data[mid]){
        return binarySearch(data, lo, high, x);
    }
    else {
        return binarySearch(data, lo, high, x);
    }
}

int main(){
    int digits = countDigits(11049);
    cout << digits << endl;

    vector<int> numbers = {10, 15, 25, 32, 46, 57, 89, 100};
    int x = 33;
    int indice = binarySearch(numbers, 0, numbers.size()-1, x);
    if(indice < 0 || indice == -1){
        cout << "No existe el elemento: "<< x << " en la lista" << endl;
    } else{
        cout << "Elemento encontrado en: " << indice << endl;
    }
    return 0;


}
