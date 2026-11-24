#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
        return binarySearch(data, mid+1, high, x);
    }
    else {
        return binarySearch(data, lo, mid-1, x);
    }
}

int productDigits(int num){
    if(num < 0){
        num = num * -1;
    }
    if(num <= 9 && num>0) return num;
    int res = num % 10;
    return res * productDigits(num/10);
}

int sumArray(vector<int> array, int n){
    if(n==0) return 0;
    return array[n-1] + sumArray(array, n-1);
}

int countVowels(string s, int n){
    if(n == 0) return 0;
    char c = tolower(s[n-1]);
    cout << "Processing.... [" << n << "] " << c << endl;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o'|| c == 'u'){
        return 1 + countVowels(s, n-1);
    }
    return countVowels(s, n-1);
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

    vector <int> arr = {1, 2, 3, 4, 5};
    int suma = sumArray(arr, arr.size());
    cout << "Summa del array es: " << suma << endl;

    int cantidadVocales = countVowels("hola mundo", 10);
    cout << "Cantidad de vocales: " << cantidadVocales << endl;

    int product = productDigits(-567);
    cout << "Product: " << product << endl;
    return 0;

}
