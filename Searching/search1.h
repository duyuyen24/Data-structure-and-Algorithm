#ifndef SEARCH_H
#define SEARCH_H
#include <stdio.h>
#include<vector>
using namespace std;

int linearS(vector<int> &a, int n, int index){
	for(int i = 0; i < n; i++){
		if(a.at(i) == index){
			printf("i = %d, index = %d\n", i, index);
			return 1;
		}
	}
	return -1;
}

int binaryS(vector<int> &a,int low, int high, int index){
	if (high >= low) {
		int mid = high + (high - low) / 2;

		if (a.at(mid) == index){
			return mid;
		}

		if (a.at(mid) > index){
			return binaryS(a, low, mid - 1, index);
		}
		return binaryS(a, mid + 1, high, index);
	}
	return -1;
}

#endif // SEARCH_H
