//link:https://codeforces.com/problemset/problem/557/B
#include <iostream>
#include <algorithm>
using namespace std;
int a[200000];
int n,w;
int main()
{
	scanf("%d%d", &n, &w);
	for(int i = 0; i < n*2; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a+n*2);
	double gv,bv,cv;
	gv = min(a[0]*1.0, a[n]*1.0/2);
	bv = gv*2;
	cv = (gv + bv)*n;
	cv = min(cv, w*1.0);
	printf("%.6lf\n",cv);
	return 0;
}
