#include <iostream>
#include <string>
using namespace std;
 
int main() {
    float x, y;
    cin >> x;
    cin >> y;

    string saida;
    if (x == 0 && y == 0) 
        saida = "Origem";
    else if (x == 0) 
        saida = "Eixo Y";
    else if (y == 0) 
        saida = "Eixo X";
    else if (x < 0) 
        if (y < 0) saida = "Q3";
        else saida = "Q2";
    else 
        if (y < 0) saida = "Q4";
        else saida = "Q1";

    cout << saida << endl;

    return 0;
}