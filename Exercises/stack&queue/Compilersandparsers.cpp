//https://www.codechef.com/problems/COMPILER
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string chrAr;
		cin >> chrAr;
		int top = 0, cnt = 0, tmpCnt = 0;
		for(int i = 0; i < chrAr.size(); i++){
			if(chrAr.at(i) == '<'){
				top++;
			}else{
				top--;
				if(top < 0){
					break;
				}
				tmpCnt++;
				if(top == 0){
					cnt = tmpCnt;
				}	
			}
		}	
		cout << cnt*2 << endl;
	}
	
	return 0;
}


