//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX
#define MAXNODES 1005
#define MAXEDGES 2005

typedef struct{
	int u,v,w;
} Edge;

int dist[MAXNODES], path[MAXNODES];
Edge edge[MAXEDGES];
int n, m;

int BellmanFord(int s){
	for(int i = 0; i < n; i++){
		dist[i] = INF;
		path[i] = -1;
	}
	dist[s] = 0;

	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m; j++){
			if(dist[edge[j].v] > dist[edge[j].u]+edge[j].w){
				dist[edge[j].v] = dist[edge[j].u]+edge[j].w;
				path[edge[j].v] = edge[j].u;
			}
		}

	for(int j = 0; j < m; j++){
		if(dist[edge[j].v] > dist[edge[j].u]+edge[j].w) return 0;
	}
	return 1;
}

int main(){
	int num;
	scanf("%d", &num);
	while(num--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		if(BellmanFord(0)) printf("not ");
		printf("possible\n");
	}
	return 0;
}
