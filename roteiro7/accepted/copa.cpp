#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, sum, intHelper;
	string strHelper;

	while(true){
		cin >> T >> N;
		if(T == 0) exit(0);

		sum = 0;
		for(int i = 0; i < T; i++){
			cin >> strHelper >> intHelper;
			sum += intHelper;	
		}
		
		cout << (3 * N - sum) << endl;
	}

	return 0;
}
