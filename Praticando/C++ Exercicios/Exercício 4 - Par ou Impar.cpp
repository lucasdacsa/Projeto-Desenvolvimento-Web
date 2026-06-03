#include <iostream>
#include <string>
using namespace std;

int main() {
    int inteiro;
    string resultado; // variável para armazenar o resultado

    cout << "Digite um número: ";
    cin >> inteiro;

    if (inteiro % 2 == 0) {
        resultado = "par";
    } else {
        resultado = "impar";
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}
