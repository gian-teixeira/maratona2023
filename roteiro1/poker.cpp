#include <bits/stdc++.h>
using namespace std;

#define carta pair<int, int>
#define valor(c) c.second
#define quantidade(c) c.first 

int main() {
    int N, pontos, aux;
    vector<int> cartas;
    cin >> N;
    for(int n = 1; n <= N; n++){
        vector<carta> cartas(5, {0, 0});
        int tamanhoCartas = 0;

        for(int i = 0; i < 5; i++){
            cin >> aux;
            bool presente = false;
            for(int j = 0; j < 5; j++)
                if(valor(cartas[j]) == aux){
                    quantidade(cartas[j])++;
                    presente = true;
                    break;
                }
            if(!presente){
                valor(cartas[tamanhoCartas]) = aux;
                quantidade(cartas[tamanhoCartas]) = 1;
                tamanhoCartas++;
            }
        }

        set<carta> tmpSet(cartas.begin(), cartas.begin() + tamanhoCartas);
        vector<carta> cartasOrdenadas(tmpSet.rbegin(), tmpSet.rend());
        cartas = cartasOrdenadas;

        if( 
            cartas.size() == 5 &&
            (valor(cartas[0]) + valor(cartas[1]) + valor(cartas[2]) + valor(cartas[3]) + valor(cartas[4])) == (valor(cartas[0]) + valor(cartas[4]))*5/2
        ){
            pontos = valor(cartas[4]) + 200;
        }
        else if(quantidade(cartas[0]) == 4){
            pontos = valor(cartas[0]) + 180;
        }
        else if(quantidade(cartas[0]) == 3 && cartas.size() == 2){
            pontos = valor(cartas[0]) + 160;
        }
        else if(quantidade(cartas[0]) == 3 && cartas.size() == 3){
            pontos = valor(cartas[0]) + 140;
        }
        else if(quantidade(cartas[0]) == 2 && cartas.size() == 3){
            pontos = 3*valor(cartas[0]) + 2*valor(cartas[1]) + 20;
        }
        else if(quantidade(cartas[0]) == 2 && cartas.size() == 4){
            pontos = valor(cartas[0]);
        }
        else{
            pontos = 0;
        }

        cout << "Teste " << n << endl;
        cout << pontos << "\n\n";
    }
    return 0;
}