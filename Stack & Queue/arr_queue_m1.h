#include <stdio.h>
#define LIMIT 5
void insert(int queue[], int head, int tail, int element)
{
	if (tail == LIMIT - 1)
		printf("Queue Overflow\n");
	else{
		if (head == - 1)
			head = 0;
		tail++;
		queue[head] = element;
		printf("Add element: %d\n", element);
	}
}

void delet(int queue[],int font, int rear)
{
	int element = queue[font];
	if (font == - 1 || font > rear)
	{
		printf("Queue Underflow \n");
	}
	else
	{
		font++;
		printf("The deleted element in the queue is: %d\n", element);
	}
}

