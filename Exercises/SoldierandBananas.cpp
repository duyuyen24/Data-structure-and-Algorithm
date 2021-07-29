//https://codeforces.com/problemset/problem/546/A
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

long long n,k,w;

int main(){
	int i;
	long long sum = 0;
	scanf("%I64d%I64d%I64d", &k, &n, &w);
	for(i = 1; i <= w; i++)
		sum += i * k;
	if(n>=sum)
		printf("0\n");
	else
		printf("%I64d\n", sum-n);

	return 0;
}
