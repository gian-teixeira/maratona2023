#include <iostream>
using namespace std;

int main(){
    int consumo, conta = 0;
    cin >> consumo;
    int aux;
    if(consumo > 100){
        aux = consumo-100;
        conta += aux*5;
        consumo -= aux;
    }
    if(consumo > 30){
        aux = consumo-30;
        conta += aux*2;
        consumo -= aux;
    }
    if(consumo > 10){
        aux = consumo-10;
        conta += aux;
        consumo -= aux;
    }
    conta += 7;
    cout << conta << endl;
    return 0;
}