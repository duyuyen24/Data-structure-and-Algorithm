//link: https://codeforces.com/problemset/problem/439/B
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long int a[100000];

int main() {
	int n, x;
	long long int s = 0;
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	for(int i=0; i<n; i++) {
		s += a[i]*x;
		if(x > 1){
			x--;
		}
	}
	printf("%I64d", s);
	return 0;
}
