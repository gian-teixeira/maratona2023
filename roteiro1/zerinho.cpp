#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    while(cin >> A){
        cin >> B; cin >> C;
        int soma = A + B + C;
        if(soma == 0 || soma == 3) cout << "*";
        if(soma == 1) cout << (A == 1 ? "A" : (B == 1 ? "B" : "C"));
        if(soma == 2) cout << (A == 0 ? "A" : (B == 0 ? "B" : "C"));
        cout << endl;
    }
    return 0;
}