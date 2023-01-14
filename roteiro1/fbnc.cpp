#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    cout << "0 1 ";
    int buffer[] = {0, 1};
    while(N-- > 2){
        int aux = buffer[0];
        buffer[0] = buffer[1];
        buffer[1] += aux;
        cout << buffer[1];
        if(N > 2) cout << " ";
    }
    cout << endl;
    return 0;
}