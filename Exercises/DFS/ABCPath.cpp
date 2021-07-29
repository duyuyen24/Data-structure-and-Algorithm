//https://www.spoj.com/problems/ABCPATH/
#include<bits/stdc++.h>
using namespace std;

#define N 52

int W, H;
char mt[N][N];
int visited[N][N];
int dx[8] = {1, 1, 1, 0, 0, -1, -1,-1};
int dy[8] = {1,-1, 0, 1, -1, 1, -1, 0};

int dfs(int i, int j){
	int r = 1;
	for(int k = 0; k < 8; k++){
		int x = i + dx[k];
		int y = j + dy[k];
		if( x >= 0 && x < W && y >= 0 && y < H && mt[i][j]+1 == mt[x][y] && visited[x][y] == 0){
			visited[x][y] = 1;
			r = max(r, dfs(x, y) + 1);
		}
	}
	return r;
}

int main(){
	int tc = 1;
	while(true){
		cin >> W >> H;
		if(W == 0 && H == 0){
			break;
		}

		for(int i = 0; i < W; i++)
			for(int j = 0; j < H; j++)
				cin >> mt[i][j];

		memset(visited,0,sizeof(visited));
		int mx =0 ;
		for(int i = 0; i < W; i++){
			for(int j = 0; j < H; j++){
				if(mt[i][j] == 'A'){
					visited[i][j] = 1;
					mx = max(mx, dfs(i, j));
				}
			}
		}
		cout << "Case " << tc << ": " << mx << endl;
		tc++;
	}
}
