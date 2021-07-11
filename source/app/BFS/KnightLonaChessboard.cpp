
//link : https://www.hackerrank.com/challenges/knightl-on-chessboard
#include<bits/stdc++.h>

using namespace std;

const int MAX = 2e9;
int n, mt[50][50];

void can(queue<pair<int, int>> &q, int i, int j, int d){
	if(i >= 0 && i < n && j >= 0 && j < n && mt[i][j] > d){
		mt[i][j] = d;
		q.push(make_pair(i,j));
	}
}

int bfs(int n, int a, int b){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mt[i][j] = MAX;
		}
	}

	mt[0][0] = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0,0));

	while(!q.empty()){
		pair<int, int> v = q.front();
		q.pop();
		int x = v.first;
		int y = v.second;
		int dist = mt[x][y] + 1;
		can(q, x + a, y + b, dist);
		can(q, x + a, y - b, dist);
		can(q, x - a, y + b, dist);
		can(q, x - a, y - b, dist);
		can(q, x + b, y + a, dist);
		can(q, x + b, y - a, dist);
		can(q, x - b, y + a, dist);
		can(q, x - b, y - a, dist);
	}
	int ans = mt[n - 1][n - 1];
	if(ans == MAX){
		return -1;
	}
	return ans;
}

int main(){
	cin >> n;
	for(int i = 1; i < n; i++){
		for(int j = 1; j < n; j++){
			cout << bfs(n, i, j) << " ";
		}
		cout << "\n";
	}

}
