//https://codeforces.com/problemset/problem/673/A
#include <cstdio>
#include <iostream>
#include <string>
int n, a[1001];
int min(int a,int b){
	return a < b ? a : b;
}

int main(){
    int n,x,last=0,ans=15;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (last+15>=x){
		 ans=x+15;
        }else{
		 break;
		}
        last = x;
    }
    printf("%d\n", min(ans,90));
    return 0;
}
