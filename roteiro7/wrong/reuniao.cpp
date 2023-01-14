#include <bits/stdc++.h>
using namespace std;

int distance(vector<vector<int>> &table, int origin, int target){
	if(origin == target) return 0;
	
	int better = min(table[origin][target], table[target][origin]);
	
	int aux = 0;
	for(int i = origin + 1; i < table.size(); i++){
		aux = table[origin][i] + distance(table, i, target);
		if(better > aux) better = aux;
	}
	
	table[target][origin] = better;
	return better;
}

int main(){
	int N, M, aux_o, aux_e, aux_d;
	cin >> N >> M;

	vector<vector<int>> table(N, vector<int>(N, 200));
	for(int i = 0; i < M; i++){
		cin >> aux_o >> aux_e >> aux_d;
		table[aux_o][aux_e] = min(table[aux_o][aux_e], aux_d);
	}	

	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			table[i][j] = distance(table, i, j);
		}
	}
	
	int minMaxDistance = 200,
		localMax;
	for(int j = 0; j < N; j++){
		localMax = 0;
		for(int i = 0; i < N; i++)
			if(table[i][j] > localMax) localMax = table[i][j];
		if(localMax < minMaxDistance)
			minMaxDistance = localMax;
	}

	cout << minMaxDistance << endl;

}
