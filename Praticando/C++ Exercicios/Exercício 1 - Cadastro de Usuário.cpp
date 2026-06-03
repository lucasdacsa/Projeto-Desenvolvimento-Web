#include <iostream> 
#include <string>
using namespace std;

int main (){

string Nome ;
int Idade ;
float Peso ;
char Genero ;

//<< é o operador de inserção (inserir dados na saída).
            // Leitura dos dados
cout << "digite seu nome: ";
getline(cin, Nome); // Lê nome completo, com espaços

cout << "digite sua idade: ";
cin >> Idade;

cout << "digite seu peso: ";
cin >> Peso;

cout << "digite seu genero (M ou F): ";
cin >> Genero;

cout << "\n---Cadastro realizado com sucesso.---\n";

            // Exibindo os dados
cout << "Seu nome e: " << Nome << endl;
cout << "Sua idade e: " << Idade << endl;
cout << "Seu peso e: " << Peso << endl;
cout << "Seu genero e: " << Genero << endl;

return 0;

}