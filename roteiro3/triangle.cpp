#include <bits/stdc++.h>
using namespace std;

#define sum(a) a[0] + a[1] + a[2]

int main(){
	int X[3], Y[3];
	cin >> X[0] >> Y[0] >> X[1] >> Y[1] >> X[2] >> Y[2];
	
	int eX[3] = {X[0] == X[1], X[0] == X[2], X[1] == X[2]},
	    eY[3] = {Y[0] == Y[1], Y[0] == Y[2], Y[1] == Y[2]};
	   
	int equalitySum = sum(eX) + sum(eY);
	if(equalitySum == 2){
		cout << "RIGHT" << endl;
		return 0;
	}
	else if (abs(2 - equalitySum) <= 1)
		for(int i = 0; i < 3; i++){
			bool can = false;
			
			int move[] = {X[i] + 1, X[i] - 1, Y[i] + 1, Y[i] - 1};
			for(int m = 0; m < 4; m++)
				if( find(X, X + 3, move[m]) != X + 3 ){
					can = true;
					break;
				}
					
			if(can){
				cout << "ALMOST" << endl;
				return 0;
			}
		}
	cout << "NEITHER" << endl;

	return 0;
}
