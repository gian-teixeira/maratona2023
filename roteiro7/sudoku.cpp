#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<vector<int>> &table, int n, int x, int y){
	if(table[y][x] != 0) return false;
			
	int x0 = ( x / dimension ) * dimension,
		y0 = ( y / dimension ) * dimension;
	for(int i = 0; i < size; i++)
		if(table[y][i] == n or table[i][x] == n or table[y0 + i / dimension][x0 + i % dimension] == n) 
		return false;

	return true;
}

class Sudoku {
	public:
		int dimension;
		int size;
		vector<vector<int>> table;

		Sudoku(int n){
			dimension = n;
			size = pow(n, 2);
			table.assign(size, vector<int>(size));
		}

		void print(){
			for(int i = 0; i < size; i++){
				for(int j = 0; j < size; j++)
					cout << table[i][j] << " ";
				cout << endl;
			}
			cout << endl;
		}

		void read(){
			for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				cin >> table[i][j];
		}
		
		bool solved(){
			for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				if(table[i][j] == 0) return false;
			return true;
		}

		bool acceptNumberIn(int n, int x, int y){
			if(table[y][x] != 0) return false;
			
			int x0 = ( x / dimension ) * dimension,
				y0 = ( y / dimension ) * dimension;
			for(int i = 0; i < size; i++)
				if(table[y][i] == n or table[i][x] == n or table[y0 + i / dimension][x0 + i % dimension] == n) 
				return false;

			return true;
		}

		vector<Sudoku*> getNextStates(int x, int y){
			vector<Sudoku*> states;
			
			if(table[y][x] != 0) {
				states.push_back(new Sudoku(dimension));
				states[states.size() - 1]->table = table;
			}
			else {
				for(int n = 1; n <= 9; n++)
				if(acceptNumberIn(n, x, y)){
					states.push_back(new Sudoku(dimension));
					states[states.size() - 1]->table = table;
					states[states.size() - 1]->table[y][x] = n;
				} 
			}

			return states;
		}

		void getSolutions(int x, int y){
			if(solved()) print();
			else {
				vector<Sudoku*> nextStates = getNextStates(x, y);
				if(nextStates.size() == 0) cout << "acabou" << endl;
				else for(int i = 0; i < nextStates.size(); i++){
					nextStates[i]->getSolutions((x + 1) % size, y + (x == 0));
				}
			}
		}
};

int main(){
	int N;

	while(cin >> N){
		vector<vector<int>> table(N, vector<int>(N));

		for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> table[i][j];

		for(int y = 0; y < N; y++)
		for(int x = 0; x < N; x++)
			if(table[y][x] != 0){
				vector<vector<vector<int>>> states;
				for(int n = 1; n <= 9; n++){
				if(possible(table, n, x, y){
						
					}
				}
			}
			

	}

	return 0;
}
