//https://codeforces.com/problemset/problem/518/A
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string.h>

using namespace std;
string s;
string t;
int main()
{
	cin >> s >> t;
	int len = s.length();
	for(int i = len -1; i >= 0 ; i--){
		if(s[i] == 'z'){
			s[i] = 'a';
		}else{
			s[i] = s[i] + 1;
			break;
		}
	}
	if(s != t)
		cout << s << endl;
	else
		cout << "No such string" << endl;
	return 0;
}
