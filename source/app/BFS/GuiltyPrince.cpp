//link of problem: https://lightoj.com/problem/guilty-prince
#include<bits/stdc++.h>
using namespace std;

int col, row;
char A[25][25];
int vis[25][25];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int BFS(int sx, int sy){
	int ans = 1;
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	vis[sx][sy] = 1;

	while(!q.empty()){
		int topx = q.front().first;
		int topy = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++){
			int x = topx + dx[i];
			int y = topy + dy[i];
			if(x >= 0 && x < col && y >= 0 && y < row && vis[x][y] != 1 && A[x][y] != '#'){
				vis[x][y] = 1;
				ans++;
				q.push(make_pair(x,y));
			}
		}
	}
	return ans;
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		memset(vis, 0, sizeof(vis));
		int sx, sy;
		cin >> row >> col;
		for(int i = 0; i < col; i++){
			for(int j = 0; j < row; j++){
				cin >> A[i][j];
				if(A[i][j]=='@'){
					sx = i;
					sy = j;
				}
			}
		}
		cout<< "Case " << t <<": "<< BFS(sx, sy) << endl;
	}

	return 0;
}
