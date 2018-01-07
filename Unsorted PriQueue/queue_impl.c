#include"queue.h"

void initialize(struct queue *q)
{
	q->head = NULL;
}

void insert(struct queue *q, int data, int priority)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;	
	temp->priority = priority;

	if(q->head == NULL)
		q->head = temp;
	else
	{
		struct node *p = q->head;
		while(p->link != NULL)
			p = p->link;
		p->link = temp;
	}
}

void display(struct queue *q)
{
	if(q->head == NULL)
	{
		printf("\nThe queue is empty.\n");
		return;
	}
	else
	{
		printf("\n");
		struct node *temp = q->head;
		while(temp != NULL)
		{
			printf("%d	", temp->data);
			temp = temp->link;
		}
		printf("\n");
	}
}



void delete(struct queue *q)
{
	if(q->head == NULL)
	{
		printf("\nThe queue is empty.\n");
		return;
	}
	else
	{
		int max = q->head->priority;
		struct node *p = q->head;
		while(p != NULL)
		{
			if(p->priority > max)
				max = p->priority;
			p = p->link;
		}
		p = q->head;
		if(max == p->priority)
		{
			printf("\nThe element removed was : %d\n", p->data);
			q->head = p->link;
			free(p);
			return;
		}
		while(p->link != NULL && p->link->priority != max)
			p = p->link;
		struct node *x = p->link;
		p->link = p->link->link;
		printf("\nThe element removed was : %d\n", x->data);
		free(x);
		return;
	}
}