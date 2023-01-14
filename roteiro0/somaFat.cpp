#include <iostream>
#include <string>
using namespace std;
 
int main() {
    int M, N;
    while(cin >> M){
        cin >> N;
        long fatM = 1;
        long fatN = 1;
        for(int i = 2; i <= M; i++) fatM *= i;
        for(int i = 2; i <= N; i++) fatN *= i;
        long soma = fatM + fatN;
        cout << soma << endl;
    }
    return 0;
}