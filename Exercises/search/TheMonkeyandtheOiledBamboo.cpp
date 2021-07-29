//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183
#include <bits/stdc++.h>

using namespace std;
vector<int> input;
vector<int> sub;
int n;

bool check(vector<int> input, int jump){
	for (int i = 0; i < input.size(); i++){
		if (input[i] > jump)
			return false;
		if (input[i] == jump)
			jump--;
	}
	return true;
}
int BinarySearch(int low, int high){
	int res;
	while (low <= high){
		int mid = (low + high) / 2;
		if(check(sub, mid)){
			res = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return res;
}

int main(){
	int tc, n;
	cin >> tc;
	for (int k = 0; k < tc; k++){
		cout << "Case " << k + 1 << ": ";
		input.clear(), sub.clear();
		cin >> n;
		input.resize(n);
		for (int i = 0; i < n; i++){
			cin >> input[i];
		}
		sub.resize(n);
		sub[0] = input[0];
		for (int i = 1; i < n; i++)
			sub[i] = input[i] - input[i - 1];

		int low = 0, high = input[n - 1];
		int res = BinarySearch(low, high);
		cout << res << endl;
	}
	return 0;
}
