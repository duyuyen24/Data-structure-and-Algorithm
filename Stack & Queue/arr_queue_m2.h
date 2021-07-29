#include <sstream>
#include <iostream>
#include <stdio.h>
using namespace std;
#define LIMIT 5
bool isFull(int font, int rear)
{
	if((font == rear + 1)||(font == 0 && rear == LIMIT - 1)){
		return true;
	}
	return false;
}

void enqueue(int queue[], int *font, int *rear,int element)
{
	if(isFull(*font, *rear)){
		printf("Queue is full\n");
	}else{
		if(*font == -1){
			*font = 0;
		}
		*rear=(*rear+1)%LIMIT;//0
		queue[*rear] = element;
		//printf("Font: %d, rear: %d\n", font, rear);
		printf("Font: %d, rear: %d\n", *font, *rear);
		printf("Add element: %d\n",element);
	}
}

void dequeue(int queue[], int *font, int *rear){
	int element;
	if(*font == -1){
		printf("Queue is empty\n");
	}else{
		element = queue[*font];
		if(*font == *rear){
			*font = *rear = -1;
		}else{
			*font = (*font +1)%LIMIT;
		}
		printf("Del element: %d\n", element);
		//printf("Font: %d, rear: %d\n", font, rear);
		printf("Font: %d, rear: %d\n", *font, *rear);
	}
}

