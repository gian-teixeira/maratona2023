#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    double R;
    cin >> R;
    cout << fixed << setprecision(4);
    cout << "A=" << pow(R, 2) * 3.14159 << endl;
    return 0;
}