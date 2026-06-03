#include <iostream>
#include <string>

using namespace std;

int main () {


int numero [5];  // cria um vetor com 5 posições (0 a 4)
int soma = 0; 

// entrada de dados
/*Declarei uma variavel =0 dentro do for e uma condição <5; e um indice de incrementação*/
for (int i = 0; i < 5; i++) {

cout << "Digite o numero " << i+1 << ": "; // i+1 é só pra exibir o número humano (1, 2, 3, …).
cin >> numero[i];  // guarda o valor digitado

}

 // soma dos valores
for (int i = 0; i < 5; i++) {

soma += numero [i]; // soma = soma + numero[i]

}

// exibindo resultados
cout << "\n A soma dos numeros digitados foram: " << soma << endl;
for (int i = 0; i < 5; i++) {

    cout << numero[i] << " ";

}

cout << "A soma de todos e: " << soma << endl;

return 0;

}
