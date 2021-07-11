//link :https://www.hackerrank.com/challenges/count-luck
#include <bits/stdc++.h>
#include <string>

using namespace std;

char mt[100][100];
bool v[100][100];
int k;
int n,m;

void dfs(int i, int j, int p){
	if(mt[i][j] == '*'){
		if(p == k){
			cout<<"Impressed"<<'\n';
		}else{
			cout<<"Oops!"<<'\n';
		}
	}

	v[i][j] = p;
	mt[i][j] = 'X';
	if(mt[i][j-1] != 'X' && mt[i+1][j] != 'X'){
		p++;
	}else if(mt[i][j-1] != 'X' && mt[i-1][j] != 'X'){
		p++;
	}else if(mt[i][j-1] != 'X' && mt[i][j+1] != 'X'){
		p++;
	}else if(mt[i+1][j] != 'X' && mt[i][j+1] != 'X'){
		p++;
	}else if(mt[i+1][j] != 'X' && mt[i-1][j] != 'X'){
		p++;
	}else if(mt[i][j+1] != 'X' && mt[i-1][j] != 'X'){
		p++;
	}
	if(mt[i+1][j] != 'X'){
		dfs(i+1, j, p) ;
	}
	if(mt[i-1][j] != 'X'){
		dfs(i-1, j, p) ;
	}
	if(mt[i][j+1] != 'X'){
		dfs(i, j+1, p) ;
	}
	if(mt[i][j-1] != 'X'){
		dfs(i, j-1, p) ;
	}

}
int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;

		memset(mt,'X',sizeof(mt));
		memset(v,false,sizeof(v));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				cin >> mt[i][j];
			}
		}

		cin >> k;

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(mt[i][j] == 'M'){
					dfs(i,j,0);
					break;
				}
			}
		}
	}

	return 0;
}
