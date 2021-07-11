//link: https://codeforces.com/problemset/problem/540/C
#include<bits/stdc++.h>
using namespace std;
const int maxn = 500;
int n = 0,m = 0;
int r1 = 0,c1 = 0,r2 = 0,c2 = 0;

char mp[maxn][maxn];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool bfs(){
	queue<pair<int,int>> q;
	q.push(make_pair(r1,c1));

	while(!q.empty()){
		int topx = q.front().first;
		int topy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = topx + dx[i];
			int y = topy + dy[i];
			if(x < 0 || x >= n || y < 0 || y >= m){
				continue;
			}
			if(mp[x][y] == 'X' && (x == r2 && y == c2)){
				return true;
			}
			if(mp[x][y] == '.'){
				mp[x][y] = 'X';
				q.push(make_pair(x,y));
			}
		}
	}
	return false;
}

int main(){
	while(cin >> n >> m){
		for(int i = 0;i < n; i++){
			cin >> mp[i];
		}
		cin >> r1 >> c1;
		cin >> r2 >> c2;
		--r1,--c1,--r2,--c2;
		if(bfs()){
			cout << "YES\n";
		}else{
			cout <<  "NO\n";
		}
	}

	return 0;
}
