#include <iostream>
#include <string>
using namespace std;
#include <iomanip> // para formatar casas decimais

int main () {

string nome;
float peso, altura, imc;

// Entrada de dados.

cout << "Digite seu nome: ";
getline(cin, nome);

cout << "Digite seu peso: ";
cin >> peso;

cout << "Digite sua altura: ";
cin >> altura;

 // Cálculo do IMC
 imc = peso / (altura * altura);


  // Classificação usando operador ternário
 string classificacao = (imc >= 18.5 && imc <=24.9) ? "Peso normal" : "Peso fora da faixa normal";


// saida de dados
cout << "\n--- RESULTADO ---\n";

cout << "Nome: " << nome << endl ;
cout << "Peso: " << peso << endl ;
cout << "Altura: " << altura << endl ;
cout << "imc: " << imc << endl;
cout << "Classificacao: " << classificacao << endl;




    return 0;
}