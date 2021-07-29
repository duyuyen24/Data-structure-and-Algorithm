//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1594
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
bool vis[maxn][maxn];

int dx[]={0,0,-1,+1};
int dy[]={+1,-1,0,0};
int row, col;
int dist[maxn][maxn];

void bfs(int x,int y){
	queue<pair<int,int>> q;
	q.push({x,y});
	vis[x][y] = 1;

	while(!q.empty()){
		auto u = q.front();
		q.pop();
		for(int k = 0; k < 4; k++){
			int nx = u.first + dx[k];
			int ny = u.second + dy[k];
			if(nx >= 0 && nx < row && ny >= 0 && ny < col && vis[nx][ny] != 1){
				q.push({nx,ny});
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[u.first][u.second] + 1;
			}
		}
	}
}

int main(){
	int bombInRow, rowNum, bomb, colNum;
	while(cin >> row >> col){
		if(row == 0 && col == 0) break;
		cin >> bombInRow;

		memset(dist, 0, sizeof(dist));
		memset(vis, 0, sizeof(vis));

		for(int i = 0; i < bombInRow; i++){
			cin >> rowNum >> bomb;
			for(int j = 0; j < bomb; j++){
				cin >> colNum;
				vis[rowNum][colNum] = 1;
			}
		}

		int startRow, startcol, endRow, endCol;
		cin >> startRow >> startcol >> endRow >> endCol;
		bfs(startRow, startcol);
		cout << dist[endRow][endCol] << endl;
	}
	return 0;
}
