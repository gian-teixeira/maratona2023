#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, diferenca, aux;
    int teste = 1;
    while(true){
        diferenca = 0;
        cin >> N;
        if(N == 0)
            break;
        cout << "Teste " << teste++ << endl;
        for(int i = 0; i < N; i++){
            cin >> aux;
            diferenca += aux;
            cin >> aux;
            diferenca -= aux;
            cout << diferenca << endl;
        }
        cout << endl;
    }
    return 0;
}