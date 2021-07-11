#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(int s, vector<vector<int>> graph, int N){
	queue<int> q;
	q.push(s);
	vector<int> distance(N, -1);
	vector<bool> visited(N, false);
	visited[s] = true;
	distance[s] = 0;
	while(!q.empty()){
		auto node = q.front();
		q.pop();
		for(auto it = graph[node].begin(); it != graph[node].end(); it++){
			if(!visited[*it]){
				distance[*it] = distance[node] + 1;
				q.push(*it);
				visited[*it] = true;
			}
		}
	}
	for(int i = 0; i < N; i++){
		if(visited[i] == false){
			cout << -1 << " ";
		}else if(distance[i] > 0){
			cout<< distance[i]*6 << " ";
		}
	}
	cout<<endl;
}

int main() {
	int testcase;
	cin >> testcase;
	for(int i = 0; i < testcase; i++){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> graph(n,vector<int>());
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			graph[x-1].push_back(y-1);
			graph[y-1].push_back(x-1);
		}
		int s;
		cin >> s;
		bfs(s-1, graph,n);
	}
	return 0;
}
