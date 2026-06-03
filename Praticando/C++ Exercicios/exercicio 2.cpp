#include <iostream>
using namespace std;
#include <string>

int main () {

string nome;
float nota1, nota2, nota3, media;

    // Entrada de dados
cout << "Digite o nome do aluno: ";
getline(cin, nome);

cout << "Digite a primeira nota: ";
cin >> nota1;

cout << "Digite a segunda nota: ";
cin >> nota2;

cout << "Digite a terceira nota: ";
cin >> nota3;

    // Cálculo da média
media = (nota1 + nota2 + nota3) / 3; //   (/) Divisão

    // Saida
cout <<"\n---RESULTADO---";

cout <<"\n Aluno: " << nome;

cout <<"\n A sua media final foi: " << media;




 return 0;
}