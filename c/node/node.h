struct Node {
	int data;
	struct Node *before;
	struct Node *after;
};

struct Node createNode(int data);
void prependNode(struct Node (*), int data);
void appendNode(struct Node (*), int data);
void deleteNode(struct Node (*));
void deleteAll(struct Node (*));
