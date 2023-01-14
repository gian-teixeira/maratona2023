#include <iostream>
using namespace std;
 
int main() {
    int max;
    int pos;
    for(int i = 1; i < 101; i++){
        int aux;
        cin >> aux;
        if (aux > max){
            max = aux;
            pos = i;
        }
    }
    cout << max << endl;
    cout << pos << endl;
    return 0;
}