#include <bits/stdc++.h>
using namespace std;

int main(){
	string strand;
	int counter;

	while( cin >> strand ){
		counter = 0;
		for(int d = 1; d < strand.size(); d += 2)
			for(int i = 0; i < strand.size() - d + 1; i++)
			if(strand[i] + strand[i + d] == 149 or strand[i] + strand[i + d] == 137){
				strand[i + d] = '-';
				counter++;
			}
		cout << counter << endl;
	}

	return 0;
}
