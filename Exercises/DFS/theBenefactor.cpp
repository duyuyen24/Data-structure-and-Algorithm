//https://www.spoj.com/problems/BENEFACT/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<vector<pair<int, int>>> a;
int visited[50001];
int res = 0, cindex = 0;

void dfs(int x, int dis){
	if(res < dis){
		res = dis;
		cindex = x;
	}
	visited[x] = 1;
	for(int i = 0; i < a[x].size(); i++){
		if(visited[a[x][i].first] == 0)
			dfs(a[x][i].first, dis + a[x][i].second);
	}
	visited[x] = 0;
}

int main(){
	int nTestCase;
	cin >> nTestCase;
	for(int t = 0; t < nTestCase; t++){
		int nCity, start, end, dis;
		cin >> nCity;
		a = vector<vector<pair<int, int>>>(nCity + 1);
		for(int st = 1; st < nCity; st++){
			cin >> start >> end >> dis;
			a[start].push_back(make_pair(end, dis));
			a[end].push_back(make_pair(start, dis));
		}
		res = 0;
		cindex = 0;
		dfs(1,0);

		res = 0;
		dfs(cindex, 0);
		cout << res << endl;
	}
	return 0;
}
