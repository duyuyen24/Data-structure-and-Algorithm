/*#include <iostream>
#include <string>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <semaphore.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
//#include"llist_queue.h"
//#include"llist_stack.h

#define LIMIT 5
int queue[LIMIT];
int stack[LIMIT];
int font = -1;
int rear = -1;
*/

#include"stackSTL.h"
//#include"queueSTL.h"
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	/*
	queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);
	gquiz.push(5);
	gquiz.push(1);
	gquiz.push(2);
	gquiz.push(3);
	gquiz.push(4);

	cout << "The queue gquiz is : ";
	showq(gquiz);

	cout << "\ngquiz.size() : " << gquiz.size();
	cout << "\ngquiz.front() : " << gquiz.front();
	cout << "\ngquiz.back() : " << gquiz.back();

	cout << "\ngquiz.pop() : ";
	gquiz.pop();
	showq(gquiz);
	gquiz = reverse(gquiz);
	cout << "Reverse queue:\n";
	showq(gquiz);
	int n = gquiz.size();

	(checkSortedUsingStack(gquiz, n) ? (cout << "Yes\n") : (cout << "No\n"));
	*/
	//stack stl

	stack<int> S;

	S.push(34);
	S.push(3);
	S.push(31);
	S.push(98);
	S.push(92);
	S.push(23);

	// Function call
	reverseStackUsingTwoStacks(S);
	int N = 7;
	insertToBottom(S, N);
	stack<int> tmpStack = sortStack(S);
	cout << "Sorted numbers are:\n";
	display(tmpStack);
	if (sortPair(S)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	cout << "Stack content (from top) after function call\n";
	display(S);
	//stackSTL + pair
	stack<pair<int, int> > s;

	s.push({ 10, 20 });
	s.push({ 15, 5 });
	s.push({ 1, 5 });
	s.push({ 5, 10 });
	s.push({ 7, 9 });
	cout << "Stack of Pairs: ";
	Showstack(s);

	cout << "\nSize of Stack of Pairs: " << s.size();
	cout << "\nTop of Stack of Pairs: ";
	printPair(s.top());

	cout << "\n\nRemoving the top pair\n";
	s.pop();

	cout << "Current Stack of Pairs: ";
	Showstack(s);
	int n;
	int a[1000];
	stack<int> input;
	cin >> n;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++){
		input.push(a[i]);
	}
	cout << "Number Sort Stack: ";
	checksortStack(input, n);

	/*
	int n,m;
	int a[100];
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int count = 0;
	//int sum = 0;
	sort(a, a + n);
	for(int i = 0; i > n; i++){
		//sum = sum + a[i];
		//if(sum <= m){
		//	count++;
		//}
		printf("%d", a[i]);
	}
*/
	//queue_array
	/*
	insert(queue, font, rear,1);
	insert(queue, font, rear,2);
	insert(queue, font, rear,3);
	delet(queue, font, rear);
*/
	//circilar queue_array
	/*
	enqueue(queue, &font, &rear,1);
	enqueue(queue, &font, &rear,2);
	enqueue(queue, &font, &rear,3);
	enqueue(queue, &font, &rear,4);
	enqueue(queue, &font, &rear,5);

	dequeue(queue, &font, &rear);
	dequeue(queue, &font, &rear);
	dequeue(queue, &font, &rear);
	enqueue(queue, &font, &rear,1);
	dequeue(queue, &font, &rear);
	enqueue(queue, &font, &rear,2);
*/
	//stack_array
	/*
	push(stack, &font,1);
	push(stack, &font,2);
	push(stack, &font,3);
	pop(stack,&font);
	push(stack, &font,4);
	pop(stack,&font);
	push(stack, &font,5);
	pop(stack,&font);
	pop(stack,&font);
*/

	//queue_linklist
	/*
	Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	deQueue(q);
	deQueue(q);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	enQueue(q, 60);
	deQueue(q);
	printf("Queue Front : %d \n", q->font->data);
	printf("Queue Rear : %d\n", q->rear->data);
*/
	//stack_linklist
	/*
	Stack* root = createStack();

	push(root, 10);
	push(root, 20);
	push(root, 30);

	printf("%d popped from stack\n", pop(root));
*/

	/*
	char str[] = "abcde";
	reverse(str);
	printf("Reversed string is: %s\n", str);
*/

	/*
	int price[] = { 10, 4, 5, 90, 120, 80,85};

	int n = sizeof(price) / sizeof(price[0]);
	int span[n] = {0};
	calculateSpan(price, n, span);

	int arr[] = { 8, 1, 7, 6, 0 };
	int size = sizeof(arr) / sizeof(arr[0]);
	findMaxMultupleOf3(arr, size)
*/

	return 0;
}
