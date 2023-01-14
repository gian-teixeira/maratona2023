#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, R;
    while(cin >> N){
        // Entrada dos dados
        cin >> R;
        vector<int> vivos;
        for(int i = 0; i < R; i++){
            int aux;
            cin >> aux;
            vivos.push_back(aux);
        }
        // Verificação previa da sobrevivência de todos os mergulhadores
        if(vivos.size() == N) {
            cout << "*" << endl;
            continue;
        }
        // Ordenação do vetor de vivos
        sort(vivos.begin(), vivos.end());
        // Procura das mortes
        vector<int> mortos;
        int i = 1, aux = 0;
        while(i <= N){
            while(i != vivos[aux] && i <= N)
                mortos.push_back(i++);
            i++;
            aux++;
        }
        // Impressão do resultado
        for(int i = 0; i < N - R; i++)
            cout << mortos[i] << " ";
        cout << "\n";
    }
    cout << "\n";
    return 0;
}