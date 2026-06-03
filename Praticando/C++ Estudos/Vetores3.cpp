#include <iostream>
#include <string>

using namespace std;

int main () {

int numeros[6];

for (int i = 0; i < 6; i++ ) {

    cout << "Digite os numeros: "<< i << endl; 
    cin >> numeros[i];
}

cout << "os numeros digitados foram: " << endl;

for (int i = 0; i < 6; i++  ) {

cout << numeros[i] << " ";
}

cout << endl;

    return 0;
}