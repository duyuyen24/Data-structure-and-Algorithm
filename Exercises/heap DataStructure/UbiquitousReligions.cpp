//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
#include <cstdio>
using namespace std;

int arr[50010];
int numR;

int find(int x){
	if (x == arr[x])
		return x;
	return find(arr[x]);
}
void uni(int x, int y){
	x = find(x);
	y = find(y);

	if (x != y) {
		arr[x] = y;
		--numR;
	}
}
int main(){
	int n, m, tc = 1;
	while (scanf("%d %d", &n, &m) && (n || m)) {
		for (int i = 1; i <= n; i++){
			arr[i] = i;
		}
		int x, y;
		numR = n;

		while (m--) {
			scanf("%d%d", &x, &y);
			uni(x, y);
		}
		printf("Case %d: %d\n", tc++, numR);
	}
	return 0;
}

