#include<bits/stdc++.h>
using namespace std;

char A[25][25];
int vis[25][25];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int sx, sy, ex, ey;
int m, n;

int bfs(int sx, int sy){
	if (vis[sx][sy]){
		return 0;
	}
	queue<pair<int,int>> q;
	q.push(make_pair(sx,sy));
	vis[sx][sy] = 1;
	int ans = 0;

	while(!q.empty()){
		int topx = q.front().first;
		int topy = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			int x = topx + dx[i];
			int y = topy + dy[i];
			if(x >= 0 && x < m && y >= 0 && y < n && vis[x][y] != 1 && A[x][y] != '#'){
				vis[x][y] = 1;
				if (x == ex && y == ey){
					ans = 1;
				}
				q.push(make_pair(x,y));
			}
		}
	}
	return ans;
}

int check(int cnt){
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if ((i == 0 || i == m-1 || j == 0 || j == n-1) && A[i][j] == '.'){
				if (cnt == 0){
					sx = i;
					sy = j;
				}
				else if (cnt == 1){
					ex = i;
					ey = j;
				}
				cnt++;
			}
		}
	}
	if (cnt == 2){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(vis, 0, sizeof(vis));
		cin >> m >> n;
		for(int i = 0; i < m; i++){
			cin >> A[i];
		}

		if (m == 1 && n == 1){
			printf("invalid\n");
			continue;
		}

		int cnt = 0;
		if (check(cnt) && bfs(sx, sy)){
			printf("valid\n");
		}else{
			printf("invalid\n");
		}
	}

	return 0;
}
