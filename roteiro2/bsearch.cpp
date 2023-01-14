#include <bits/stdc++.h>
using namespace std;

int busca_binaria(vector<int> &vetor, int valor, int inicio, int final){
    if(inicio > final)
        return -1;
    int centro = (final + inicio) / 2;
    if(vetor[centro] == valor) return centro;
    else if (vetor[centro] > valor) return busca_binaria(vetor, valor, inicio, centro - 1);
    return busca_binaria(vetor, valor, centro + 1, final);
}

int main(){
    int N, C, aux;
    cin >> N >> C;
    vector<int> lista(N);
    for(int i = 0; i < N; i++)
        cin >> lista[i];
    for(int c = 0; c < C; c++){
        cin >> aux;
        cout << busca_binaria(lista, aux, 0, lista.size() - 1) << endl;
    }
    return 0;
}