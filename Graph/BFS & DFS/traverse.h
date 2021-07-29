#ifndef GRAPHH_H
#define GRAPHH_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> graph[100];
bool vis[100];
int level[100];
int path[100];

int bfs(int s, int k, int v){
	for(int i = 0; i < v; i++){
		vis[i] = false;
		path[i] = -1;
	}

	queue<int> q;
	q.push(s);

	vis[s] = true;
	int c = 0;

	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i = 0; i < graph[p].size();i++){
			int t = graph[p][i];
			if(!vis[t]){
				vis[t] = true;
				level[t] = level[p]+1;
				q.push(t);
				if(level[t] == k){
					c++;
				}
				path[t] = p;
			}
		}
	}
	return c;
}

void printPath(int s, int f){
	if(s == f){
		cout << f << " ";
	}else{
		if(path[f] == -1){
			cout << "No path" << endl;
		}else{
			printPath(s, path[f]);
			cout << f << " ";
		}
	}
}

void dfs(int s) {
	vis[s] = true;
	for(int i = 0; i < graph[s].size(); i++){
		int t = graph[s][i];
		if(!vis[t]){
			dfs(t);
		}
	}
}

#endif // GRAPHH_H
