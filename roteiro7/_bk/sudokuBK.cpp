#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<vector<int>> &table, int n, int x, int y, int element){

	// Verifica linhas e colunas
	for(int i = 0; i < 9; i++)
		if( table[i][x] == n or table[y][i] == element )
			return false;

	// Verifica um quadrado
	int y0 = y / 3 * n,
		x0 = x / 3 * n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if( table[i + y0][j + x0] == element )
				return false;
	
	// Retorna true caso nenhum problema
	// tenha sido encontrado
	return true;
}

bool solve(vector<vector<int>> &table, int n){
	for(int y = 0; y < table.size(); y++)
		for(int x = 0; x < table.size(); x++)
			// Verifico se a posição está vazia
			if(table[y][x] == 0){
				printf("%d %d\n", x, y);
				bool least = false;

				for(int i = 1; i <= 9; i++){
					// Verifico se é possível colocar o
					// número na posição atual
					if(possible(table, n, x, y, i)){
						// Sendo possível, coloco o número
						table[y][x] = i;
						least = true;
						
						// Chamo a função recursivamente e,
						// se houver erro na chamada recursiva,
						// limpo a posição para continuar o loop
						if(!solve(table, n)) table[y][x] = 0;
					}
				}

				if(!least) return false;
			}
	
	return true;
}

int main(){
	int n;
	cin >> n;

	vector<vector<int>> table(pow(n, 2), vector<int>(pow(n, 2)));

	for(int i = 0; i < pow(n, 2); i++)
		for(int j = 0; j < pow(n, 2); j++)
			cin >> table[i][j];

	solve(table, n);

	for(int i = 0; i < pow(n, 2); i++){
		for(int j = 0; j < pow(n, 2); j++)
			cout << table[i][j] << " ";
		cout << endl;
	}

	

	return 0;
}
