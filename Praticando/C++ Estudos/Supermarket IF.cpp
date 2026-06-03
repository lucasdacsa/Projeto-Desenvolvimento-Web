#include <iostream>
#include <string>

using namespace std;

int main () {

    int produto, dia;
    float cobre = 200 ,prata = 500 ,ouro = 800;
//Entradas
cout << " Bem vindo ao Joja Market o Melhor Mercado de toda regiao! "<< endl;

cout << " Escolha Um Dos Itens Disponiveis. \n #1 Cobre., #2 Prata., #3 Ouro. "<< endl;
cin >> produto;

cout << "Escolha o dia da semana:\n 1-Seg, 2-Ter, 3-Qua, 4-Qui, 5-Sex, 6-Sab, 7-Dom" << endl;
cin >> dia;

// Se for Ouro e dia entre segunda e quarta, aplica desconto
if (dia >= 1 and dia <= 4 and produto == 3)  {

    ouro /= 2.2; // desconto especial de metade do valor para na ouro segunda, terça ou quarta
    cout << "Desconto de segunda terca e quarta aplicado! \nO Novo preco do produto e: " << ouro << endl;


   }
if (dia >= 4 and dia <= 6 and produto == 3) {  


    ouro /= 2.3; // desconto especial de um terço para ouro as quintas e sextas
    cout << "Desconto de quinta ou sexta aplicado!\n item comprado com desconto :  " << ouro << endl;


 }

 if (dia >= 6 and dia <= 7 and produto == 2 ) {

    prata *= 3;
    //preço triplo para o sabado ou domingo
    cout << "Hoje o preco desse item está o triplo!\n Item comprado por mais caro : "  << prata << endl;
 }

 if (dia >=7 and dia <=8 and produto == 1) {

    cobre -=100;
    cout << "promocao de -100 de cobre para domingo\n Item comprado com desconto Valor:  " << cobre << endl;
 }

 else
 cout << "Dia de preco normal para esse item! " << endl;


 

return 0;

}