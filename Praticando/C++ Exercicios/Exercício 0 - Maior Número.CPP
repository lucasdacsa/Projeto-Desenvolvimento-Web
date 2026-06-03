#include <iostream>
#include <string>
using namespace std;

int main () {

int num1, num2;

//Entrada
cout << "Digite um numero.: ";
cin >> num1;

cout << "Digite outro numero.: ";
cin >> num2;

// Processamento e saída
if (num1 > num2) { // Se o primeiro número for maior que o segundo, então:
cout << "Numero maior: " << num1 << endl;
}

else if (num2 > num1) {
cout << "Numero maior: " << num2 << endl;
}

if (num1 < num2) { // Se o primeiro número for maior que o segundo, então:
cout << "Numero menor: " << num1 << endl;
}

else if (num2 < num1) {
cout << "Numero menor: " << num2 << endl;
}

else if (num2 < num1) {
cout << "Numero menor: " << num2 << endl;
}

else {
    cout << "Os dois numeros sao iguais. ";
}


return 0;

}