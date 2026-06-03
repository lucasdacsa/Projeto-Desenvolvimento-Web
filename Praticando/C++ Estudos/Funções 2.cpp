#include <iostream>
#include <string>
using namespace std;

bool ehpar (int n) {

	return n % 2 == 0;

}




int main () {

int num;

cout << " digite um numero" << endl;
cin >> num;

if (ehpar (num)) {

	cout << "Par" << endl;
} 

else {
	cout << "Impar" << endl;
}


 return 0;
}