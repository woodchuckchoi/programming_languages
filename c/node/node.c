#include "node.h"
#include <stdlib.h>
#ifndef MYNODE
#include <stdio.h>
#endif
/*
struct Node {
	int data;
	Node *before;
	Node *after;
}
*/

struct Node createNode(int data) {
	struct Node node;
	node.data = data;
	node.before = NULL;
	node.after = NULL;
	return node;
}

void prependNode(struct Node *node, int data) {
	node->before = (struct Node *)malloc(sizeof(struct Node));
	(node->before)->data = data;
	(node->before)->after = node;
}

void appendNode(struct Node *node, int data) {
	node->after = (struct Node *)malloc(sizeof(struct Node));
	(node->after)->data = data;
	(node->after)->before = node;
}

void deleteNode(struct Node *node) {
	if (node->before) {
		if (node->after) {
			(node->before)->after = node->after;
		} else {
			(node->before)->after = NULL;
		}
	}
	if (node->after) {
		printf("%d Node is being dereferenced from %d Node\n", node->data, (node->after)->data);
		(node->after)->before = NULL;
	}
	printf("%d Node will be deleted\n", node->data);  
	free(node);
}

void deleteAll(struct Node *node) {
	struct Node *previous = node->before;
	struct Node *next = node->after;
	while (1) {
		if (previous == NULL) {
			break;
		}
		struct Node *todelete = previous->before;
		printf("%d Node will be deleted\n", previous->data);
		free(previous);
		previous = todelete;
	}
	while (1) {
		if (next == NULL) {
			break;
		}
		struct Node *todelete = next->after;
		printf("%d Node will be deleted\n", next->data);
		free(next);
		next = todelete;
	}
}

