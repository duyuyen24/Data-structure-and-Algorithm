//link:https://codeforces.com/problemset/problem/551/A
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long int n,a[20000],b[20000];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i]=a[i];
	}

	for(int i = 0; i < n; i++){
		int x = 0;
		for(int j = 0; j < n; j++){
			if(a[i] < a[j]){
				x++;
			}
		}
		cout<<x+1<<" ";
	}
	cout<<endl;
	return 0;
}
