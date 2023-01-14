#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define info pair<char, int>
#define base(a) a.first
#define num(a) a.second
#define alien vector<info>

int main(){
    int N;
    char aux;
    while(true){
        cin >> N;
        //cout << N << endl;
        if(N == 0) break;

        vector<alien> aliens(N);
        for(int i = 0; i < N; i++){
            for(int b = 0; b < 3; b++){
                cin >> aux;
                bool existe = false;
                for(int j = 0; j < aliens[i].size(); j++)
                    if(base(aliens[i][j]) == aux){
                        existe = true;
                        num(aliens[i][j]) += 1;
                        break;
                    }
                if(!existe){
                    info tmp = {aux, 1};
                    aliens[i].push_back(tmp);
                }
            }
        }

        vector<alien> especies;
        especies.push_back(aliens[0]);
        for(int i = 0; i < aliens.size(); i++)
            if(find(all(especies), aliens[i]) == especies.end())
                especies.push_back(aliens[i]);
        
        cout << especies.size() << endl;
    }
    return 0;
}