#include <iostream>
using namespace std;

int main(){
    int N;
    int instancia = 0;
    while(cin >> N){
        bool achou = false;
        int soma = 0;
        int aux;
        for(int i = 0; i < N; i++){
            cin >> aux;
            if(aux == soma) achou = true;
            else if (!achou) soma += aux;
        }
        cout << "Instancia " << ++instancia << endl;
        if(!achou) cout << "nao achei" << endl;
        else cout << soma << endl;
        cout << "\n";
    }
}