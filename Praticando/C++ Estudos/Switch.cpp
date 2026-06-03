#include <iostream>
#include <string>
using namespace std;

/*]
if ... else → só 2 caminhos (verdadeiro ou falso).
else if → permite criar vários testes intermediários (3 ou mais caminhos).
*/

//a palavra case significa “caso”. Ela marca um valor específico que a variável testada pode assumir.
/**/

int main () {

int opcao = 2;

switch (opcao){

case 1:
cout << "primeiro " << endl;

case 2:
cout << "Segundo " << endl;

case 3:
cout << "Terceiro" << endl;

break;

 default:
        cout << "Outro" << endl;

}


return 0;

}



