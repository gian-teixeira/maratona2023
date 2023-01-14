#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<vector<int>> &table, int n, int x, int y, int element){
	for(int i = 0; i < 9; i++)
		if( table[i][x] == n or table[y][i] == element )
			return false;

	int y0 = y / 3 * n,
		x0 = x / 3 * n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if( table[i + y0][j + x0] == element )
				return false;

	return true;
}

class Board {
	public:
		vector<vector<int>> table;
		int size;
		
		Board(int n){
			size = pow(n, 2);
			table = vector<vector<int>>(size, vector<int>(size));
		}

		vector<Board*> getNextBoards(){
			int p = 0;
			vector<Board*> nextBoards;

			for(int i = 0; i < size; i++)
				for(int j = 0; j < size; j++)
					if( table[i][j] == 0 ){
						for(int e = 1; e <= 9; e++){
							if( possible(table, sqrt(size), j, i, e) ){
								nextBoards.push_back(new Board(sqrt(size)));
								*(nextBoards[p]) = *this;
								nextBoards[p]->table[i][j] = e;
								
								
								for(int i = 0; i < nextBoards[p]->size; i++){
									for(int j = 0; j < nextBoards[p]->size; j++)
										cout << nextBoards[p]->table[i][j] << " ";
									cout << endl;
								}
								cout << endl;
							}
						}

						return nextBoards;
					}
			return nextBoards;
		}
};

bool solved(Board* board);
bool searchSolution(vector<Board*> &boards);
void print(Board* board);
bool solve(Board* board);

int main(){
	int n;
	cin >> n;

	int size = pow(n, 2);
	Board board(n);

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			cin >> board.table[i][j];

	solve(&board);

	return 0;
}	

bool solved(Board* board){
	for(int i = 0; i < board->size; i++)
		for(int j = 0; j < board->size; j++)
			if( board->table[i][j] == 0 ) return false;
	return true;
}

bool searchSolution(vector<Board*> &boards){
	if(boards.size() < 1) return false;
	for(int i = 0; i < boards.size(); i++){
		solve(boards[i]);
	}
}

void print(Board* board){
	for(int i = 0; i < board->size; i++){
		for(int j = 0; j < board->size; j++)
			cout << board->table[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

bool solve(Board* board){
	if( solved(board) ){
		cout << "correct" << endl;
		print(board);
		return true;
	}
	else {
		vector<Board*> nextBoards = board->getNextBoards();
		return searchSolution(nextBoards);
	}
}
