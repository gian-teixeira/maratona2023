#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    char times[] = "ABCDEFGHIJKLMNOP";
    for(int i = 3; i >= 0; i--)
        for(int j = 0; j < pow(2, i);j++){
            int A, B;
            cin >> A;
            cin >> B;
            times[j] = times[2*j + (A < B ? 1 : 0)];
        }
    cout << times[0] << endl;
    return 0;
}