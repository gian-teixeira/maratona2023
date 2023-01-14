#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, aux, aux_s, aux_p, hr, ahr;
	bool pos_hr, pos_ahr, start;
	vector<int> station(1001), path(1001);

	while(true){
		cin >> N;
		if(N == 0) exit(0);

		for(int i = 0; i < N; i++) cin >> station[i];
		for(int i = 0; i < N; i++) cin >> path[i];
		
		hr = -2;
		ahr = -2;
		for(int i = 0; i < N; i++){
			if(hr != -2 and ahr != -2) break;

			pos_hr = true;
			pos_ahr = true;

			if(hr == -2){
				start = true;
				aux = 0;
				for(int j = i; j != i or start; j = (j + 1) % N){
					start = false;
					aux += station[j] - path[j];
					if(aux < 0){
						pos_hr = false;
						break;
					}
				}
				if(pos_hr) hr = i;
			}
			
			if(ahr == -2){
				start = true;
				aux = 0;
				for(int j = i; j != i or start; j = j > 0 ? j - 1 : N - 1){
					start = false;
					aux += station[j] - path[j > 0 ? j - 1 : N - 1];
					if(aux < 0){
						pos_ahr = false;
						break;
					}
				}
				if(pos_ahr) ahr = i;
			}
		}
		
		printf("%d %d\n", hr + 1, ahr + 1);
	}
	
	return 0;
}
