#ifndef LLIST_STACK_H
#define LLIST_STACK_H
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 5

struct SNode{
	int data;
	SNode *next;
};

struct Stack{
	SNode * top;
};

SNode *createSNode(int new_data){
	SNode *new_node = (SNode*)malloc(sizeof (SNode));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

Stack *createStack(){
	Stack* s = (Stack*)malloc(sizeof (Stack));
	s->top = NULL;
	return s;
};

bool isEmpty(Stack * root)
{
	//return !root;
	if (root == NULL){
		return true;
	}
	else
		return false;
}

void push(Stack *s, int newdata){
	struct SNode* temp = createSNode(newdata);
	temp->next = s->top;
	s->top= temp;
}

int pop(Stack * s){
	if (isEmpty(s)){
		return INT_MIN;
	}
	SNode * temp = s->top;
	s->top = s->top->next;
	int popped = temp->data;
	free(temp);
	return popped;
}
int peek(Stack* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->top->data;
}

void reverse( char *str){
	Stack *s = createStack();
	int n = strlen(str);
	for(int i = 0; i < n;i++){
		push(s, str[i]);
	}

	for(int i = 0; i < n; i++){
		str[i] = pop(s);
	}
}
bool isFull(Stack *s){

	if (s->top != NULL) {
		return true;
	}
	return false;
}

void calculateSpan(int price[], int n, int span[]){
	Stack *s = createStack();
	Stack *temp = createStack();
	int count = 1;
	span[0] = 1;
	push(s, price[0]);

	for(int i = 1; i < n; i++){
		count = 1;
		while (isFull(s) && price[peek(s)] <= price[i]){
			push(temp,pop(s));
			count++;
		}
		while (isFull(s)){
			push(s,pop(temp));
		}
		push(s,price[i]);
		printf("bbbbb\n");
		span[i] = count;
		printf("%d\n", span[i]);
	}
}


#endif // LLIST_STACK_H
