//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975
#include<cstdio>
#include<cmath>
#include<climits>
#define N 101

struct Point{
	double x, y;
	double getDistance(const Point& a){
		return sqrt((x - a.x)*(x - a.x) + (y - a.y)*(y - a.y));
	}

}point[N];

double prim(int n){
	bool isVisit[N] = {};
	double w[N][N] = {}, d[N];
	double sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = i + 1; j < n; j++){
			w[j][i] = w[i][j] = point[i].getDistance(point[j]);
		}
	}
	for (int i = 0; i < n; i++){
		d[i] = w[0][i];
	}
	isVisit[0] = true;

	for (int i = 0; i < n; i++){
		int next = -1;
		double min = INT_MAX;
		for (int j = 0; j < n; j++)
			if (d[j] < min && !isVisit[j]){
				min = d[j];
				next = j;
			}
		if (next == -1)
			break;

		sum += min;
		isVisit[next] = true;

		for (int j = 0; j < n; j++){
			if (w[next][j] < d[j]){
				d[j] = w[next][j];
			}
		}
	}

	return sum;
}

int main(){
	int Case;
	scanf("%d", &Case);

	int M[N][N] = {};
	while (Case--){
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}
		printf("%.2lf\n", prim(n));
		if (Case)
			printf("\n");
	}

	return 0;
}
