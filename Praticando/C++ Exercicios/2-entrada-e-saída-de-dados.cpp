#include <iostream>
#include <string> // Biblioteca Necessaria para usar string
using namespace std;

int main(){

string nome;
int idade;
float altura;

// Saída de dados (mensagem para o usuário)
cout << "digite seu nome";
getline(cin, nome); // Lê a linha inteira (inclusive espaços)

// Usar cin com o operador de extração (>>):
// >> é o operador de extração (extrair dados da entrada).
// O operador >> extrai os dados do fluxo de entrada cin e os armazena na variável especificada. 

cout << "digite sua idade : ";
cin >> idade;  // Lê um número inteiro

cout << "digite sua altura (em metros)";
cin >> altura; // Lê um número real

// Exibindo os dados inseridos

cout << "\n---DADOS INSERIDOS---" << endl;
cout << "Nome: " << nome << endl;
cout << "idade: " << idade << "anos"<<endl;
cout << " altura: " << altura << "metros" << endl;


return 0;
}