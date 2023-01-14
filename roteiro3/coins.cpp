#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define show(a) "%d %d\n", a.first, a.second

int main(){
	int x, y, a, b;
	cin >> x >> y >> a >> b;
	
	set<pair<int, int>> possibilities;
	for(int i = a; i <= x; i++)
		for(int j = b; j < i; j++)
			possibilities.insert({i, j});

	vector<pair<int, int>> helper(all(possibilities));
	for(int i = 0; i < helper.size(); i++)
		printf(show(helper[i]));
	
	return 0;
}

