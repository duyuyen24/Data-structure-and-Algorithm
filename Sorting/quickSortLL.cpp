#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	int priority;
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int value, int prior);// push new node
void printList(struct Node *node) ;// print list node
void quickSort(struct Node **headRef) ;

int main() {
	struct Node *head = NULL;
	int i;
	srand(time(NULL));
	for (i = 1; i <= 50; i++){
		int priorityRandom = rand() % 8 + 1;//random priority in range from 1 to 8
		push(&head, i, priorityRandom);
	}
	printf("Linked List before sorting: \n");
	printList(head);

	quickSort(&head);

	printf("Linked List after sorting: \n");
	printList(head);

	return 0;
}

void push(struct Node** head_ref, int value, int prior) {
	struct Node* new_node = (struct Node *) malloc(sizeof(struct Node));
	new_node->priority  = prior;
	new_node->data = value;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void printList(struct Node *node) {
	printf("priority : data \n");
	while (node != NULL) {
		printf("%d : %d \n", node->priority, node->data);
		node = node->next;
	}
	printf("\n");
}

struct Node *getTail(struct Node *cur) {
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}

struct Node *partition(struct Node *head, struct Node *end, struct Node **newHead, struct Node **newEnd) {
	struct Node *pivot = end;
	struct Node *prev = NULL, *cur = head, *tail = pivot;

	while (cur != pivot) {
		if (cur->priority < pivot->priority) {
			if ((*newHead) == NULL)
				(*newHead) = cur;

			prev = cur;
			cur = cur->next;
		}else{
			if (prev)
				prev->next = cur->next;
			struct Node *tmp = cur->next;
			cur->next = NULL;
			tail->next = cur;
			tail = cur;
			cur = tmp;
		}
	}
	if ((*newHead) == NULL)
		(*newHead) = pivot;

	(*newEnd) = tail;

	return pivot;
}

struct Node *quickSortRecur(struct Node *head, struct Node *end) {
	if (!head || head == end)
		return head;

	Node *newHead = NULL, *newEnd = NULL;

	struct Node *pivot = partition(head, end, &newHead, &newEnd);

	if (newHead != pivot) {
		struct Node *tmp = newHead;
		while (tmp->next != pivot)
			tmp = tmp->next;
		tmp->next = NULL;

		newHead = quickSortRecur(newHead, tmp);

		tmp = getTail(newHead);
		tmp->next =  pivot;
	}
	pivot->next = quickSortRecur(pivot->next, newEnd);

	return newHead;
}

void quickSort(struct Node **headRef) {
	(*headRef) = quickSortRecur(*headRef, getTail(*headRef));
	return;
}
