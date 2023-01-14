#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, pairs;
	char L;
	
	while(cin >> N){
		vector<vector<int>> helper(31, vector<int>(2, 0));

		while(N-- > 0){
			cin >> M >> L;
			helper[M - 30][L == 'D'] += 1;
		}
		
		pairs = 0;
		for(int i = 0; i <= 30; i++){
			pairs += min(helper[i][0], helper[i][1]);
		}
		
		cout << pairs << endl;
	}
	
	return 0;
}
