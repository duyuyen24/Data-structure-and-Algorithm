//link: https://codeforces.com/problemset/problem/37/A
#include <iostream>
#include <algorithm>
using namespace std;
int a[200000];
int n;
int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int  height = 1, count = 1, h = 1;
	for(int i = 1; i < n; ++i){
		if(a[i] == a[i - 1]){
			++h;
			if(h > height){
				height = h;
			}
		}else{
			h = 1;
			++count;
		}
	}
	printf("%d %d\n", height, count);
	return 0;
}
