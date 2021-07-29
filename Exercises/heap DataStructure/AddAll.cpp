//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main(){
	int n;
	long long t;

	while(cin >> n && n){
		while(!q.empty()) q.pop();
		for(int i = 0; i < n; i++){
			cin >> t;
			q.push(t);
		}
		long long sum = 0, ans = 0, a, b;
		while(!q.empty()){
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			sum = a + b;
			ans += sum;
			q.push(sum);
		}
		cout << ans << endl;
	}
	return 0;
}
