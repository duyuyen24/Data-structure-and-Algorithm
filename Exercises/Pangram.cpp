//https://codeforces.com/problemset/problem/520/A
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    string str;
    while(scanf("%d",&n)!=EOF){
        cin >> str;
        //int l = strlen(s);
        set<int> s;
        for(int i = 0; i < n; i ++){
            if(str[i] >= 'A' && str[i] <= 'Z')
                s.insert(str[i] - 'A');
            else if(str[i] >= 'a'&&str[i] <= 'z')
                s.insert(str[i] - 'a');
        }
        //cout<<s.size()<<endl;
        if(s.size() == 26)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
