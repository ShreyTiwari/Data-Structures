#include"list.h"
#include<stdlib.h>

void insert(struct List *list, int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(list->head == NULL)
	{
			list->head = temp;
			return;
	}

	if(list->head->data > data)
	{
		temp->next = list->head;
		list->head = temp;
	}

	else
	{
		struct node *x;
		x = list->head;
		while(x->next != NULL && x->next->data<data)
		{
			x = x->next;
		}
		temp->next = x->next;
		x->next = temp;
	}
}

void display(struct List *list)
{
	struct node *temp = list->head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void deleteList(struct List *list)
{
	struct node *temp;
	do
	{
		temp = list->head;
		list->head = temp->next;
		free(temp);
	}while(list->head != NULL);
}

void merge(struct List *list1, struct List *list2, struct List *list3)
{
	struct node *temp = list1->head;
	while(temp!=NULL)
	{
		insert(list3, temp->data);
		temp = temp->next;
	}

	temp = list2->head;
	while(temp!=NULL)
	{
		insert(list3, temp->data);
		temp = temp->next;
	}
}
