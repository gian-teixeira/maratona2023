#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define all(a) a.begin(), a.end()

int main(){
    int N;
    cin >> N;
    while(N-- > 0){
        string proibida, alvo;
        cin >> proibida >> alvo;

        alvo.append(alvo);

        bool presente = false;
        presente = alvo.find(proibida) != string::npos;
        if(!presente){
            reverse(all(alvo));
            presente = alvo.find(proibida) != string::npos;
        }   

        cout << (presente ? "S" : "N") << endl;
    }
    return 0;
}