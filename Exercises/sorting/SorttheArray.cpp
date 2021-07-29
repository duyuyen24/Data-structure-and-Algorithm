//link: https://codeforces.com/problemset/problem/451/B
#include <iostream>
#include <algorithm>
using namespace std;
bool check(int a[], int n){
	for (int i = 0; i < n - 1; i++)
	{
		if(a[i] > a[i + 1]){
			return 0;
		}
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	bool flag = 1;
	int front = 0, end ;
	for (int i = 0; i < n - 1; i++){
		if(a[i] > a[i + 1])
		{
			flag = 0;
			front = i;
			break;
		}
	}

	if(flag){
		cout << "yes" << endl << "1 1" << endl;
		return 0;
	}

	end = front;
	while((end < n - 1) && (a[end] > a[end + 1])){
		end++;
	}
	reverse(a + front, a + end + 1);
	if(check(a, n)){
		cout << "yes" << endl;
		cout << ++front << " " << ++end << endl;
	}else{
		cout << "no\n" << endl;
	}
	return 0;
}
