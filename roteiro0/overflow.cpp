#include <iostream>
using namespace std;

int main(){
    int max, a, b;
    char sinal;

    cin >> max;
    cin >> a;
    cin >> sinal;
    cin >> b;

    int operacao = sinal == '+' ? a + b : a * b;
    
    cout << (operacao > max ? "OVERFLOW" : "OK") << endl;
}