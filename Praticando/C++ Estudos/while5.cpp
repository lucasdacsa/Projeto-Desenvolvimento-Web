#include <iostream>
#include <string>
using namespace std;

int main () {

int opcao =0;


while (opcao != 3 ) {

cout << "----------  Menu  ----------" << endl;
cout << "1- Mensagem de bem vindo, 2- Ver o numero secreto, 3- Sair. \nEscolha uma opcao: " << endl;
cin >> opcao;


if (opcao ==1 ) {

    cout << "Seja muito bem vindo!!\n " << endl;
}
else if (opcao ==2) {

cout << "O Numero secreto e: \n42 " << endl;

}
else if (opcao ==3) {

cout << "\nSaindo..." << endl;

}

else {
    cout << "\nopcao invalida." << endl;
}

}


    return 0;
}