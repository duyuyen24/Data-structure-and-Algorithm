#ifndef STACKSTL_H
#define STACKSTL_H
#include <bits/stdc++.h>
using namespace std;

void transfer(stack<int>& X, stack<int>& Y){
	while (!X.empty()) {
		Y.push(X.top());
		X.pop();
	}
}

void display(stack<int> S){
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
}
void reverseStackUsingTwoStacks(stack<int>& S)
{
	stack<int> A, B;

	transfer(S, A);

	transfer(A, B);

	transfer(B, S);

	display(S);
}

void insertToBottom(stack<int> S, int N){
	stack<int> temp;

	while (!S.empty()) {
		temp.push(S.top());

		S.pop();
	}

	S.push(N);

	while (!temp.empty()) {
		S.push(temp.top());

		temp.pop();
	}

	display(S);
}
void printPair(pair<int, int> p){
	cout << "("
		 << p.first << ", "
		 << p.second << ") ";
}

void Showstack(stack<pair<int, int> > s){
	while (!s.empty()) {
		printPair(s.top());
		s.pop();
	}

	cout << '\n';
}

stack<int> sortStack(stack<int> input){
	stack<int> temp;
	while(!input.empty()){
		int t = input.top();
		input.pop();

		while(!temp.empty() && temp.top() > t){
			input.push(temp.top());
			temp.pop();
		}
		temp.push(t);
	}
	return temp;
}

bool sortPair(stack<int> s){
	stack<int> aux;
	while(!s.empty()){
		aux.push(s.top());
		s.pop();
	}

	bool res = true;
	while(!aux.empty()){
		int x = aux.top();
		aux.pop();
		int y = aux.top();
		aux.pop();
		if(x > y){
			res = false;
		}
		s.push(x);
		s.push(y);
	}
	if (aux.size() == 1)
		s.push(aux.top());
	return res;
}
void checksortStack(stack<int> input, int n){
	stack<int> temp;
	int k = 0;
	while(!input.empty()){
		while(!temp.empty() && temp.top() == k + 1){
			k++;
			temp.pop();
		}
		if(input.top() != k +1){
			temp.push(input.top());
		}else{
			k++;
		}
	}
	while (temp.size() && temp.top() == k + 1){
		k++;
		temp.pop();
	}
	if(k == n){
		cout << "yes\n";
	}else{
		cout << "no\n";
	}
}

#endif // STACKSTL_H
