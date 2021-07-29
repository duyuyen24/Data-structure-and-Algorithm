//https://codeforces.com/problemset/problem/721/B
#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b){
	return a.length() < b.length();
}

int main(){
	int n, k;
	cin >> n >> k;
	string s[110];
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	}
	string str;
	cin >> str;
	
	sort(s+1, s+1+n, cmp);
	
	int t1 = 0, t2 = 0;
	for (int i = 1; i <= n; i++){
		if (s[i].length() > str.length()){
			break;
		}
		if (s[i].length() < str.length()){
			t1++;
		}
		if (s[i].length() == str.length()){
			t2++;
		}
	}
	int tmin = t1 + 1 + (t1/k) * 5;
	int tmax = t1 + t2 + ((t1 + t2 - 1)/k) * 5;
	cout << tmin << ' ' << tmax << endl;
	
	return 0;
}
