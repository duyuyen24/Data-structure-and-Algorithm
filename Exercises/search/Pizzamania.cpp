//https://www.spoj.com/problems/OPCPIZZA/en/
#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int pairBS(int a[], int length, int sum){
	int res = 0;
	if(length < 1)
		return res;
	
	int high = length - 1;
	int low = 0;
	
	while(low < high){
		int curSum = a[high] + a[low];
		
		if(curSum == sum){
			res++;
			low++;
			high--;
		}else if(curSum > sum){
			high --;
		}else{
			low ++;
		}
	}
	
	return res;
}
int main(){
	int tc, m, n;
	cin >> tc;
	while(tc--){
		cin >> n >> m;
		int arr[n];
		
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cout << pairBS(arr, n, m) << endl;
	}
}
