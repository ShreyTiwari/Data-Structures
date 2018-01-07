#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	int priority;
	struct node *link;
};

struct queue
{
	struct node *head;
};

void initialize(struct queue *q);
void insert(struct queue *q, int data, int priority);
void display(struct queue *q);
int delete(struct queue *q);
