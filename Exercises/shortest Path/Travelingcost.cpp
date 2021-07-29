//link :https://www.spoj.com/problems/TRVCOST/
#include<bits/stdc++.h>
using namespace std;

#define MAX 100
const int INF = 1e9;

vector<vector<pair<int, int>>> graph;
bool vis[MAX];
int path[MAX];
vector<int> dist(MAX, INF);

struct option{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
		return a.second > b.second;
	}
};

void dijkstra(int s){
	priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
	pq.push(make_pair(s,0));
	dist[s] = 0;
	while(!pq.empty()){
		pair<int, int> top = pq.top();
		pq.pop();
		int u = top.first;
		int w = top.second;

		for(int i = 0; i < graph[u].size(); i++){
			pair<int, int> neighbor = graph[u][i];
			if(w + neighbor.second < dist[neighbor.first]){
				dist[neighbor.first] = w + neighbor.second;
				pq.push(make_pair(neighbor.first, dist[neighbor.first]));
				path[neighbor.first] = u;
			}
		}
	}
}

int main(){
	int n, a, b, c;
	cin >> n;
	graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());

	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		graph[b].push_back(make_pair(a,c));
	}
	int s, q, dest;
	cin >> s;
	dijkstra(s);

	cin >> q;
	while(q--){
		cin >> dest;
		if(path[dest]){
			cout << "NO PATH" << endl;
		}else{
			cout << dist[dest] << endl;
		}
	}
	return 0;
}
