#include <iostream>
#include <string>

using namespace std;

int main () {

//Variaveis
int produto,dia;
double preco; 
string opcao;
//float preco1 = 59.90, preco2 = 299.90, preco3 = 899.90, valor;

//Entradas
cout << " Bem vindo ao Joja Market o Melhor Mercado de toda região! "<< endl;

cout << " Escolha Um Dos Itens Disponiveis. \n #1 Cobre., #2 Prata., #3 Ouro. "<< endl;
cin >> produto;

cout << "O Preco do produto é: " << endl;
cin >> preco;

cout << "Escolha o dia da semana:\n 1-Seg, 2-Ter, 3-Qua, 4-Qui, 5-Sex, 6-Sab, 7-Dom" << endl;
cin >> dia;

//Switchs
//tabela de preços do super mercado
switch (produto) {

case 1:opcao = 200; cout << "Voce escolheu Cobre! " << endl;
break;

case 2:opcao = 400; cout << "Voce Escolheu Prata! " << endl;
break;

case 3:opcao = 800; cout << "Voce Escolheu Ouro! " << endl;
break;

}
// dia da semana e promoções
switch (dia) {

case 1:dia -30; cout << "Quinta Feira! " or cout << "Sexta Feira" << endl;
break;

case 2:dia -400; cout << "Segunda Feira! " or cout << "Terça Feira" or cout << "quarta feira" << endl;
break;

case 6:dia -400; cout << "Sabado! " << endl;
break;

case 7: cout << "Domingo! " << endl;
break;

}
return 0;

}