#include <iostream>
using namespace std;
#include <string>


int main () {

int idade;

cout << "Informe a sua idade: ";
cin >> idade;

/*Em C++, a instrução else if é usada em "escadas" condicionais para testar múltiplas condições em sequência
    return 0;
    
    Sempre colocar () no começo do if.
    A instrução if é avaliada primeiro. */

if  (idade >=5 and idade <=7) {
cout << "O nadador se encaixa na categoria infantil A : ";

}

//Em C, && é o operador lógico E (ou AND) condicional. 
//Ele avalia duas condições e retorna verdadeiro somente se ambas as condições forem verdadeiras.
else if (idade >= 8 and idade <= 10) {
cout << "O nadador se encaixa na categoria infantil B. ";

}
else if (idade >= 11 and  idade <= 13) {
    cout << "O nadador se encaixa na categoria juvenil A. ";
}

else if (idade >= 14 and idade <= 17) {
    cout << "O nadador se encaixa na categoria juvenil B. ";

}

else if (idade >= 18 and idade <= 40){
    cout << "O nadador se encaixa na categoria Adulto. ";
}

else if (idade >= 41 and idade > 41) {
    cout << "O nadador se encaixa na categoria Master. ";
}

else {
    cout << "Categoria Invalida. ";

}



return 0; 

}