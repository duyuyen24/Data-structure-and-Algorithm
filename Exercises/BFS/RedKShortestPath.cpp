//link: https://www.hackerrank.com/challenges/red-knights-shortest-path/problem
#include<iostream>
#include<queue>
#include<string>
using namespace std;

void printRKShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
	typedef struct{
		int row;
		int col;
		string str;
	}Vertex;

	int count = 0;

	bool visited[200][200] = {false};
	queue<Vertex> Q;
	Vertex start = {i_start, j_start};
	visited[i_start][j_start] = true;
	Q.push(start);

	while(!Q.empty()){
		Vertex v = Q.front();
		Q.pop();
		for(int i = 1; i <= 6; i++){
			switch(i){
			case 1://UL
				if(v.row - 2 >= 0 && v.col - 1 >= 0 && visited[v.row - 2][v.col - 1] == false){
					visited[v.row - 2][v.col - 1] = true;
					Vertex temp = {v.row - 2, v.col - 1 , v.str + "UL "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}

				}break;
			case 2://UR
				if(v.row - 2 >= 0 && v.col + 1 < n  && visited[v.row - 2][v.col + 1] == false){
					visited[v.row - 2][v.col + 1] = true;
					Vertex temp = {v.row - 2, v.col + 1 , v.str + "UR "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}
				}break;
			case 3://R
				if(v.col + 2 <n && visited[v.row][v.col + 2] == false){
					visited[v.row][v.col + 2] = true;
					Vertex temp = {v.row, v.col + 2, v.str + "R "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}
				}break;
			case 4://LR
				if(v.row + 2 < n && v.col + 1 < n && visited[v.row + 2][v.col + 1] == false){
					visited[v.row + 2][v.col + 1] = true;
					Vertex temp = {v.row + 2, v.col + 1 , v.str + "LR "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}
				}break;
			case 5://LL
				if(v.row + 2 <n && v.col - 1 >= 0 && visited[v.row + 2][v.col - 1] == false){
					visited[v.row + 2][v.col - 1] = true;
					Vertex temp = {v.row + 2, v.col - 1 , v.str + "LL "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}
				}break;
			case 6://L
				if(v.col - 2 >= 0 && visited[v.row][v.col - 2] == false){
					visited[v.row][v.col - 2] = true;
					Vertex temp = {v.row, v.col - 2 , v.str + "L "};
					Q.push(temp);
					if(temp.row == i_end && temp.col == j_end){
						for(int i = 0; i < temp.str.size(); i++){
							if(temp.str[i] == ' '){
								count++;
							}
						}
						cout << count << endl;
						cout << temp.str << endl;
						return;
					}
				}break;
			}
		}
	}
	cout << "Impossible" << endl;
}

int main() {
	int n;
	cin >> n;
	int i_start;
	int j_start;
	int i_end;
	int j_end;
	cin >> i_start >> j_start >> i_end >> j_end;
	printRKShortestPath(n, i_start, j_start, i_end, j_end);
	return 0;
}
