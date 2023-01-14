#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> Quadradonia(N);
	vector<int> Nlogonia(N);

	for(int i = 0; i < N; i++) cin >> Quadradonia[i];
	for(int i = 0; i < N; i++) cin >> Nlogonia[i];

	sort(Quadradonia.begin(), Quadradonia.end());
	sort(Nlogonia.begin(), Nlogonia.end());
	
	int qSoldier = 0;
	for(int i = 0; i < N; i++)
		if(Nlogonia[i] > Quadradonia[qSoldier]) 
			qSoldier++;

	cout << qSoldier << endl;

	return 0;
}
