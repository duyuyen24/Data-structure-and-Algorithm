//https://codeforces.com/problemset/problem/296/D
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

const int N = 505;
int a[N][N];
int b[N];
long long sum[N];

int main(){
	int n;
	while(cin >> n){
		memset(sum, 0, sizeof(sum));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1; i <= n;i++)
			cin >> b[i];
		for(int k = n; k >= 1; k--){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					a[i][j] = min(a[i][j], a[i][b[k]] + a[b[k]][j]);
				}
			}
			for(int i = k; i <= n; i++){
				for(int j = k ; j <= n; j++){
					sum[k] += (a[b[i]][b[j]]);
				}
			}

		}
		for(int i = 1; i <= n; i++)
			cout << sum[i] << " ";
		cout<<endl;
	}
	return 0;
}
