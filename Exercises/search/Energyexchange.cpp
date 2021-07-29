//https://codeforces.com/problemset/problem/68/B
#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10000;
int a[MAXN];
int n, k;

bool check(double x){
	double low = 0, high = 0;
	for(int i = 0; i < n; i++){
		if (a[i] < x)
			low += x - a[i];
		else
			high += a[i] - x;
	}
	return (high - (high * k) / 100.0) >= low;
}
int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	double low = 0, high = 1000;
	for(int i = 0; i < 100; i++){
		double mid = (low + high) / 2;
		if (check(mid))
			low = mid;
		else
			high = mid;
	}
	printf( "%.9lf\n", low);
	
	return 0;
}

