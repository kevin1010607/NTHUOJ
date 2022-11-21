typedef struct node {
	struct node* next;
	int val;
} Node;
void createLinkedList(Node **head, int N, int *arr);
void swapTwoSegment(Node **head, int N, int a, int b, int len);