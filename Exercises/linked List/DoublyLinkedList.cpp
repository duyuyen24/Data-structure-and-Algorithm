//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_C
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Node {
	int k;
	Node *next, *prev;
};

Node *nil;

void init() {
	nil = (Node *) malloc(sizeof(Node));
	nil->next = nil;
	nil->prev = nil;
}

Node *list_se(int k) {
	Node *c = nil->next;
	while (c != nil && c->k != k){
		c = c->next;
	}
	return c;
}

void print_list() {
	Node *c = nil->next;
	int isf = 0;
	while (true) {
		if (c == nil){
			break;
		}
		if (isf++ > 0){
			cout << ' ';
		}
		cout << c->k;
		c = c->next;
	}
	cout << endl;
}

void delete_Node(Node *t) {
	if (t == nil){
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

void delete_first() {
	delete_Node(nil->next);
}

void delete_last() {
	delete_Node(nil->prev);
}

void delete_k(int k) {
	delete_Node(list_se(k));
}

void insert(int k) {
	Node *x = (Node *) malloc(sizeof(Node));
	x->k = k;
	x->next = nil->next;
	nil->next->prev = x;
	nil->next = x;
	x->prev = nil;
}

int main() {
	init();
	string co;
	int k, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> co;
		switch (co[0]) {
		case 'i':
			cin >> k;
			insert(k);
			break;
		case 'd':
			if (co.length() > 6) {
				switch (co[6]) {
				case 'F':
					delete_first();
					break;
				case 'L':
					delete_last();
					break;
				}
			} else {
				cin >> k;
				delete_k(k);
			}
			break;
		}
	}
	print_list();
	return 0;
}
