//link: https://www.spoj.com/problems/KOZE/cstart=20
#include <bits/stdc++.h>
using namespace std;

const int N = 255;
char mt[N][N];
int vis[N][N];
int n, m, k, v;
int s = 0, w = 0;

void dfs(int x, int y){
	vis[x][y] = 1;
	if(mt[x][y] == 'k'){
		k++;
	}
	if(mt[x][y]=='v'){
		v++;
	}
	if(((x >= 0 && x < n) && (y >= 0 && y < m)) && vis[x+1][y] == 0 && mt[x+1][y] != '#'){
		dfs(x+1, y);
	}
	if(((x >= 0 && x < n) && (y >= 0 && y < m)) && vis[x-1][y] == 0 && mt[x-1][y] != '#'){
		dfs(x-1, y);
	}
	if(((x >= 0 && x < n) && (y >= 0 && y < m)) && vis[x][y+1]==0 && mt[x][y+1] != '#'){
		dfs(x, y+1);
	}
	if(((x >= 0 && x < n) && (y >= 0 && y < m)) && vis[x][y-1] == 0 && mt[x][y-1] != '#'){
		dfs(x, y-1);
	}

}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mt[i][j];
			if(mt[i][j] == 'k')
				s++;
			if(mt[i][j] == 'v')
				w++;
		}
	}
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mt[i][j] == 'k' && vis[i][j] == 0){
				k = 0;
				v = 0;
				dfs(i, j);
				if(k > v){
					w -= v;
				}else{
					s -= k;
				}
			}
		}
	}
	cout << s << " " << w << endl;
	return 0;
}
