#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, aux;
    while(cin >> N){
        if(N == 0) break;
        vector<int> votos(N, 0);
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++){
                cin >> aux;
                votos[j] += aux;
            }
        sort(votos.rbegin(), votos.rend());
        cout << votos[0] << endl;
    }
    return 0;
}
