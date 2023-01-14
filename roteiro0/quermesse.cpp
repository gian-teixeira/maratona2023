#include <iostream>
using namespace std;

int main(){
    int N, teste = 1;
    while(true){
        cin >> N;
        if (N == 0) break;
        int aux;
        for(int i = 1; i <= N; i++){
            cin >> aux;
            if (i == aux) {
                cout << "Teste " << teste++ << endl;
                cout << aux << "\n\n";
            }
        }
    }
    return 0;
}