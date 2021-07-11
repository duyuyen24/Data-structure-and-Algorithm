//link:https://codeforces.com/problemset/problem/149/A
#include <iostream>
#include <algorithm>
using namespace std;
int arr[13];
int k;
int main(){
	scanf("%d", &k);
	for(int i = 0; i < 12; i++) {
		scanf("%d", &arr[i]);
	}
	int sum = 0, count = 0;
	sort(arr, arr + 12,greater<int>());
	if(k == 0){
		printf("0\n");
	}else{
		for(int i = 0; i < 12; i++){
			sum += arr[i];
			count++;
			if(sum >= k){
				break;
			}
		}

		if(sum < k){
			printf("-1\n");
		}else{
			printf("%d\n",count);
		}
	}
	return 0;
}
