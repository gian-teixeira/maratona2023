#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int L, C;
    cin >> L;
    cin >> C;

    vector<int> maximos(C+1, 0);
    for(int i = 0; i < L; i++){
        int somaLinha = 0;
        for(int j = 0; j < C; j++){
            int aux;
            cin >> aux;
            somaLinha += aux;
            maximos[j] += aux;
        }
        if(somaLinha > maximos[C]) maximos[C] = somaLinha;
    }
    
    sort(maximos.begin(), maximos.end());
    cout << maximos[C] << endl;
    return 0;
}