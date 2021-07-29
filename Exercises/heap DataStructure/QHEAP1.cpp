//https://vjudge.net/problem/HackerRank-qheap1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
priority_queue<int, vector<int>, greater<int> > pqRemove;

void add(){
	int n;
	cin >> n;
	pq.push(n);
}

void remove(){
	int n;
	cin >> n;
	pqRemove.push(n);
}

void printMin(){
	while(!pqRemove.empty() && pqRemove.top() == pq.top()){
		pq.pop();
		pqRemove.pop();
	}
	cout << pq.top() << endl;
}

int main() {
	int Q;
	cin >> Q;
	while(Q != 0){
		int c;
		cin >> c;
		if(c == 1){
			add();
		}else if(c == 2){
			remove();
		}else if(c == 3){
			printMin();
		}
		Q--;
	}
	return 0;
}
