#include <iostream>
using namespace std;

int main () {

int contador = 0 ;

cout << " Contador:  ";

while (contador <= 5) {

cout << " Contador:  " << contador << endl;
contador++;

}


return 0;
}


/*

#include <iostream>

using namespace std;

void variaveis() {
int i = 0;

while (i <= 5){
    cout << "contador: " << i << endl;
        //    ATUALIZAÇÃO: Incrementa o valor de 'i' em 1. (i++ é o mesmo que i = i + 1).
        //    Isto é ESSENCIAL para que a condição do 'while' eventualmente se torne
        //    falsa (quando 'i' chegar a 6), fazendo o laço terminar.
    i++;  

}

  }

int main () {

cout << "... Iniciando Programa... " << endl;

    // CHAMADA DA FUNÇÃO: O programa agora executa todo o código que está 
    // dentro da função 'variaveis'. Ele só continuará para a próxima linha do 'main'
    // depois que a função 'variaveis' terminar seu trabalho por completo.
variaveis ();

cout << "... Programa finalizado ... " << endl;

return 0;
}

*/



    
