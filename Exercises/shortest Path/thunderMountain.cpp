//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
#include <cstring>
#include <cstdio>
#include <cmath>

const double oo = 50000;

struct point{
	double x,y;
};
point  P[101];

double dist[101][101];

int main(){
	int T,n;
	while (~scanf("%d",&T))
		for (int t = 1; t <= T; ++ t) {

			scanf("%d",&n);
			for (int i = 0; i < n; ++ i)
				scanf("%lf%lf",&P[i].x,&P[i].y);

			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < n; ++ j) {
					dist[i][j] = sqrt((P[i].x-P[j].x)*(P[i].x-P[j].x)+(P[i].y-P[j].y)*(P[i].y-P[j].y));
					if (dist[i][j] > 10.0)
						dist[i][j] = oo;
				}

			for (int k = 0; k < n; ++ k)
				for (int i = 0; i < n; ++ i)
					for (int j = 0; j < n; ++ j)
						if (dist[i][j] > dist[i][k] + dist[k][j])
							dist[i][j] = dist[i][k] + dist[k][j];

			double Max = 0;
			for (int i = 0; i < n; ++ i)
				for (int j = 0; j < n; ++ j)
					if (Max < dist[i][j])
						Max = dist[i][j];

			printf("Case #%d:\n",t);
			if (Max == oo)
				printf("Send Kurdy\n\n");
			else printf("%.4lf\n\n",Max);
		}
	return 0;
}
