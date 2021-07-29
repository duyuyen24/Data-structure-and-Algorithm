//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3359
#include<bits/stdc++.h>
using namespace std;
int main(){
	int cases = 0;
	int p,c;
	
	while(cin >> p >> c, p != 0, c != 0){
		deque<int> dq;
		if(p < c){
			for(int i = 1; i <= p; i++){
				dq.push_back(i);
			}
		}else{
			for(int i = 1;i <= c; i++){
				dq.push_back(i);
			}
		}
		cases++;
		printf("Case %d:\n", cases);
		while(c--){
			string com;
			cin >> com;
			if(com == "N"){
				int e = dq.front();
				cout << e << endl;
				dq.pop_front();
				dq.push_back(e);
			}else{
				int num;
				cin >> num;
				for(deque<int>::iterator it = dq.begin(); it != dq.end(); it++){
					if(*it == num){
						dq.erase(it);
						break;
					}
				}
				dq.push_front(num);
			}
		}
	}
	return 0;
}
