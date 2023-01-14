#include <bits/stdc++.h>
using namespace std;

int divide(int N, int K){
	if(N <= K) return 1;
	return ( divide(N / 2, K) + divide(N - N / 2, K) );
}

int main(){
	int N, K;
		
	while(true){
		cin >> N >> K;
		if(N == 0) exit(0);

		cout << divide(N, K) << endl;
	}
	
	return 0;
}
