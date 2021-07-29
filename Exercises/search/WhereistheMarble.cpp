//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX 10005
int input[MAX], item, pos, middle;

void binarySearch(int low, int high){
	if(low <= high){
		middle = (low + high)/2;
		if(input[middle] == item)
			pos = middle;
		if(item <= input[middle]){
			binarySearch(low, middle - 1);
		}else{
			binarySearch(middle + 1, high);
		}
	}
	else{
		return;
	}
}
int main(){
	int n, q, tc = 0;
	while(cin >> n >> q && (n||q)){
		for(int i = 0; i < n; i++){
			cin >> input[i];
		}
		sort(input, input + n);
		cout << "CASE# " << ++tc << ":" << endl;

		for(int i = 0; i < q; i++){
			cin >> item;
			pos = -1;
			binarySearch(0, n-1);
			if(pos < 0){
				cout << item << " not found\n";
			}else{
				cout << item <<  " found at " << pos + 1 << endl;
			}
		}
	}
	return 0;
}
