//https://www.spoj.com/problems/SHPATH/en/
#include<bits/stdc++.h>
using namespace std;
#define INF (1<<25)
 
map<string,int> city;
vector<vector<pair<int,int>>> neighbors;
vector<int> vals;
int n;
 
typedef bool (*comp)(pair<int,int>,pair<int,int>);
 
bool compare(pair<int,int> a,pair<int,int> b){
	return a.second > b.second;
}
 
void dijkstra(int source,int destination){
	priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq(compare);
	pq.push(pair<int,int>(source,0));
	vals[source] = 0;
	while(!pq.empty()){
		pair<int,int> x = pq.top();
		int top = x.first;
		pq.pop();
		if(top == destination)break;
		if(vals[top] < x.second){
			continue;
		}
		for(int i = 0; i < neighbors[top].size(); i++){
			pair<int,int> neighbor = neighbors[top][i];
			int in = neighbor.first, cost = neighbor.second;
			if(vals[in] > vals[top] + cost){
				vals[in] = vals[top] + cost;
				pq.push(make_pair(in,vals[in]));
			}
		}
	}
}
 
 
int main(){
	int s;
	cin >> s;
	city.clear();
	while(s--){
		cin >> n;
		neighbors = vector<vector<pair<int,int>>>(n,vector<pair<int,int>>());
		for(int i = 0; i < n; i++){
			char name[11];
			cin >> name;
			city[string(name)] = i;
			int inn;
			cin >> inn;
			while(inn--){
				int nr,cost;
				cin >> nr >> cost;
				neighbors[i].push_back(make_pair(nr - 1,cost));
			}
		}
		int r;
		cin >> r;
		while(r--){
			char source[11], destination[11];
			cin >> source >> destination;
			vals = vector<int>(n,INF);
			string start = string(source);
			string end = string(destination);
			dijkstra(city[start], city[end]);
			cout << vals[city[end]] << endl;
		}
	}
	return 0;
}
