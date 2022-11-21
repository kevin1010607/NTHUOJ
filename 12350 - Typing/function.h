#include<stdio.h>
#include<stdlib.h>
typedef struct _NODE
{
	char character;
	struct _NODE *ptr_to_next_node;
	struct _NODE *ptr_to_prev_node;
} Node;


void insert(Node**, char);

void deletion(Node**);

void backspace(Node**);

void go_left(Node**, int);

void go_right(Node**, int);

void go_home(Node**);

void go_end(Node**);

void show();