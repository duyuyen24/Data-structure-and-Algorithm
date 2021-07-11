//link: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
#include <bits/stdc++.h>

using namespace std;

int mt[100][100];
int vis[100][100];
int n, m, t;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int i, int j){
	t++;
	vis[i][j] = 1;
	for(int k = 0; k < 8; k++){
		int x = i + dx[k];
		int y = j + dy[k];

		if((x >= 0 && x < n && y >= 0 &&  y < m) && vis[x][y] == 0 && mt[x][y] == 1){
			dfs(x, y);
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mt[i][j];
		}
	}

	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vis[i][j] == 0 && mt[i][j] == 1){
				t = 0;
				dfs(i, j);

				if(t > ans){
					ans = t;
				}
			}
		}
	}

	cout << ans;

	return 0;
}
