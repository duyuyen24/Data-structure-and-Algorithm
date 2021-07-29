//https://codeforces.com/problemset/problem/471/B
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt = 0;
	pair <int,int> a[2000];
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + n + 1);

	for(int i = 1; i < n; i++){
		if (a[i].first == a[i+1].first){
			cnt++;
		}
	}
	if(cnt <= 1){
		cout << "NO" << endl;
	}else{
		cout<<"YES"<<endl;
		for (int i = 1; i <= n; i++){
			cout << a[i].second << ' ';
		}
		cout << endl;
		int temp = 0;
		for(int i = 1; i <= n; i++){
			if(temp < 2){
				if (a[i].first == a[i+1].first){
					swap(a[i], a[i+1]);
					for (int j = 1; j <= n; j++){
						cout << a[j].second << ' ';
					}
					cout << endl;
					temp++;
				}
			}
		}
	}
	return 0;
}
