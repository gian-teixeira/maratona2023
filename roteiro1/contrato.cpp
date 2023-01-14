#include <bits/stdc++.h>
using namespace std;

int main(){
    char falha;
    string erro;
    while(true){
        cin >> falha >> erro;
        if(falha == '0' && erro == "0") break;
        bool zeros = true;
        int i = 0;
        for(int i = 0; i < erro.size(); i++){
            if(zeros && erro[i] != '0' && erro[i] != falha) 
                zeros = false;
            if(!zeros && erro[i] != falha)
                    cout << erro[i];
            if(zeros && i == erro.size() - 1)
                cout << 0;
        }
        cout << endl;
    }
    return 0;
}