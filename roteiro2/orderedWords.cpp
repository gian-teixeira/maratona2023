#include <iostream>
#include <set>
using namespace std;

#define all(a) a.begin(), a.end()

int main(){
    int N;
    cin >> N;
    while(N-- > 0){
        string original;
        cin >> original;

        string lowerCase(original);
        for(int i = 0; i < original.size(); i++)
            lowerCase[i] = tolower(original[i]);
        
        set<char> tmpSet(all(lowerCase));
        string ordered(all(tmpSet));



        cout << original << (lowerCase == ordered ? ": O" : ": N") << endl;
    }
    return 0;
}