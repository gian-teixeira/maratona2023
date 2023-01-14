#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int W, H, N;
    int teste = 0;
    while(++teste){
        cin >> W;
        cin >> H;
        cin >> N;
        if(W == 0 || H == 0) break;
        
        char tabuleiro[W][H];
        for(int i = 0; i < W; i++)
            for(int j = 0; j < H; j++)
                tabuleiro[i][j] = '-';

        int x1, x2, y1, y2;
        for(int i = 0; i < N; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            for(int Y = min(y1, y2); Y <= max(y1, y2); Y++)
                for(int X = min(x1, x2); X <= max(x1, x2); X++)
                    tabuleiro[Y-1][X-1] = '*';
        }

        int contador = 0;
        for(int i = 0; i < W; i++)
            for(int j = 0; j < H; j++)
                if(tabuleiro[i][j] == '-') contador++;
        
        if(contador == 0) cout << "There is no empty spots." << endl;
        else cout << "There is " << contador << " empty spots." << endl;
    }
    return 0;
}