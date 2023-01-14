#include <iostream>
#include <string>
using namespace std;

int main(){
    int direcoes[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
    int N, M, S;
    while(true){
        cin >> N;
        cin >> M;
        cin >> S;
        if(N == 0 || M == 0) break;

        char campo[N][M];
        int orientacao;
        int posicao[2];

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                char aux;
                cin >> aux;
                campo[i][j] = aux;
                if(aux == 'N') orientacao = 0;
                if(aux == 'L') orientacao = 1;
                if(aux == 'S') orientacao = 2;
                if(aux == 'O') orientacao = 3;
                if(aux == 'N' || aux == 'L' || aux == 'S' || aux == 'O'){
                    posicao[0] = j;
                    posicao[1] = i;
                }
            }
        }

        int pontos = 0;
        char cmd;
        for(int i = 0; i < S; i++){
            cin >> cmd;
            if(cmd == 'D') orientacao = (orientacao + 1) % 4;
            else if(cmd == 'E') orientacao = orientacao == 0 ? 3 : orientacao - 1;

            if(cmd == 'F'){
                int novaPosicao[2] = { posicao[0] + direcoes[orientacao][0], posicao[1] + direcoes[orientacao][1] };
                if(
                    campo[novaPosicao[1]][novaPosicao[0]] != '#' && 
                    novaPosicao[0] < M && novaPosicao[1] < N &&
                    novaPosicao[0] >=0 && novaPosicao[1] >=0
                ){
                    posicao[0] = novaPosicao[0];
                    posicao[1] = novaPosicao[1];
                    if(campo[posicao[1]][posicao[0]] == '*'){
                        pontos++;
                        campo[posicao[1]][posicao[0]] = '.';
                    }
                }
            }
        }

        cout << pontos << endl;
    }
    return 0;
}