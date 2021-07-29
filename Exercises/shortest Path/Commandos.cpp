//https://vjudge.net/problem/LightOJ-1174
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const int INF = 9999999;
int dis[MAXN][MAXN];
int t, n, r, x, y, s, d;

void floyd(){
	for(int k = 0; k < n ; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	cin >> t;
	for(int i = 1;i <= t;i++){
		cin >> n;
		cin >> r;
		for(int i = 0; i < MAXN; i++){
			dis[i][i] = 0;
			for(int j = i+1; j < MAXN; j++)
				dis[i][j] = dis[j][i] = INF;
		}

		while(r--){
			cin >> x >> y;
			dis[x][y] = dis[y][x] = 1;
		}

		cin >> s >> d;
		floyd();

		int ans = 0;

		for(int j = 0; j < n; j++){
			if(dis[s][j] == INF || dis[j][d] == INF){
				continue;
			}
			ans = max(ans, dis[s][j] + dis[j][d]);
		}
		cout << "Case " << i << ": " << ans << endl;
	}
	return 0;
}
