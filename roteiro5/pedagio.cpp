#include <bits/stdc++.h>
using namespace std;

bool has(const vector<City*> &V, City* city){
	return find(V.begin(), V.end(), city) != V.end();
}

class City {
	public:
		vector<City*> links;
		
		void connect(City* city){
			links.push_back(city);
			city->links.push_back(this);
		}
};

class Country {
	public:
		vector<City*> cities;

		Country(int n){
			cities = vector<City*>(n + 1);
		}

		void connect(int origin, int end){
			cities[origin]->connect(cities[end]);
		}

		vector<City*> walk(int start, int limit, vector<City*> &visited){
			vector<City*> bestWay;			

			City* at = cities[start];
			for(int i = 0; i < at->links.size(); i++){
				visited.push_back(at->links[i]);
				vector<City*> currentWay;
				currentWay.push_back(at);
				
				if(!has(visited, at->links[i])){
					vector<City*> cont = walk(i, limit - 1, visited);
				}
			}

		}
};

vector<int> solve(const vector<vector<bool>> &H, vector<int> &visited, int start){
	visited.push_back(start);
	
}

int main(){
	int C, E, L, P,
		teste = 0,
		origin, end;

	while(true){
		cin >> C >> E >> L >> P;
		if(C == 0) break;

		vector<vector<bool>> helper(C + 1, vector<int>(C + 1));
		for(int i = 0; i < E; i++){
			cin >> origin >> end;
			helper[origin][end] = 1;
			helper[end][origin] = 1;
		}

		
		

		printf("Teste %d\n", ++teste);

	}
 
	return 0;
}
