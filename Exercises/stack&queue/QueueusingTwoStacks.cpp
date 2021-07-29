//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem
#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    stack<int> s1;
    stack<int> s2;
    cin >> q;
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        switch(op){
            case 1:
                int num;
                cin>>num;
                s1.push(num);
                break;
            case 2:
                if(s2.empty())
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s2.pop();
                break;
            case 3:
                if(s2.empty())
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s2.top() << endl;
                break;
        }
    }
    return 0;
}
