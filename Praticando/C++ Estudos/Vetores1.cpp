#include <iostream>
#include <string>

using namespace std;

int main() {

int numeros [5] = {10,20,30,40,50}; //vetor sempre começa do zero , e tambem sempre são colocados em colchetes
int soma = 0;

//entrada
for (int i = 0; i < 5; i++) {

cout << "Digite o numero " << i+1 << ": ";
cin >> numeros[i];

}

for (int i = 0; i <5; i++) {
soma += numeros [i];


}

cout << "a soma dos numeros inteiros e: " << soma << endl;

    return 0;
}
