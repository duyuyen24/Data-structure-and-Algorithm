//https://www.spoj.com/problems/HACKRNDM/en/
#include <bits/stdc++.h>
using namespace std;

vector<int> input;
int res = 0;

void BinarySearch(int low, int high, int k, int i){
	while (low <= high){
		int mid = (low + high)/2;
		if(input[mid] == input[i] + k){
			res++;
			break;
		}else if(input[mid] > k + input[i]){
			high = mid - 1;
		}else{
			low = mid + 1;
		}
	}
}

int main(){
	int  n, k;
	input.clear();
	cin >> n >> k;
	input.resize(n);
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}
	sort(input.begin(), input.end());
	
	for(int i = 0; i < n; i++){
		int low = 0, high = n- 1;
		BinarySearch(low, high, k, i);
	}
	
	cout << res << endl;

	return 0;
}
