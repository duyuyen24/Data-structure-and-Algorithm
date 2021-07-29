//https://codeforces.com/problemset/problem/892/B
#include<iostream>
#define maxn 1000010
using namespace std;

int main(){
	int n;
	int a[maxn];
	scanf("%d",&n);
	for(int i = 1; i <= n; i++){
		scanf("%I64d",&a[i]);
	}
	int ans = 0;
	int j = n+1;
	for(int i = n;i >= 1; i--){
		if(i < j){
			ans++;
		}
		int x = i - a[i];
		if(x <= 0){
			x = 1;
		}
		if(j > x){
			j = x;
		}
	}
	printf("%d\n",ans);
	return 0;
}	
