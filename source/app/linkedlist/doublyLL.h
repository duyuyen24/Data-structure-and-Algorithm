#ifndef DOUBLYLL_H
#define DOUBLYLL_H
#include <stdlib.h>
#include<stdio.h>
#include<assert.h>

struct Node {
	int data;
	struct Node* next; // Pointer to next node in DLL
	struct Node* prev; // Pointer to previous node in DLL
};


void addHead( Node** head, int new_data){
	Node* new_node = ( Node*)malloc(sizeof(Node));

	new_node->data = new_data;

	new_node->next = (*head);
	new_node->prev = NULL;

	if ((*head) != NULL)
		(*head)->prev = new_node;

	(*head) = new_node;
}

void addAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

void addLast( Node** head, int new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node *last = *head;

	new_node->data = new_data;
	new_node->next = NULL;

	if (*head == NULL) {
		new_node->prev = NULL;
		*head = new_node;
		return;
	}
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	new_node->prev = last;
	return;
}

void printNode(Node * node){
	Node* last;
	while(node != NULL){
		printf("%d\n", node->data);
		last = node;
		node = node->next;
	}
}

void deleteFirst(Node **head, Node *del){
	if (*head == NULL || del == NULL)
		return;

	if (*head == del)
		*head = del->next;

	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
	return;
}
void deleteNode(Node *head, Node *t){
	if (t == head){
		return;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);
}

void reverse(Node **head){
	Node *temp = NULL;
	Node *cur = *head;
	while (cur != NULL) {
		temp = cur->prev;
		cur->prev = cur->next;
		cur->next = temp;
		cur = cur->prev;
	}
	if(temp != NULL ){
		*head= temp->prev;
	}
}

int findSize(Node *node){
	int res = 0;
	while (node != NULL){
		res++;
		node = node->next;
	}
	return res;
}

void removeDuplicates(Node** head){
	if ((*head) == NULL ||(*head)->next == NULL){
		return;
	}
	Node* temp1, *temp2;
	temp1 = *head;

	while( temp1 != NULL) {
		temp2 = temp1->next;
		while (temp2 != NULL) {
			if (temp1->data == temp2->data) {
				Node* next = temp2->next;
				deleteNode(head, temp2);
				temp2 = next;
			}else{
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}
}

void swap ( int* a, int* b ){
	int t = *a;
	*a = *b;
	*b = t;
}

Node *lastNode(Node *root){
	while (root && root->next){
		root = root->next;
	}
	return root;
}

Node* partition(Node *l, Node *h){
	int x = h->data;
	Node *i = l->prev;

	for ( Node *j = l; j != h; j = j->next){
		if (j->data <= x){
			//i++
			i = (i == NULL) ? l : i->next;
			swap(&(i->data), &(j->data));
		}
	}
	//i++
	i = (i == NULL) ? l : i->next;
	swap(&(i->data), &(h->data));
	return i;
}
void _quickSort(struct Node* l, struct Node *h){
	if (h != NULL && l != h && l != h->next){
		struct Node *p = partition(l, h);
		_quickSort(l, p->prev);
		_quickSort(p->next, h);
	}
}
void quickSort(Node *head){
	Node *h = lastNode(head);
	_quickSort(head, h);
}

Node *split(Node *head){
	Node *fast = head,*slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	Node *temp = slow->next;
	slow->next = NULL;
	return temp;
}

Node *merge(Node *first, Node *second){
	if (!first)
		return second;

	if (!second)
		return first;

	if (first->data < second->data)
	{
		first->next = merge(first->next,second);
		first->next->prev = first;
		first->prev = NULL;
		return first;
	}
	else
	{
		second->next = merge(first,second->next);
		second->next->prev = second;
		second->prev = NULL;
		return second;
	}
}

Node *mergeSort(Node *head){
	if (!head || !head->next)
		return head;
	Node *second = split(head);

	head = mergeSort(head);
	second = mergeSort(second);

	return merge(head,second);
}
#endif // DOUBLYLL_H
