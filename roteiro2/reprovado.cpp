#include <bits/stdc++.h>
using namespace std; 

#define aluno pair<int, string>
#define nome(a) a.second
#define nota(a) a.first

int main(){
    int N;
    int instancia = 0;
    while(cin >> N){
        vector<aluno> alunos(N);
        for(int n = 0; n < N; n++)
            cin >> nome(alunos[n]) >> nota(alunos[n]);
        sort(alunos.rbegin(), alunos.rend());
        
        int p = 1;
        while(nota(alunos[++p]) == nota(alunos[0]));

        cout << "Instancia " << ++instancia << endl;
        cout << nome(alunos[p]) << "\n\n";
    }
    return 0;
}