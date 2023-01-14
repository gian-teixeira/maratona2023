#include <bits/stdc++.h>
using namespace std; 

int main(){
    int A, D, min;
    while(true){
        cin >> A >> D;
        if(A == 0 && D == 0) break;

        vector<int> atacantes(A);
        vector<int> defensores(D);

        for(int a = 0; a < A; a++)
            cin >> atacantes[a];

        while(--D > -1)
            cin >> defensores[D];
        sort(defensores.begin(), defensores.end());

        char output = 'N';

        while(--A > -1)
            if(atacantes[A] < defensores[1]){
                output = 'Y';
                break;
            }
        
        cout << output << endl;
    }
    return 0;
}