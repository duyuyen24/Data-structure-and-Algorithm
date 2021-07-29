//https://www.codechef.com/problems/MAXCOMP
#include<stdio.h>
#include<stdlib.h>
#define LIMIT 2000

int result[LIMIT+1], P[LIMIT+1], n;

typedef struct{
	int start_time, stop_time, compensation;
} offer;

offer offers[LIMIT+1];

int solve(){
	result[0] = offers[0].compensation;
	int result_previous;
	for(int i = 1; i < n; i++){
		if(P[i] == -1){
			result_previous = 0;
		}else{
			result_previous = result[P[i]];
		}
		if(offers[i].compensation + result_previous > result[i - 1]){
			result[i] = offers[i].compensation + result_previous;
		}else{
			result[i] = result[i - 1];
		}
	}
	return result[n-1];
}
int compare(const void * a, const void * b) {
	return ((offer*)a)->stop_time > ((offer*)b)->stop_time;
}

int main(){
	int tc, flag;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			scanf("%d%d%d", &offers[i].start_time, &offers[i].stop_time, &offers[i].compensation);

		}
		qsort(offers, n, sizeof(offer), compare);
		for(int i = 1; i < n; i++){
			P[i] = 0;
			flag = 0;
			for(int j = i - 1; j >= 0; j--){
				if(offers[j].stop_time <= offers[i].start_time){
					P[i] = j;
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				P[i] = -1;
		}
		int final_result = solve();
		printf("%d\n",final_result);
	}
	return 0;
}
