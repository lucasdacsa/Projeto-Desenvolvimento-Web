#include <iostream>
using namespace std;

int main() {
    int opcao;

    do {
        cout << "---- Menu ----" << endl;
        cout << "1 - Mensagem de boas-vindas" << endl;
        cout << "2 - Ver o numero secreto" << endl;
        cout << "3 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Seja muito bem-vindo!!" << endl;
        } 
        else if (opcao == 2) {
            cout << "O número secreto e 42!" << endl;
        } 
        else if (opcao == 3) {
            cout << "Saindo..." << endl;
        } 
        else {
            cout << "Opcao inválida. Tente novamente." << endl;
        }

        cout << endl; // apenas para deixar o menu mais bonito

    } while (opcao != 3); // verifica no final se deve repetir

    return 0;
}