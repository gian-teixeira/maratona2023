#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, soma, aux;
    while(true){
        cin >> N;
        if(N == 0)
            break;
        soma = 0;
        for(int i = 0; i < N; i++){
            cin >> aux >> aux;
            soma += aux / 2;
        }
        cout << soma/2 << endl;
    }
    return 0;
}