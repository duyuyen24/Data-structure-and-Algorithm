//https://www.codechef.com/problems/FSQRT
#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, a;
		cin >> n;
		for(int i = 0; i*i <= n; i++){
			a = i;
		}
		cout << a << endl;
	}
	return 0;
}
