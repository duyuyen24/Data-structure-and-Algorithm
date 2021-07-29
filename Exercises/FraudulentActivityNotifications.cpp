//https://www.hackerrank.com/contests/openbracket-2016/challenges/fraudulent-activity-notifications
#include <algorithm>
#include <iostream>
using namespace std;

int A[200000];
int F[200];

int median(int D) {
	int p = 0;
	for (int i = 0; i < 200; i++) {
		p += F[i];
		if (p * 2 > D) {
			return 2 * i;
		} else if (p * 2 == D) {
			for (int j = i + 1; ; j++) {
				if (F[j]) {
					return i + j;
				}
			}
		}
	}
	return -1;
}

int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (i >= d) {
			if (A[i] >= median(d)) {
				++result;
			}
			F[A[i - d]]--;
		}
		F[A[i]]++;
	}
	cout << result << endl;
	return 0;
}
