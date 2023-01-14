#include <iostream>
using namespace std;

int main(){
    int Q, D, P;
    while(true){
        cin >> Q;
        if (Q == 0) break;
        cin >> D;
        cin >> P;
        int resposta = P * ((float)(Q*D) / (P - Q));
        cout << resposta << (resposta != 1 ? " paginas" : " pagina") << endl;
    }
    cout << "\n";
    return 0;
}