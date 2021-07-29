//link :https://www.spoj.com/problems/UCV2013H/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000;

int m, n, k = 1;
int mt[N][N];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int num[1000000];

void bfs(int x,int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(mt[nx][ny] == 1){
			k++;
			mt[nx][ny] = 0;
			bfs(nx,ny);
		}
	}
}

int main(){
	while(cin >> n >> m){
		memset(mt,0,sizeof(mt));
		memset(num,0,sizeof(num));
		if(n == 0 && m == 0){
			break;
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> mt[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(mt[i][j] == 1){
					mt[i][j] = 0;
					bfs(i,j);
					num[k]++;
					ans++;
					k = 1;
				}
			}
		}

		cout << ans << endl;
		for(int i = 0; i < 1000000; i++){
			if(num[i] != 0){
				cout << i << " " << num[i] <<endl;
			}
		}
	}
}
