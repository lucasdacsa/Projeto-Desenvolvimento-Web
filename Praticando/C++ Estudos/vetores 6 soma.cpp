#include <iostream>
using namespace std;

int main () {

int numero [5];
int soma = 0 ;

for (int i = 0; i < 5; i++) {

cout << "digite o numero: " << i+1 << ": ";
cin >> numero[i];

}

for (int i = 0; i < 5; i++) {

soma += numero[i];   // mesmo que soma = soma + numeros[i]

}

cout << "A soma de todos o numeros e: " << soma << endl;


    return 0;
}