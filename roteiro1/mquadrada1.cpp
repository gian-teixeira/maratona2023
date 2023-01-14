#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    while(true){
        cin >> N;
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j != 0) cout << " ";
                cout << setw(3) << min(min(min(i+1, j+1), N-i), N-j);
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}