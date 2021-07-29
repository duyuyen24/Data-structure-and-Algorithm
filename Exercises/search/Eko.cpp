//https://www.spoj.com/problems/EKO/
#include <stdio.h>
#include <stdlib.h>

int main () {
	int max = -1;
	int n , k;

	scanf("%d%d", &n, &k);

	int *array = (int *) malloc (n * sizeof(int));

	for (int i = 0 ; i < n ; i++) {
		scanf("%d" , &array[i]);
		if (array[i] > max)
			max = array[i];
	}

	long long int low = 0;
	long long int high = max;
	long long int count = 0 , mid;
	long long int h = 0;

	while ( low <= high ) {
		mid = (high + low)/2;
		count = 0;
		for (int i = 0 ; i < n ; i++) {
			long long int temp = array[i] - mid;
			if(temp > 0){
				count += temp;
			}else{
				count += 0;
			}
		}

		if (count == k) {
			h = mid;
			break;
		}else if ( count < k ) {
			high = mid - 1;
		}else {
			low = mid + 1;
			if (mid > h){
				h = mid;
			}
		}

	}

	printf("%lld\n" , h);

	return 0;
}
