#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> cows(N);
    for(int i = 0; i < N; i++)
        cin >> cows[i];
    sort(cows.begin(), cows.end());
    cout << cows[cows.size()/2] << endl;
    return 0;
}