#include <iostream>
#include <string>
using namespace std;

int main (){

string aluno;
float nota1, nota2, nota3, media;

cout << "\ninforme o nome do aluno: ";
getline (cin, aluno); // Lê o nome completo

cout << "\nInforme a primeira nota: ";
cin >> nota1;

cout << "\nInforme a segunda nota: ";
cin >> nota2;

cout << "\nInforme a terceira nota: ";
cin >> nota3;

 // Cálculo da média
media = (nota1 + nota2 + nota3) / 3;

 // Exibe o resultado
cout << "\n--- RESULTADO ---\n";
cout << "Aluno: " << aluno << endl; // endl, serve para “pular uma linha” no que está sendo impresso na tela
cout << "Media: " << media << endl;
    return 0;
}