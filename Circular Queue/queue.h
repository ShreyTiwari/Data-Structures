#include<stdio.h>
#define max 10

struct queue
{
	int array[max];
	int front;
	int rear;
};

void display(struct queue *q);
int dequeue(struct queue *q);
void enqueue(struct queue *q, int data);
void initialize(struct queue *q);
