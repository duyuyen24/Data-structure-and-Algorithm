//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1187
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	int c, r, q, tc = 0;
	bool newline = false;

	while(cin >> c >> r >> q, c != 0 || r != 0 || q != 0) {
		int feast[c];
		for(int i = 0; i < c; i++){
			cin >> feast[i];
		}

		long long  matrix[c][c];

		for(int i = 0; i < c; i++) {
			for(int j = 0; j < c; j++) {
				matrix[i][j] = INT_MAX;
			}
		}

		int u, v, cost;
		while(r--) {
			cin >> u >> v >> cost;
			--u, --v;
			matrix[u][v] = cost;
			matrix[v][u] = cost;
		}

		int times = 2;

		int feastMat[c][c];
		for(int i = 0; i < c; i++){
			for(int j = 0; j < c; j++){
				feastMat[i][j] = max(feast[i], feast[j]);
			}
		}
		while(times--) {
			for(int k = 0; k < c; k++) {
				for(int i = 0; i < c; i++) {
					for(int j = 0; j < c; j++) {
						if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX && matrix[i][j] + feastMat[i][j] > matrix[i][k] + matrix[k][j] + max(feastMat[i][k], feastMat[k][j])) {
							matrix[i][j] = matrix[i][k] + matrix[k][j];
							feastMat[i][j] = max(feastMat[i][k], feastMat[k][j]);
						}
					}
				}
			}
		}

		if(newline){
			cout << '\n';
		}
		newline = true;

		cout << "Case #" << ++tc << endl;
		while(q--) {
			cin >> u >> v;
			--u, --v;
			if(matrix[u][v] == INT_MAX){
				cout << "-1" << endl;
			}else{
				cout << matrix[u][v] + feastMat[u][v] << endl;
			}
		}
	}

	return 0;
}
