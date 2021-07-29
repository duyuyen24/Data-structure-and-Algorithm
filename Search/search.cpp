#include <bits/stdc++.h>
#include"search1.h"
using namespace std;
int main(){
	vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
	//Vector search
	int haveIndex = linearS(v, v.size(), 5);
	//int haveIndex = binaryS(v,0, v.size(), 1);
	if(haveIndex == -1){
		cout << "Element not in vector\n";
	} else {
		cout << "Element in vector\n";
	}
	return 0;
}
