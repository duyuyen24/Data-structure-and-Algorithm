//https://www.hackerrank.com/contests/interfacecse-codedash/challenges/closest-numbers
#include <iostream>
#include<algorithm>
#include<cmath>
#include<cstdint>
using namespace std;
int min(int values[], int size) {
	int diff = values[1] - values[0];
	
	for (int i = 1; i < size - 1; ++i) {
		if (values[i + 1] < values[i] + diff) {
			diff = values[i + 1] - values[i];
		}
	}
	return diff;
}

void showpairs(int values[], int diff, int size) {
	int first = 1;
	
	for (int i = 0; i < size - 1; ++i) {
		if (values[i] + diff == values[i + 1]) {
			if (first) {
				first = 0;
				printf("%d %d", values[i], values[i + 1]);
			} else {
				printf(" %d %d", values[i], values[i + 1] );
			}
		}
	}
}

int main() {
	int n, *a, d;
	scanf("%d", &n);
	a = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	
	sort(a, a + n);
	d = min(a, n);
	showpairs(a, d, n);
	
	free(a);
	return 0;
}

