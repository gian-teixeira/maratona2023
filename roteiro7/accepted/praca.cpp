#include <bits/stdc++.h>
using namespace std;


#define time pair<int, pair<int, pair<int, char>>>

#define hour(t) t.first
#define minute(t) t.second.first
#define sec(t) t.second.second.first
#define event(t) t.second.second.second

int main(){
    int N, counter, max;
    time helper;	
    
    while(true){
        cin >> N;
		if(N == 0) break;
        
        set<time> events;
		vector<int> ev(3, 0);
        for(int i = 0; i < N; i++){
            scanf("%d:%d:%d %c", &hour(helper), &minute(helper), 
				&sec(helper), &event(helper));

			if(event(helper) == 'E') ev[0]++;
			else if(event(helper) == 'X') ev[1]++;
			else ev[2]++;

            events.insert(helper);
        }

		int diff = ev[0] - ev[1];
		int E_extra_count = ev[1] - ev[0] + (ev[2] - ev[1] + ev[0]) / 2;

        max = 0;
        counter = 0;
        for(int i = 0; i < N; i++){
            set<time>::iterator first = events.begin();
			char ev = first->second.second.second;
			
			if(ev == 'E' or ev == 'X') 
				counter += ( ev == 'E' ? 1 : -1 );
			else if(E_extra_count <= 0) counter--;
			else {
				counter++;
				E_extra_count--;
			}
            
            events.erase(events.begin());

            if(max < counter) max = counter;
        }

        cout << max << endl;
    }
    

	return 0;
}
