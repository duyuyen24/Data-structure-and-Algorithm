//https://codeforces.com/problemset/problem/644/B
#include<bits/stdc++.h>
using namespace std;

queue<long long int> q;

int main(){
	long long int n, m, x, y, h;
	cin >> n >> m;
	while (n != 0){
		cin >> x >> y;
		while(q.size() && q.front() <= x){
			q.pop();
		}
		if(q.empty()){
			h = x;
		}
		if (q.size() <= m){
			h += y;
			q.push(h);
			cout << h << ' ';
		}else{
			cout << -1 << ' ';
		}
		n--;
	}
}

