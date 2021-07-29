//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3252
#include <bits/stdc++.h>

using namespace std;

bool cmp(int i, int j){
	return i > j;
}

int main() {
	int t, n, m, num;
	
	cin >> t;
	
	while (t--){
		cin >> n >> m;
		
		vector<int> v;
		queue<pair<int,int>> q;
		
		for (int i = 0; i < n; i++){
			cin >> num;
			q.push(pair<int,int>(num, i));
			v.push_back(num);
		}
		
		sort(v.begin(),v.end(),cmp);
		
		int i = 0;
		int ans = 0;
		
		while (!q.empty()){
			int u = q.front().first;
			int w = q.front().second;
			q.pop();
			
			if (u  ==  v[i]){
				ans++;
				if (w == m) break;
				i++;
			}else{
				q.push(pair<int,int>(u, w));
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

