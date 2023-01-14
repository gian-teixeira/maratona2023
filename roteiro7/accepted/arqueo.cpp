#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, birth, death;
	cin >> N;
	
	while(N-- > 0){
		cin >> birth >> death;
		birth += birth < 0 and death > 0;
		cout << death - birth << endl;
	}

	return 0;
}
