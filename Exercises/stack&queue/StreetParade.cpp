//https://www.spoj.com/problems/STPAR/en/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
	while(cin>>n, n){
		ll a[n];
		ll count = 1;
		bool ans = true;
		stack<ll> s;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		for(ll i = 0; i < n; i++){
			if(a[i] == count){
				count++;
			}else{
				if(s.empty()){
					s.push(a[i]);
				}else{
					if(s.top() < a[i] && s.top() != count){
						ans = false;
						break;
					}else if(s.top() == count){
						while( !s.empty() && s.top() == count){
							s.pop();
							++count;
						}
						if(s.empty()){
							s.push(a[i]);
						}else{
							if(s.top() < a[i]){
								ans = false;
								break;
							}else{
								s.push(a[i]);
							}
						}
					}else if(s.top() > a[i]){
						s.push(a[i]);
					}
				}
			}
		}

		if(ans){
			cout<<"yes\n";
		}else{
			cout<<"no\n";
		}
	}
	return 0;
}
