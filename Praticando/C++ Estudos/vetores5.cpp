#include <iostream>
using namespace std;

int main () {

int vet [5];

for (int i = 0; i < 5; i++) {

cout << "digite o numero: ";
cin >> vet[i];

}
cout << "\nvoce digitou: \n" << endl;
for (int i = 4; i >= 0; i--) {

cout << vet[i] << " ";

}

cout << endl;
    return 0;
}