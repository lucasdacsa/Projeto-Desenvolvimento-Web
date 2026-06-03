#include <iostream>
#include <string>
#include <vector> // Primeiro, você precisa incluir a biblioteca para usar o vector
using namespace std;


/* Struct serve para agrupar diferentes variáveis relacionadas em um único "pacote", 
criando um novo tipo de dado personalizado. Pense nele como uma ficha de cadastro.    */
struct Filme { 
    string titulo;
    string genero;
    string ano;
    float nota;
};

void cadastrar_filme() {

// Criando uma variável do tipo struct Filme
Filme meufilme;


cout << "Digite o Titulo do Filme: " << endl;
getline(cin, meufilme.titulo); /* getline, aceita titulos com espaço sem ele imprimiria apenas ate o primeiro espaço da frase 
                                  (Usado apenas em strings)*/
cout << "Digite o Genero do filme: " << endl;
getline (cin, meufilme.genero);

cout << "Digite o ano do filme: " << endl;
getline (cin, meufilme.ano);

cout << "Digite sua nota de 0.0 a 10.0: " << endl;
cin >> meufilme.nota;


if (meufilme.nota >=0.0 and meufilme.nota <=10.0) {

cout << "\n--- FILME CADASTRADO COM SUCESSO --" << endl;

cout << "O nome do titulo e: " << meufilme.titulo << endl;

cout << "O genero do filme e: " << meufilme.genero << endl;

cout << "O ano do filme e: " << meufilme.ano << endl;

cout << "Sua nota e: " << meufilme.nota << endl;

}

else {
    cout << "Dados Invalidos " << endl;
}

 }



void menu() {

int opcao;

cout << "\n ---SISTEMA DE GERENCIAMENTO DE FILMES--- " << endl;
cout << "\n--- MENU ---" << endl;

cout << "1 - Cadastrar Filme" << endl;
cout << "2 - Listar Filmes" << endl;
cout << "3 - Sair" << endl;
cin >> opcao;

switch (opcao) {

case 1: cadastrar_filme(minha_lista_de_filme); 
// Passa a lista principal para a função de cadastro

break;

case 2: cout << "Digite 2 para escolher um genero: " << opcao << endl;

break;

case 3: cout << "Digite 3 para escolher o ano: " << opcao << endl;

break;

default: cout << "opcao invalida! tente novamente. " << endl;

 }

while (opcao !=3) {

cout << opcao;

}

  }

int main () {
/*o vetor serve para Armazenar coleções de dados: É usado para guardar múltiplos elementos de um mesmo tipo de dado,
 como uma lista de inteiros, strings ou objetos. */
vector <Filme> minha_lista_de_filme; // Criamos o vetor da lista, sem definir um tamanho!


menu ();


return 0;

}
