#include <bits/stdc++.h>
using namespace std; 

#define upTo(a, c) a.begin(), a.begin() + c

int main(){
    int n;
    vector<int> cards(8);
    while(true){
        cin >> n;
        if(n == 0) break;

        for(int i = 0; i < n; i++)
            cin >> cards[i];
        sort(upTo(cards, n));

        do{
            for(int i = 0; i < n; i++)
                cout << cards[i] << " ";
            cout << endl;
        }while(next_permutation(upTo(cards, n)));
        
        cout << endl;
    }
    return 0;
}