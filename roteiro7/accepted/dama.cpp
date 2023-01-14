#include <bits/stdc++.h>
using namespace std;

int main(){
	int X1, Y1, X2, Y2;

	while(true){
		cin >> X1 >> Y1 >> X2 >> Y2;
		if(X1 == 0) exit(0);
		
		cout << ((int)(X1 != X2 and Y1 != Y2) + (int)(abs(X2 - X1) != abs(Y2 - Y1))) << endl;
	}

	return 0;
}
