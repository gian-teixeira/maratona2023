#include <bits/stdc++.h>
using namespace std;

#define tudo(a) a.begin(), a.end()

#define estrutura pair<int, pair<int, pair<int, pair<int, pair<int, string>>>>>

#define nome(t) t.second.second.second.second.second
#define jogos(t) t.second.second.second.second.first
#define pontos(t) t.first
#define saldo(t) t.second.first
#define golsMarcados(t) t.second.second.first
#define golsSofridos(t) t.second.second.second.first

int main()
{
    while (true)
    {
        int nTimes, nJogos;
        cin >> nTimes >> nJogos;
        if (nTimes == 0 && nJogos == 0)break;

        // Pontos, Saldo, GolsMarcados, GolsSofridos, Nome
        vector<estrutura> times(nTimes);
        for(int i = 0; i < nTimes; i++){
            string tmpName;
            cin >> tmpName;
            nome(times[i]) = tmpName;
            golsMarcados(times[i]) = 0;
            golsSofridos(times[i]) = 0;
            saldo(times[i]) = 0;
            pontos(times[i]) = 0;
            jogos(times[i]) = 0;
        }

        for(int i = 0; i < nJogos; i++){
            char bin;
            string time1, time2;
            int gol1, gol2;
            cin >> time1 >> gol1 >> bin >> gol2 >> time2;

            for(int t = 0; t < nTimes; t++){
                if(nome(times[t]) == time1){
                    jogos(times[t]) += 1;
                    golsMarcados(times[t]) += gol1;
                    golsSofridos(times[t]) += gol2;
                    saldo(times[t]) += gol1 - gol2;
                    if(gol1 > gol2) pontos(times[t]) += 3;
                    else if(gol1 == gol2) pontos(times[t]) += 1;
                }
                else if(nome(times[t]) == time2){
                    jogos(times[t]) += 1;
                    golsMarcados(times[t]) += gol2;
                    golsSofridos(times[t]) += gol1;
                    saldo(times[t]) = gol2 - gol1;
                    if(gol2 > gol1) pontos(times[t]) += 3;
                    else if(gol2 == gol1) pontos(times[t]) += 1;
                }
            }
        }

        set< estrutura > set(tudo(times));
        vector< estrutura > timesOrdenados(tudo(times));
        int totalPontos = 0;
        for(int i = 0; i < nTimes; i++){
            totalPontos += pontos(times[i]);
            for(int j = i+1; j < nTimes; j++){
                if(times[i] < times[j]) 
                    swap(times[i], times[j]);
            }
        }
        cout << totalPontos << endl;

        estrutura grupoAtual;
        for (int i = 0; i < nTimes; i++){     
            if(
                pontos(timesOrdenados[i]) != pontos(grupoAtual) ||
                saldo(timesOrdenados[i]) != saldo(grupoAtual) ||
                golsMarcados(timesOrdenados[i]) != golsMarcados(grupoAtual)
            ){
                cout << i+1 << ". ";
                pontos(grupoAtual) = pontos(timesOrdenados[i]);
                saldo(grupoAtual) = saldo(timesOrdenados[i]);
                golsMarcados(grupoAtual) = golsMarcados(timesOrdenados[i]);
            }
            else {
                cout << "   ";
            }
            stringstream ss;
            ss << setw(15) << nome(timesOrdenados[i]);
            string tmp = ss.str();
            cout << tmp;
            cout << setw(3) << pontos(timesOrdenados[i]); 
            cout << setw(3) << jogos(timesOrdenados[i]);
            cout << setw(3) << golsMarcados(timesOrdenados[i]);
            cout << setw(3) << golsSofridos(timesOrdenados[i]);
            cout << setw(3) << saldo(timesOrdenados[i]);
            if(
                pontos(timesOrdenados[i]) == 0 &&
                jogos(timesOrdenados[i]) == 0 &&
                golsMarcados(timesOrdenados[i]) == 0 &&
                golsSofridos(timesOrdenados[i]) == 0 &&
                saldo(timesOrdenados[i]) == 0
            ){
                cout << setw(6) << "N/A";
            }
            else {
                cout << " " << fixed << setprecision(2) << (float)pontos(timesOrdenados[i]) / (float)totalPontos * 100;
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
