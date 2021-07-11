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
#include"doublyLL.h"
using namespace std;


int main(){d
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
