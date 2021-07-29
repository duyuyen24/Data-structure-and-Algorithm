#include<stdio.h>
#define LIMIT 5

bool isEmpty(int head){
	if(head == -1 ){
		return true;
	}
	return false;
}

bool isFull(int head){
	if(head == LIMIT){
		return true;
	}
	return false;
}

void push(int stack[], int *top, int element){
	printf("top: %d\n", *top);
	if(isFull(*top)){
		printf("Stack is full\n");
	}else{
		if(*top == -1){
			*top = 0;
		}
		stack[*top] = element;
		*top = *top+1;
		printf("Add element: %d\n", element);
	}
}

void pop(int stack[], int *top){
	int element;
	element = stack[*top-1];
	if(isEmpty(*top)){
		printf("Stack is empty\n");
	}else{
		*top = *top - 1;
		printf("Del element: %d\n", element);
	}
}

