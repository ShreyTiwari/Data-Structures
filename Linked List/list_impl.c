#include"list.h"
#include<stdio.h>
#include<stdlib.h>

void insert_e(struct BE *list, int data)
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
	else
	{
		struct node *x;
		x = list->head;
		while(x->next != NULL)
		{
			x = x->next;
		}
		x->next = temp;
	}
}


void insert_b(struct BE *list, int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	temp->next = list->head;
	list->head = temp;	

}


void remove_b(struct BE *list)
{
	if(list->head == NULL)
	{
		return;
	}
	struct node *temp = list->head;
	list->head = temp->next;
	free(temp);
}

void remove_m(struct BE *list, int data)
{
	if(list->head == NULL)
		return;
	if(list->head->data == data)
	{
		struct node *temp = list->head;
		list->head = temp->next;
		free(temp);
		return;	
	}
	else
	{
		struct node *temp = list->head;
		while(temp->next!=NULL && temp->next->data != data)
			temp = temp->next;
		if(temp->next == NULL)
			return;
		struct node *x = temp->next;
		temp->next = temp->next->next;
		free(x);
	}
}

void remove_e(struct BE *list)
{
	if(list->head == NULL)
		return;
	if(list->head->next == NULL)
	{
		free(list->head);
		list->head = NULL;
	}
	else
	{
		struct node *temp = list->head;
		while(temp->next->next!=NULL)
			temp = temp->next;
		free(temp->next);
		temp->next = NULL;
	}
}

void deleteList(struct BE *list)
{
	struct node *temp;
	while(list->head != NULL)
	{
		temp = list->head;
		list->head = temp->next;
		free(temp);
	}
}


void display(struct BE *list)
{
	struct node *temp = list->head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse(struct BE *list)
{
	if(list->head == NULL)
		return;
	struct node *pre = NULL, *cur, *nex;
	cur = list->head;
	while(cur!= NULL)
	{
		nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	list->head = pre;
}

void insert_m(struct BE *list, int data, int index)
{
	if(list->head == NULL)
	{
		printf("\nList is empty hence element entered is added as the first element.\n");
		insert_b(list, data);
	}
	else if(index == 1 && list->head != NULL)
		insert_b(list, data);
	else
	{
		struct node *temp = list->head;
		int i=2;
		for(;i<index && temp->next!=NULL ;i++)
		{
			temp = temp->next;
		}
		struct node *x = (struct node*)malloc(sizeof(struct node));
		x->data = data;
		x->next = temp->next;
		temp->next = x;
	}
}