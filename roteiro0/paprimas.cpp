#include <iostream>
#include <string>
using namespace std;

int main(){
    string palavra;
    while(cin >> palavra){
        int soma = 0;
        for(int i = 0; i < palavra.size(); i++){
            int letra = (int)palavra[i];
            soma += letra <= 90 ? letra - 38 : letra - 96;
        }
        bool prima = true;
        for(int i = 2; i < soma; i++)
            if(soma % i == 0){
                prima = false;
                break;
            }
        cout << (prima ? "It is a prime word." : "It is not a prime word.") << endl;
    }
}