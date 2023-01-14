#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> piramide(9, vector<int> (9, 0));
    while(N-- > 0){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j <= i; j++)
                cin >> piramide[2*i][2*j];
        }
        
        for(int i = 0; i < 4; i++){
            for(int j = 0; j <= i; j++){
                int E = piramide[2*i+2][2*j];     
                int D = piramide[2*i+2][2*j+2];
                piramide[2*i+1][2*j+1] = (piramide[2*i][2*j] - E + D)/2;
                piramide[2*i+1][2*j] = piramide[2*i][2*j] - piramide[2*i+1][2*j+1];
                piramide[2*i+2][2*j+1] = piramide[2*i+1][2*j] - E;
            }
        }
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j <= i; j++)
                cout << piramide[i][j] << (j != i ? " " : "");
            cout << endl;
        }
    }
    return 0;
}