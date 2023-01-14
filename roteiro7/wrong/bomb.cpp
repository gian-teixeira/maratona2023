#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, M, c, d, counter;
	int x[100000], y[100000];

	while(true){
		cin >> N >> M;
		if(N == 0) exit(0);

		for(int i = 0; i < N; i++)
			cin >> x[i] >> y[i];
	
		for(int b = 0; b < M; b++){
			cin >> c >> d;
			counter = 0;
			for(int i = 0; i < N; i++){
				if(x[i] == d or y[i] == d){
					counter++;
					x[i] = 0;
					y[i] = 0;
				}
			}
			cout << counter << endl;
		}
		
		cout << endl;
	}	

	return 0;
}
