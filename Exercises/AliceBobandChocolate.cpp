//https://codeforces.com/problemset/problem/6/C
#include<iostream>
using namespace std;
int main()
{
	int n, a[100000], l, m;

	int sum = 0, sum1 = 0;
	scanf("%d",&n);
	l = 0;
	m = n-1;
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	while(l <= m){
		if(sum <= sum1){
			sum += a[l++];
		}else{
			sum1 += a[m--];
		}

	}
	printf("%d %d\n",l,n-l);
	return 0;
}

