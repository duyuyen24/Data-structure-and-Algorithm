#ifndef CIRCULARLL_H
#define CIRCULARLL_H

#include <stdlib.h>
#include<stdio.h>
#include<assert.h>
struct Node{
	int data;
	struct Node *next;
};

void addToEmpty(Node **last, int data)
{
	if (*last != NULL){
		return;
	}

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	*last = new_node->next;
	new_node->next = *last;

}

void addBegin(Node **last, int data)
{
	if (last == NULL)
		addToEmpty(last, data);

	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*last)->next;
	(*last)->next = new_node;
}

void addEnd(Node **last, int data)
{
	if (last == NULL)
		addToEmpty(last, data);
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = (*last)->next;
	(*last)->next = new_node;
	*last = new_node;

}

void addAfter(Node **last, int data, int item)
{
	if (*last == NULL)
		return;

	Node *new_node, *p;
	p = (*last) -> next;
	do{
		if (p ->data == item){
			new_node = (Node *)malloc(sizeof(Node));

			new_node -> data = data;
			new_node -> next = p -> next;
			p -> next = new_node;
			if (p == *last){
				*last = new_node;
			}
		}
		p = p -> next;
	} while (p != (*last) -> next);
}


void printNode(Node *head)
{
	Node *temp = head;
	if (head != NULL){
		do{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		while (temp != head);
	}
	printf("\n");
}

Node *newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

bool isCircular(Node *head)
{
	if (head == NULL)
		return true;

	struct Node *node = head->next;

	while (node != NULL && node != head)
		node = node->next;

	return (node == head);
}

void deleteNode(Node* head, int key)
{
	if (head == NULL)
		return;
	Node *curr = head;
	Node *prev = NULL;

	while (curr->data != key) {
		if (curr->next == head) {
			printf("\nGiven node is not found in the list!!!");
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if (curr->next == head) {
		head = NULL;
		free(curr);
		return;
	}

	if (curr == head) {
		prev = head;
		while (prev->next != head)
			prev = prev->next;
		head = curr->next;
		prev->next = head;
		free(curr);
	} else if (curr->next == head) {
		prev->next = head;
		free(curr);
	}else {
		prev->next = curr->next;
		free(curr);
	}

}

Node* exchangeNodes(Node* head)
{
	if (head->next->next == head) {
		head = head->next;
		return head;
	}

	Node* p = head;
	while (p->next->next != head)
		p = p->next;

	p->next->next = head->next;
	head->next = p->next;
	p->next = head;
	head = head->next;

	return head;
}

int countNodes( Node* head)
{
	Node* temp = head;
	int count = 0;
	if (head != NULL) {
		do {
			temp = temp->next;
			count++;
		} while (temp != head);
	}

	return count;
}
#endif // CIRCULARLL_H
