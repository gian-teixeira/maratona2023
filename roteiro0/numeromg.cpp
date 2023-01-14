#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string A, B;
    while(true){
        cin >> A;
        cin >> B;
        if(A == "0" && B == "0") break;

        int soma = stoi(A, nullptr, 36) + stoi(B, nullptr, 36);

        vector<char> resultado;
        while(soma != 0) {
            int tmp = soma % 36;
            resultado.insert(resultado.begin(), (char)(tmp > 9 ? tmp + 55 : tmp + 48));
            soma /= 36;
        }

        for(int i = 0; i < resultado.size() ; i++)
            cout << resultado[i];
        cout << endl;
    }
    return 0;
}