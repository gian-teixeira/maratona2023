#include <bits/stdc++.h>
using namespace std;

#define numero(a) (int)a - (int)'0'

int main() {
    int N, resultado, aux;
    int teste = 1;
    while(true){
        resultado = 0;
        cin >> N;
        if(N == 0)
            break;
        for(int i = 0; i < N; i ++){
            cin >> aux;
            resultado += aux;
        }
        cout << "Teste " << teste++ << endl;
        cout << resultado << "\n\n";
    }
    return 0;
}