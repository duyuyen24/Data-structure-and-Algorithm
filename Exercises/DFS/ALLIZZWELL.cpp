//https://www.spoj.com/problems/ALLIZWEL/
#include<iostream>
using namespace std;

const int MAX = 105;
const char arr[] = "ALLIZZWELL";

int  R, C;
int  ans;
char mt[MAX][MAX];
bool vis[MAX][MAX];

int dr[8] = {-1,-1,0,1,1,1,0,-1};
int dc[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int row, int col, int current){
	if(current == 9){
		ans = 1;
		return;
	}

	for(int i = 0; i < 8; i++){
		int r = row + dr[i];
		int c = col + dc[i];

		if (r >= 0 && r < R && c >= 0 && c < C && !vis[r][c] && mt[r][c] == arr[current + 1]){
			vis[r][c] = true;
			dfs(r, c, current + 1);
			vis[r][c] = false;
		}
	}
}

int main(){
	int T;
	cin >> T;

	for(int tc = 0; tc < T; tc++){
		ans = 0;

		cin >> R >> C;
		for(int i = 0; i < R; i++)
			cin >> mt[i];

		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				vis[i][j] = false;
			}
		}
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(mt[i][j] == 'A'){
					vis[i][j] = true;
					dfs(i, j, 0);
					if(ans){
						break;
					}
				}
			}
		}
		cout << endl;
		if(ans){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}
