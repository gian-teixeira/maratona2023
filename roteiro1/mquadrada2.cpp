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
                cout << setw(3) << abs(j-i) + 1;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}