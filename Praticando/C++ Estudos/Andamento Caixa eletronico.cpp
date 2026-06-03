#include <iostream>
#include <string>

using namespace std;

int main () {

float saldo = 0.0, valor = 0.0 ;
int opcao;

cout << "------CAIXA ELETRONICO!------" << endl;

cout << "Oque voce deseja fazer?\n Selecione uma das opcoes:\n 1- Ver Saldo. , 2-Deposito. , 3-Saque. " << endl;
cin >> opcao;

// switch não funciona com float
switch (opcao) {

case 1: cout << " Saldo Atual da conta: " << saldo << endl;

break;

case 2: cout << "Digite o valor do deposito: " << opcao << endl;
cin >> valor ;
//incremento
saldo += valor;

cout << "Deposito realizado com sucesso! " << valor << endl;

break;

case 3: cout << "digite o valor do saque: " << opcao << endl;
cin >> valor;
//decremento
valor -= saldo;

cout << "Valor sacado com Sucesso! " << valor << endl;

break;


}

while (valor >0 ) 
{
    cout << valor << "   " << endl;
    valor--;

    break;
}


// if não funciona com int




return 0;
}



//if (A Escolha Simples) Com apenas Um Caminho
//if-else (A Escolha de Dois Caminhos)
//O else if (Múltiplas Escolhas em Cadeia) Ele permite que você verifique uma nova condição se a anterior for falsa. Você pode ter quantos else if quiser.
