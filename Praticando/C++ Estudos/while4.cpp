#include <iostream>

using namespace std;

int main () {

int senhaCorreta = 159357;
int senhaDigitada;

cout << "digite a senha: " << endl;
cin >> senhaDigitada;

while (senhaDigitada != senhaCorreta) {

cout << "Senha incorreta. Tente Novamente: " << endl;
cin >> senhaDigitada;

}
cout << " Acesso permitido!! Senha Correta. " << endl;

    return 0;
}