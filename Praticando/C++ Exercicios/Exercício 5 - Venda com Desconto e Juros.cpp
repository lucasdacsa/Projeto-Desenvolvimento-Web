#include <iostream>
#include <string>
using namespace std;
int main() {

    int produto;
    float preco = 800.0;
    float a_vista = preco * 0.95;         // 5% de desconto
    float total_parcelado = preco * 1.10; // 10% de acrescimo
    float parcela = total_parcelado / 5;  // 5 parcelas

    string tipo_pagamento; // Variavel para armazenar o tipo de pagamento

    // entrada
    cout << "Como vai ser o pagamento? \n1 - A vista \n2 - Parcelado \n";
    cin >> produto;

    // ifs
    if (produto == 1) 
    {
        cout << "Valor do produto: " << a_vista << endl;
    }
    else if (produto == 2)
    {
        cout << "Valor do produto (total parcelado): " << total_parcelado << endl;
        cout << "Valor de cada parcela: " << parcela << endl;
    }
    else
    {
        cout << "Opcao invalida, por favor escolha 1 ou 2." << endl;
    }

    // saida
    cout << "Digite o tipo de pagamento: ";
    cin >> tipo_pagamento;

    cout << "Produto Comprado.! ";

    return 0;
}
