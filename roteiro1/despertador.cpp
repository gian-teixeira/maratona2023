#include <bits/stdc++.h>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    int T1, T2;
    while(true){
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
            break;
        T1 = (h1*60 + m1);
        T2 = (h2*60 + m2);
        cout << (T1 < T2 ? T2 - T1 : 1440 - T1 + T2) << endl;
    }
    return 0;
}