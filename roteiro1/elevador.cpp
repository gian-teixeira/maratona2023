#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, C, aux, pessoas = 0;
    char ultrapassou = 'N';
    cin >> N >> C;
    while(N-- > 0){
        cin >> aux;
        pessoas -= aux;
        cin >> aux;
        pessoas += aux;
        if(pessoas > C){
            ultrapassou = 'S';
            break;
        }
    }
    cout << ultrapassou << endl;
    return 0;
}