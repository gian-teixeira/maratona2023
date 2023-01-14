#include <bits/stdc++.h>
using namespace std;

#define tudo(a) a.begin(), a.end()

int main(){
    int N, pos, ultrapassagens;
    while (cin >> N){
        vector<int> largada(N);
        vector<int> chegada(N);

        for (int i = 0; i < N; i++)
            cin >> largada[i];
        for (int i = 0; i < N; i++)
            cin >> chegada[i];

        ultrapassagens = 0;
        for(int i = 0; i < N; i++)
            while(largada[i] != chegada[i]){
                pos = find(tudo(largada), chegada[i]) - largada.begin();
                swap(largada[pos], largada[pos-1]);
                ++ultrapassagens;
            }
            
        cout << ultrapassagens << endl;
    }

    return 0;
}