//https://codeforces.com/problemset/problem/681/C
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct node{
	string s;
	int num;
}a[1000000];
int main(){
	int n, num;
	string str;
	while(cin >> n && n){
		int cnt = 0;
		priority_queue<int, vector<int> ,greater<int>> q;
		for(int i = 0; i < n; i++){
			cin >> str;
			if(str[0] != 'r'){
				cin >> num;
			}
			if(str[0] == 'i'){
				q.push(num);
			}else if(str[0] == 'r'){
				if(q.empty()){
					a[cnt].s = "insert";
					a[cnt++].num = 0;
					q.push(0);
				}
				q.pop();
			}else if(str[0] == 'g'){
				while(!q.empty() && q.top() < num){
					a[cnt++].s = "removeMin";
					q.pop();
				}
				while(q.empty() || q.top() > num){
					a[cnt].s = "insert";
					a[cnt++].num = num;
					q.push(num);
				}
			}
			a[cnt++].s = str;
			if(str[0] != 'r'){
				a[cnt-1].num = num;
			}
		}
		cout << cnt << endl;
		for(int i = 0; i < cnt; i++){
			cout << a[i].s << " ";
			if(a[i].s[0] != 'r'){
				cout << a[i].num;
			}
			cout << endl;
		}
	}
}
