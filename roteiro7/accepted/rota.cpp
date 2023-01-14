#include <bits/stdc++.h>
using namespace std;

class City {
	public:
		string name;
		vector<City*> links;
		
		City(string str){
			name = str;
		}

		void addLink(City* city){
			links.push_back(city);
		}

		vector<vector<City*>> getCriticPath(City* city);
};

class Map {
	public:
		vector<City*> cityList;
	
		void addCity(City* newCity){
			cityList.push_back(newCity);
		}

		City* getCity(string name){
			for(int i = 0; i < cityList.size(); i++)
				if(cityList[i]->name == name) 
					return cityList[i];
			return new City("NULL");
		}

		City* getCapital(){
			return cityList[0];
		}
};

bool has(vector<City*> list, City* city){
	return find(list.begin(), list.end(), city) != list.end();
}

bool hasDiffPathsTo(City* origin, City* target, vector<city> visited){
	int paths = 0;
	path += has(origin->links, target);	
	path += hasDiffPathsTo(
}

vector<vector<City*>> City::getCriticPath(City* capital, vector<City*> &visited){
	visited.push_back(this);
	vector<City*> targetPoints;

	if(has(links, capital)){
		
	} else {
		bool valid = false;
		for(int i = 0; i < links.size(); i++){
			if(!has(visited, links[i]){
				valid = true;
			}
		}
	}
}

int main(){
	int N, M;
	string strHelper;

	while(true){
		cin >> N >> M;
		if(N == 0) exit(0);

		Map map;

		for(int i = 0; i < N; i++){
			cin >> strHelper;
			map.addCity(new City(strHelper));
		}

		for(int i = 0; i < M; i++){
			cin >> strHelper;
			City* origin = map.getCity(strHelper);
			
			cin >> strHelper;
			origin->addLink(map.getCity(strHelper));
		}

		
	}
	
	
	return 0;
}	
