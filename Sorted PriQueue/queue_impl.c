#include"queue.h"

void initialize(struct queue *q)
{
	q->head = NULL;
}

void display(struct queue *q)
{
	if(q->head == NULL)
		return;
	else
	{
		struct node *temp = q->head;
		while(temp!=NULL)
		{
			printf("%d   ",temp->data);
			temp = temp->link;
		}
	}
	printf("\n");
}

int delete(struct queue *q)
{
	int x;
	struct node *temp;
	if(q->head == NULL)
		return -1;
	else if(q->head->link == NULL)
	{
		x = q->head->data;
		free(q->head);
		q->head = NULL;
	}
	else
	{
		x = q->head->data;
		temp = q->head;
		q->head = q->head->link;
		free(temp);
	}
	return x;
}

void insert(struct queue *q, int data, int priority)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->priority = priority;
	temp->link = NULL;

	if(q->head == NULL)
	{
		q->head = temp;	
	}
	
	else if(q->head->priority < priority)
	{
		temp->link = q->head;
		q->head = temp;
	}
	else
	{
		struct node *p = q->head;
		while(p->link!=NULL)
		{
			if(p->link->priority< priority)
				break;
			p = p->link;
		}
		temp->link = p->link;
		p->link = temp;
	}
}