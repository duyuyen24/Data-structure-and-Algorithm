//https://www.spoj.com/problems/SOCIALNE/
#include <iostream>
#include <string>

using namespace std;

int main(){
	int T, l;
	string mt[51],line;
	int numf[51];
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> line;
		l = line.size();
		mt[0] = line;
		for(int i = 0; i < l; i++){
			numf[i] = 0;
			if(i > 0){
				cin >> mt[i];
			}
		}
		for(int i = 0; i < l; i++){
			for(int j = i + 1; j < l; j++){
				if(mt[i][j] == 'N'){
					for(int k = 0; k < l; k++){
						if(mt[j][k] == 'Y' && mt[i][k] == 'Y'){
							numf[j]++;
							numf[i]++;
							break;
						}
					}
				}
			}
		}

		int m = 0;
		int w = 0;
		for(int i = 0; i < l; i++){
			if(numf[i] > m){
				m = numf[i];
				w = i;
			}
		}
		cout << w << " " << m << endl;
	}
	return 0;
}

