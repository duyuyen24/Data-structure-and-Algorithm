//https://www.spoj.com/problems/UCV2013B/
#include<bits/stdc++.h>
using namespace std;
const int INF = 20000000;
const int MAX = 105;

struct Node {
	int source, target, weight;

	Node(int source, int target, int weight) {
		this->source = source;
		this->target = target;
		this->weight = weight;
	}
};

int n;
vector<Node> graph;
int dist[MAX][MAX];
bool negCycle[MAX][MAX];
string name[MAX];

void BellMan_Ford(int s) {
	for (int i = 0; i < n; ++i) {
		dist[s][i] = INF;
		negCycle[s][i] = false;
	}

	dist[s][s] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph.size(); j++) {
			int u = graph[j].source;
			int v = graph[j].target;
			int w = graph[j].weight;

			if (dist[s][u] != INF && dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w;

				if (i == n - 1) {
					negCycle[s][v] = true;
				}
			}
		}
	}
}

int main() {
	int cs = 1;
	while (cin >> n && n != 0) {
		int w;
		int q;
		graph.clear();

		for (int i = 0; i < n; i++) {
			cin >> name[i];
			for (int j = 0; j < n; j++) {
				cin >> w;
				if (i == j) {
					if (w > 0) {
						w = 0;
					}else if(w < 0){
						w = -INF;
					}
				}

				if (i == j || w != 0) {
					graph.push_back(Node(i, j, w));
				}
			}
		}

		for (int i = 0; i < n; i++) {
			BellMan_Ford(i);
		}

		cin >> q;
		cout << "Case #" << cs++ << ":" << endl;

		while (q--) {
			int u, v;
			cin >> u >> v;

			if (negCycle[u][v]) {
				cout << "NEGATIVE CYCLE" << endl;
			}else{
				cout << name[u] << "-" << name[v] << " ";

				if (dist[u][v] == INF) {
					cout << "NOT REACHABLE" << endl;
				} else {
					cout << dist[u][v] << endl;
				}
			}
		}
	}
	return 0;
}
