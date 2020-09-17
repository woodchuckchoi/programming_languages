#include <stdio.h>
#include <stdlib.h>
#define MYNODE
#include "node.h"

/*
struct Node createNode(int data);
void prependNode(struct Node (*), int data);
void appendNode(struct Node (*), int data);
void deleteNode(struct Node (*));
void deleteAll(struct Node (*));
*/

int main() {
	struct Node head = createNode(1);
	printf("prepending the first node\n");
	prependNode(&head, 0);
	printf("appending the second node\n");
	appendNode(&head, 2);
	printf("deleting the first node\n");
	deleteNode(head.before);
	printf("deleting all nodes\n");
	deleteAll(&head);
	printf("finished\n");
	return 0;
}
