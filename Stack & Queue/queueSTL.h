#ifndef QUEUESTL_H
#define QUEUESTL_H
#include <bits/stdc++.h>
using namespace std;

void showq(queue<int> gq)
{
	queue<int> g = gq;
	while (!g.empty()) {
		cout << g.front() << " ";
		g.pop();
	}
	cout << '\n';
}
queue<int> reverse(queue<int> q){
	int s = q.size();

	queue<int> ans;

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < q.size() - 1; j++) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		ans.push(q.front());
		q.pop();
	}
	return ans;
}

bool checkSortedUsingStack(queue<int> q, int n){
	stack<int> st;
	int expected = 1;
	int fnt;

	while (!q.empty()) {
		fnt = q.front();
		q.pop();
		if (fnt == expected)
			expected++;
		else {
			if (st.empty()) {
				st.push(fnt);
			} else if (!st.empty() && st.top() < fnt) {
				return false;
			}else
				st.push(fnt);
		}

		while (!st.empty() && st.top() == expected) {
			st.pop();
			expected++;
		}
	}
	if (expected - 1 == n && st.empty())
		return true;

	return false;
}

#endif // QUEUESTL_H
