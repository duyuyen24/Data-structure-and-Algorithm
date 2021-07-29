#include <stdlib.h>
#include<stdio.h>
#include<assert.h>
struct Node{
	int data;
	struct Node *next;
	int flag;
};

void setData(Node * node, int Data){
	node->data = Data;
}

int getData(Node * node){
	return node->data;
}

int getDataPos(Node *head, int pos){
	int count = 0;
	Node *cur = head;
	while(cur != NULL){
		if(count == pos){
			return cur->data;
		}
		count++;
		cur = cur->next;
	}
}

void printNode(Node * node){
	while(node != NULL){
		printf("%d\n", node->data);
		node = node->next;
	}
}
struct Node *newNode(int key)
{
	struct Node *temp =(struct Node*)malloc(sizeof(struct Node));
	temp->data = key;
	temp->next = NULL;
	return temp;
}
void addHead(Node **head, int new_data){
	Node *new_node = (Node*)malloc(sizeof (Node));
	new_node->data = new_data;
	new_node->next = *head;
	new_node->flag = 0;
	*head = new_node;
}

void addTail(Node **head, int new_data){
	Node *new_node = (Node*)malloc(sizeof (Node));
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head == NULL){
		*head = new_node;
	}else{
		Node *last_node = *head;
		while(last_node->next != NULL){
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
}

int length(Node *head){
	int count = 0;
	Node *cur = head;
	while(cur != NULL){
		count++;
		cur = cur->next;
	}
	return count;
}

void delNode(Node **head, int del_data){
	Node *temp = (Node*)malloc(sizeof (Node));
	Node *prev = NULL;
	temp = *head;
	if(temp != NULL && temp->data == del_data){
		*head = temp->next;
		free(temp);
		return;
	}
	while (temp != NULL && temp->data != del_data) {
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	prev->next = temp->next;
	free(temp);

}

void delPosNode(Node **head, int del_pos){
	Node *temp = (Node*)malloc(sizeof (Node));
	temp = *head;
	if(del_pos == 0){
		*head = temp->next;
		free(temp);
		return;
	}
	for(int i = 0; temp != NULL && i< del_pos - 1; i++){
		temp = temp->next;
	}
	if (temp == NULL || temp->next == NULL)
		return;
	Node *next = temp->next->next;
	free(temp->next);
	temp->next = next;

}

void delList(Node **head){
	Node *current = (Node*)malloc(sizeof (Node));
	Node *next = NULL;

	current = *head;
	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

bool search(Node *head, int index){
	Node *cur = head;
	while(cur != NULL){
		if(cur->data == index){
			return true;
		}
		cur = cur->next;
	}
	return false;
}

Node *reverse(Node *head){
	Node *cur = head;
	Node *prev = NULL;
	Node *next = NULL;

	while(cur != NULL){
		next = cur->next;
		cur->next = prev;

		prev = cur;
		cur = next;
	}
	return prev;
}

void PrintnNthodetoEnd(Node *head, int pos){
	int len = 0;

	Node *temp = head;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}
	if(len < pos){
		return;
	}
	temp = head;
	for(int i = 1; i < len - pos + 1; i++){
		temp = temp->next;
	}
	printf("Number of count: %d\n", temp->data);
}

void printMidNode(Node *head){
	int len = 0;
	Node *temp = head;
	while (temp != NULL) {
		temp = temp->next;
		len++;
	}

	temp = head;
	for(int i = 1; i < len/2 + 1; i++){
		temp = temp->next;
	}
	printf("Data of node mid: %d\n", temp->data);
}

int countNodetime(Node *head, int index){
	Node *cur = head;
	int count = 0;
	while (cur != NULL) {
		if(cur->data == index){
			count++;
		}
		cur = cur->next;
	}
	return count;
}

int countNodes(Node *head){
	int res = 1;
	Node *temp = head;
	while (temp->next != head)
	{
		res++;
		temp = temp->next;
	}
	return res;
}
bool detLoop(Node *head){
	Node *cur = head;
	while (cur != NULL) {
		if(cur->flag == 1)
			return true;
		cur->flag = 1;
		cur = cur->next;
	}
	return false;
}

int lengthOfLoopN(Node *list){
	Node  *ones_p = list;
	Node *twos_p = list;

	while (ones_p && twos_p && twos_p->next)
	{
		ones_p = ones_p->next;
		twos_p  = twos_p->next->next;

		if (ones_p == twos_p)
			return countNodes(ones_p);
	}
}

void moveLast(Node **head){
	if(*head == NULL || (*head)->next == NULL ){
		return;
	}
	Node *seclast = NULL;
	Node *last = *head;

	while(last->next != NULL){
		seclast = last;
		last = last->next;
	}

	seclast->next = NULL;
	last->next = *head;
	*head = last;
}

void swapNode(Node **head, int x, int y){
	if (x == y)
		return;

	Node *prevX = NULL, *currX = *head;
	while (currX && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}

	Node *prevY = NULL, *currY = *head;
	while (currY && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}

	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else
		*head = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else
		*head = currX;

	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

Node* removeDuplicates(Node *head){
	Node *t = head;
	while(t->next != NULL){
		if(t->data == t->next->data){
			t->next = t->next->next;
		}
		else{
			t = t->next;
		}
	}
	return head;
}

void swapPosNode(Node **head, int x, int y){
	if (x == y)
		return;
	int b = 0;
	int c = 0;
	Node *t= *head;
	Node *prevX = NULL, *currX = *head;
	Node *prevY = NULL, *currY = *head;

	int i = 0;
	while(t != NULL){
		if(i == x){
			b = getData(t);
		}else if(i == y){
			c = getData(t);
		}
		i++;
		t = t->next;
	}

	while (currX && currX->data != b) {
		prevX = currX;
		currX = currX->next;
	}

	while (currY && currY->data != c) {
		prevY = currY;
		currY = currY->next;
	}
	if (currX == NULL || currY == NULL)
		return;

	if (prevX != NULL)
		prevX->next = currY;
	else
		*head = currY;

	if (prevY != NULL)
		prevY->next = currX;
	else
		*head = currX;

	Node* temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}

int PosKfromMid(Node *head, int B){
	Node *current = head;
	int n = length(head);
	int count = 0, ans = 0;

	int mid = ((n + 1) / 2) - B;
	if(mid <= 0){
		ans = -1;
	}
	while (current != NULL)
	{
		if (count == mid)
		{
			ans = current->data;
			break;
		}
		count++;
		current = current->next;
	}

	return ans;
}
Node* merge2Node(Node *l1, Node *l2){
	if(!l1) {
		return l2; // ktra l1 ton tai
	}
	if(!l2) {
		return l1;
	}

	Node* head = l1;
	if(l1->data > l2->data){ //ktra phan tu trong node1 va node2 roi gan head bang node lon
		head = l2;
		l2 = l2->next;
	} else{
		l1 = l1->next;
	}

	Node* curr = head;
	while(l1 && l2){ //sort and merge vao curr
		if(l1->data < l2->data){
			curr->next = l1;
			l1 = l1->next;
		} else {
			curr->next = l2;
			l2 = l2->next;
		}
		curr = curr->next;
	}
	if(!l1){
		curr->next = l2;
	}else{
		curr->next = l1;
	}

	return head;

}

Node *getnodeMid(Node *h){
	Node *slow = h;
	Node *fast = h;

	while (fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int lPalin(Node* head) {
	Node *mid = getnodeMid(head);
	Node *temp = mid->next;
	mid->next = NULL;
	temp = reverse(temp);
	while(temp && head){
		if(head->data != temp->data){
			return 0;
		}
		temp = temp->next;
		head = head->next;
	}
	return 1;

}
Node* detectCycle(Node* root) {
	if(!root){
		return NULL;
	}

	Node *slow = root, *fast=root;

	while(fast && fast->next && slow)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			break;
		}
	}
	if(slow!= fast){
		return NULL;
	}

	if(!fast){
		return NULL;
	}
	fast = root;
	while (fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

Node* getTail(struct Node* cur)
{
	while (cur != NULL && cur->next != NULL)
		cur = cur->next;
	return cur;
}


Node* merge(Node* a, Node* b){
	Node *new_list = NULL;
	Node *tail = NULL;
	while (a != NULL && b != NULL) {
		Node * next_node = NULL;
		if(a->data <= b->data){
			next_node = a;
			a = a->next;
		} else {
			next_node = b;
			b = b->next;
		}

		if(tail != NULL){
			tail->next = next_node;
		} else {
			new_list = next_node;
			tail = next_node;
		}
		tail = tail->next;
	}
	if(a != NULL){
		tail->next = a;
	} else {
		tail->next = b;
	}
	return new_list;
}

Node* mergeSort(Node *head){
	if (head == NULL && head->next == NULL){
		return head;
	}
	Node *mid = getnodeMid(head);
	Node *left_l = head;
	Node *right_l = mid->next;
	mid->next = NULL;

	left_l = mergeSort(left_l);
	right_l = mergeSort(right_l);

	return merge(left_l, right_l);
}

Node *removeDublicatesSorted(Node* A){
	Node *dummyhead=(Node*)malloc(sizeof(Node));
	dummyhead->data = 0;
	dummyhead->next = A;
	Node *prev = dummyhead;
	while(A!=NULL){
		if(A->next != NULL && A->next->data == A->data){
			while(A->next != NULL && A->next->data == A->data){
				Node *temp = A->next;
				A->next = temp->next;
				free(temp);
			}
			Node *r = A;
			prev->next = r->next;
			A=A->next;
			free(r);
		}else{
			prev = A;
			A = A->next;
		}
	}
	return dummyhead->next;
}
