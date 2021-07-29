//https://codeforces.com/problemset/problem/723/D

#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=60;
char a[maxn][maxn];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

bool vis[maxn][maxn];
int m,n,k,sum,term,len;

struct node{
	int x;
	int y;
	int num;
}num[maxn*maxn];

bool cmp(node a,node b){
	return a.num<b.num;
}

void dfs(int x,int y){
	term++;
	vis[y][x] = 1;
	for(int i = 0; i < 4; i++){
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if(dx >= 0 && dx < m && dy >= 0 && dy < n && !vis[dy][dx] && a[dy][dx] == '.'){
			dfs(dx,dy);
		}
	}
}
void dfs_ocean(int x, int y){
	vis[y][x] = 1;
	for(int i = 0; i < 4;i++){
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if(x >= 0 && dx < m && dy >= 0 && dy < n && !vis[dy][dx] && a[dy][dx] == '.'){
			dfs_ocean(dx,dy);
		}
	}
}

void dfs_change(int x, int y){
	vis[y][x] = 1;
	a[y][x] = '*';
	for(int i = 0;i < 4; i++){
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if(dx >= 0 && dx < m && dy >= 0 && dy < n && a[dy][dx] == '.'){
			dfs_change(dx,dy);
		}
	}
}

int main(){
	len = 0;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && a[i][j] == '.' && !vis[i][j]){
				dfs_ocean(j,i);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '.' && !vis[i][j]){
				dfs(j,i);
				num[len].x = j;
				num[len].y = i;
				num[len++].num = term;
				term = 0;
			}
		}
	}
	sort(num, num + len, cmp);
	int ans = 0;
	for(int i = 0; i < len - k; i++){
		dfs_change(num[i].x, num[i].y);
		ans += num[i].num;
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << endl;
	return 0;
}
