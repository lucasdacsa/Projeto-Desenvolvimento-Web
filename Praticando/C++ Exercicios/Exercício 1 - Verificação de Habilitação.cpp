#include <iostream>
using namespace std;

int main () {

int ano_nascimento, ano_atual;

cout << "digite sua data de nascimento: ";
cin >> ano_nascimento;

cout << "digite o ano atual: ";
cin >> ano_atual;

if (ano_nascimento >=18) {
cout << "pode tirar a habilitacao: "<< endl;
}

else {
        cout << "Não pode tirar a habilitacao." << endl;
    }

    
return 0;

}