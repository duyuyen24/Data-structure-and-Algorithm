//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146
#include <bits/stdc++.h>
using namespace std;

int main(){
	long int  n, t, x, flags, flagq, flagp;

	while(scanf("%ld",&n) == 1){
		stack<long int> mystack;
		queue<long int> myqueue;
		priority_queue<long int> mypq;

		flags = 0;
		flagq = 0;
		flagp = 0;

		for(int i = 1; i <= n; i++){
			scanf("%ld%ld", &t, &x);
			if(t == 1){
				mystack.push(x);
				myqueue.push(x);
				mypq.push(x);

				flags += 1;
				flagq += 1;
				flagp += 1;
			}else if(t == 2){
				if(!mystack.empty() && mystack.top() == x ){
					mystack.pop();
					flags += 1;
				}
				if(!myqueue.empty() && myqueue.front() == x ){
					myqueue.pop();
					flagq += 1;
				}
				if(!mypq.empty() && mypq.top() == x ){
					mypq.pop();
					flagp += 1;
				}
			}
		}
		if((flags == n && flagq == n) || (flags == n && flagp == n) || (flagp == n && flagq == n))
			cout << "not sure\n";
		else if(flagp != n && flagq != n && flags != n)
			cout << "impossible\n";
		else if(flags == n)
			cout << "stack\n";
		else if(flagq == n)
			cout << "queue\n";
		else
			cout << "priority queue\n";

	}
	return 0;
}
