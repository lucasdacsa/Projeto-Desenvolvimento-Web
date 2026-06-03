#include <iostream>
using namespace std;

int main () {

int vet [10];


for(int i = 0; i < 10; i++ ) {

// Lê os 10 números do usuário
cout << "digite os numeros: " << i << endl;
cin >> vet[i];



}
    // Exibe os números digitados
cout << "\nVoce digitou:\n" << endl;
for(int i = 0; i < 10; i++ ) {
    
cout << " " << vet[i] ;



}

cout << endl;

    return 0;
}