//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=377
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	int tc = 1;
	double x;
	bool flag;
	double M[30][30];
	map<string, int> cntr;
	string s1, s2;


	while(cin >> n && n != 0){

		cntr.clear();
		for(int i = 0; i < n; i++){
			cin >> s1;
			cntr[s1] = i;
		}

		memset(M, 0, sizeof(M));

		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> s1 >> x >> s2;
			M[cntr[s1]][cntr[s2]] = x;
		}

		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(M[i][j] < M[i][k] * M[k][j]){
						M[i][j] = M[i][k] * M[k][j];
					}
				}
			}
		}

		flag = false;
		for(int i = 0; i < n; i++){
			if(M[i][i] > 1.0){
				flag = true;
			}
		}

		cout << "Case " << tc << ": ";
		tc++;

		if(flag){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}

	return 0;
}
