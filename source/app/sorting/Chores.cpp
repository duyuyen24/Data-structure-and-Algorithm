//link: https://codeforces.com/problemset/problem/169/A
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b;
int arr[10000];

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<n;++i)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	printf("%d\n",arr[b] - arr[b-1]);
	return 0;
}
