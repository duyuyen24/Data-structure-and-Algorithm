#include <iostream>
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

//#include"singlyLL.h"
//#include"circularLL.h"
#include"doublyLL.h"
using namespace std;

int main()
{
	//linklist
/*
	Node *head = NULL;

	//reverse(head);
	printNode(head);

	addHead(&head, 1);
	addHead(&head, 5);
	addHead(&head, 3);
	addHead(&head, 4);
	addHead(&head, 6);

	Node *head2 = NULL;
	addHead(&head2, 6);
	addHead(&head2, 7);
	addHead(&head2, 8);
	*/
/*
	//delNode(&head, 1);
	//delPosNode(&head, 1);
	printf("Length of linkedList: %d\n",length(head));
	//printf("\n Deleting linked list:\n");
	//delList(&head);
	reverse(head);
	printNode(head);
	search(head, 21)? printf("Yes\n") : printf("No\n");
	printf("Element at index 3 is %d\n", getDataPos(head, 3));
	PrintnNthodetoEnd(head, 1);
	printMidNode(head);
	printf("Count of 1 is %d\n", countNodetime(head, 1));

	head->next->next->next->next = head;
	if (detLoop(head))
		cout << "Loop found\n";
	else
		cout << "No Loop\n";

	struct Node *h = newNode(1);
	h->next = newNode(2);
	h->next->next = newNode(3);
	h->next->next->next = newNode(4);
	h->next->next->next->next = newNode(5);
	h->next->next->next->next->next = h->next;

	printf("Length Of Loop Node: %d \n", lengthOfLoopN(h));

	moveLast(&head);
	printf("\n Linked list after removing last to front\n");
	printNode(head);


	swapPosNode(&head, 4, 3);
	printf("\nLinked list after calling swapNode() \n");
	printNode(head);

	swapNode(&head, 4, 3);
	printf("\nLinked list after calling swapNode() \n");
	printNode(head);
*/
//	int res = PosKfromMid(head, 1);
//	printf("\nLinked list after calling PosKfromMid(): %d\n", res);

	//Node* result = merge2Node(head, head2);
	//head = mergeSort(head);

//	printf("Sorted Linked List is: \n");
//	printNode(head);
	//circular
	/*
	struct Node *head = NULL;

	addToEmpty(&head, 6);
	addBegin(&head, 4);
	addBegin(&head, 2);
	addEnd(&head, 8);
	addEnd(&head, 12);
	addAfter(&head, 10, 8);
	printNode(head);

	Node* h = newNode(1);
	h->next = newNode(2);
	h->next->next = newNode(3);
	h->next->next->next = newNode(4);

	isCircular(h)? printf("Yes\n") : printf("No\n");

	head = exchangeNodes(head); //swap first and last node
	printNode(head);

	deleteNode(head,8);
	printNode(head);
	printf("Numbers of nodes: %d\n", countNodes(head));
*/

	//doubly

	Node* head = NULL;

	addLast(&head, 6);
	addHead(&head, 7);
	addHead(&head, 1);
	addLast(&head, 4);
	addLast(&head, 4);
	addAfter(head->next, 8);

	printf("Created DLL is: \n");
	printNode(head);

	deleteFirst(&head, head);//delete first node
	reverse(&head);
	printf("\nReversed Linked list \n");
	printNode(head);

	removeDuplicates(&head);
	printf("\nDoubly linked list after removing duplicates\n");
	printNode(head);
	head = mergeSort(head);
	//quickSort(head);
	printf("Sorted Linked List is: \n");
	printNode(head);

	return 0;
}
