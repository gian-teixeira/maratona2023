#include <bits/stdc++.h>
using namespace std;

class BigInt {
	public:
		string value;

		BigInt() {
			value = "";
		}

		BigInt sum(BigInt n){
			BigInt m;
			int carry = 0;
			for(int i = 0; i < max(value.size(), n.value.size()); i++){
				if(value.size() <= i) value.push_back('0');
				if(n.value.size() <= i) n.value.push_back('0');

				int d = (int)(value[i]- '0' + n.value[i] - '0') + carry;
				carry = d > 9;
				
				m.value.push_back((char)(d - (carry ? 10 : 0) + '0'));
			}
			if(carry) m.value.push_back('1');
			return m;
		}

		string readable(){
			string helper = value;
			reverse(helper.begin(), helper.end());
			return helper;
		}
};

BigInt fbnc(vector<BigInt> &helper, int n){
	if(helper[n].value == "")
		helper[n].value = fbnc(helper, n-2).sum(fbnc(helper, n-1)).value;
	return helper[n];
}

int main(){
	vector<BigInt> helper(5001);
	(helper[0]).value = "0";
	(helper[1]).value = "1";

	int N;
	while(cin >> N){
		printf("The Fibonacci number for %d is ", N);
		cout << fbnc(helper, N).readable() << endl;
	}

	return 0;
}
