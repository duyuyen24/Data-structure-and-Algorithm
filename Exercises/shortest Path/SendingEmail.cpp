// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1927
#include <bits/stdc++.h>

#define inf 1000000000

using namespace std;

int dist[20010];
int n, m, s, t;
vector<vector<pair<int, int>>> adj;

void Dijkstra(int s){
	for(int i = 0; i < n; i++){
		dist[i] = inf;
	}
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	pq.push(make_pair(dist[s], s));

	while(!pq.empty()){
		pair<int, int> p = pq.top();
		pq.pop();
		int t = p.first;
		int u = p.second;
		if(t > dist[u]){
			continue;
		}
		for(int i = 0; i < adj[u].size(); i++){
			if(dist[adj[u][i].first] > dist[u] + adj[u][i].second){
				dist[adj[u][i].first] = dist[u] + adj[u][i].second;
				pq.push(make_pair(dist[adj[u][i].first], adj[u][i].first));
			}
		}
	}
}


int main(){
	int tc;
	scanf("%d", &tc);
	for(int k = 1; k <= tc; k++){
		scanf("%d%d%d%d", &n, &m, &s, &t);
		adj.assign(n, vector<pair<int, int>>(0));
		int x, y, l;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d", &x, &y, &l);
			adj[x].push_back( make_pair(y, l) );
			adj[y].push_back( make_pair(x, l) );
		}

		Dijkstra(s);
		printf("Case #%d: ", k);
		if(dist[t] != inf){
			printf("%d\n", dist[t]);
		}else{
			printf("unreachable\n");
		}
	}
}
