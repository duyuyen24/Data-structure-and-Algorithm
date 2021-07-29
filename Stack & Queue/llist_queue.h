#ifndef LLIST_QUEUE_H
#define LLIST_QUEUE_H
#include <stdlib.h>
#include<stdio.h>

struct QNode{
	int data;
	struct QNode * next;
};

struct Queue{
	QNode * font , *rear;
};

QNode *createQNode(int new_data){
	QNode *new_node = (QNode*)malloc(sizeof (QNode));
	new_node->data = new_data;
	new_node->next = NULL;
	return new_node;
}

Queue *createQueue(int size){
	Queue* q = (Queue*)malloc(sizeof (size));
	q->font = q->rear = NULL;
	return q;
};

void enQueue(Queue *q, int newdata){
	QNode *temp = createQNode(newdata);
	if(q->rear == NULL){ // queue empty
		q->font = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

int deQueue(Queue *q){
	if(q->font == NULL){ //queue empty
		return 0;
	}
	QNode *temp = q->font;
	q->font = q->font->next;
	if(q->font == NULL){
		q->rear = NULL;
	}
	return temp->data;
}
int isEmpty(Queue *q){
	return q->font->data == -1;
}

/*
void populateAux(int* aux, Queue* queue0, Queue* queue1, Queue* queue2, int* top)
{
	while (!isEmpty(queue0))
		aux[(*top)++] = deQueue(queue0);

	while (!isEmpty(queue1))
		aux[(*top)++] = deQueue(queue1);

	while (!isEmpty(queue2))
		aux[(*top)++] = deQueue(queue2);
}

int compareAsc(const void* a, const void* b)
{
	return *(int*)a > *(int*)b;
}
int compareDesc(const void* a, const void* b)
{
	return *(int*)a < *(int*)b;
}
int findMaxMultupleOf3(int* arr, int size)
{
	qsort(arr, size, sizeof(int), compareAsc);

	Queue* queue0 = createQueue(size);
	Queue* queue1 = createQueue(size);
	Queue* queue2 = createQueue(size);

	int sum = 0;
	for (int i = 0, sum = 0; i < size; ++i) {
		sum += arr[i];
		if ((arr[i] % 3) == 0)
			enQueue(queue0, arr[i]);
		else if ((arr[i] % 3) == 1)
			enQueue(queue1, arr[i]);
		else
			enQueue(queue2, arr[i]);
	}

	if ((sum % 3) == 1) {
		if (!isEmpty(queue1)){
			deQueue(queue1);
		}
		else {
			if (!isEmpty(queue2))
				deQueue(queue2);
			else
				return 0;

			if (!isEmpty(queue2))
				deQueue(queue2);
			else
				return 0;
		}
	}
	else if ((sum % 3) == 2) {
		if (!isEmpty(queue2))
			deQueue(queue2);
		else {
			if (!isEmpty(queue1))
				deQueue(queue1);
			else
				return 0;

			if (!isEmpty(queue1))
				deQueue(queue1);
			else
				return 0;
		}
	}

	int aux[size], top = 0;

	populateAux(aux, queue0, queue1, queue2, &top);

	qsort(aux, top, sizeof(int), compareDesc);


	for (int i = 0; i < top; ++i){
		printf("%d ", aux[i]);
	}
	printf("\n");
	return top;
}

*/
#endif // LLIST_QUEUE_H
