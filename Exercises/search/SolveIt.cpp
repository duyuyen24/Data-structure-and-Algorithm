//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1282
#include <cstdio>
#include <cmath>
#define EPS 1e-7
using namespace std;

int p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double bisection() {
	double low = 0, high = 1;
	while (low + EPS< high) {
		double x = (low + high) / 2;
		if (f(low) * f(x) <= 0) {
			high = x;
		} else {
			low = x;
		}
	}
	return (low + high)/2;
}

int main() {
	while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if (f(0) * f(1) > 0) {
			printf("No solution\n");
		} else {
			printf("%.4lf\n", bisection());
		}
	}

	return 0;
}
