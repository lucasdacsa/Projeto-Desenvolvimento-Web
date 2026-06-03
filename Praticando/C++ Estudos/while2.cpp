#include <iostream>
using namespace std;

int main () {

int n;                   // Número digitado pelo usuário
int i = 1;               // Contador que começa em 1
int soma = 0;            // Acumulador da soma


 cout << "Digite um numero inteiro: ";
 cin >> n;


// Enquanto i for menor ou igual a n, soma e incrementa
while(i <= n) {

soma = soma + i;  // soma atual + valor de i
i++;    // incrementa i (i++)


    
}

cout << "A soma e: " << soma << endl;



    return 0;
}
