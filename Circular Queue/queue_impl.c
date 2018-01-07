#include"queue.h"

void display(struct queue *q)
{
	if(q->front == q->rear)
	{
		printf("The queue is empty.");
		return;
	}
	else
	{
		int i = (q->front+1)%max;
		while(i!=q->rear)
		{
			printf("%d	",q->array[i]);
			i = (i+1)%max;
		}
		printf("%d", q->array[i]);
	}
}

void initialize(struct queue *q)
{
	q->front = q->rear = max-1;
}

void enqueue(struct queue *q, int data)
{
	if((q->rear+1)%max == q->front)
	{
		printf("The queue is full.");
		return;
	}
	else
	{
		q->rear = (q->rear+1)%max;
		q->array[q->rear] = data;
	}
}

int dequeue(struct queue *q)
{
	if(q->front == q->rear)
	{
		printf("\nThe queue is empty.\n");
		return -1;
	}
	
	else
	{
		q->front = (q->front+1)%max;
		return(q->array[q->front]);
	}
}