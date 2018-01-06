#include"list.h"
#include<stdlib.h>


void initialize(struct List *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->non = 0;
}

void insert_b(struct List *list, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->llink = NULL;
	temp->rlink = NULL;
	temp->data = data;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}

	else
	{
		temp->rlink = list->head;
		list->head->llink = temp;
		list->head = temp;
	}
	++list->non;
}

void display(struct List *list)
{
	struct node *temp = list->head;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->rlink;
	}
	print("\n");
}

void insert_e(struct List *list, int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->llink = NULL;
	temp->rlink = NULL;
	temp->data = data;

	if(list->head == NULL)
	{
		list->head = temp;
		list->tail = temp;
	}
	
	else
	{
		list->tail->rlink = temp;
		temp->llink = list->tail;
		list->tail = temp;
	}
	++list->non;
}


void insert_m(struct List *list, int data, int position)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->llink = NULL;
	temp->rlink = NULL;
	if(list->head == NULL)
	{
		printf("The List is empty. Element inserted as the first node.\n");
		list->head = temp;
		list->tail = temp;
		return;
	}	

	if(position == 0)
	{
		temp->rlink = list->head;
		list->head->llink = temp;
		list->head = temp;
	}

	else
	{
		if(position >= list->non)
		{
			list->tail->rlink = temp;
			temp->llink = list->tail;
			list->tail = temp;
			return;
		}

		int i=1;
		struct node *x = list->head;

		for(;(i<position);++i)
		{
			x = x->rlink;
		}
		temp->rlink = x->rlink; 
		x->rlink->llink = temp;
		temp->llink = x; 
		x->rlink = temp;
	}
	list->non++;
}


void remove_b(struct List *list)
{
	if(list->head == NULL)
		return;
	else if((list->head)->rlink == NULL)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->head = (list->head)->rlink;
		free(list->head->llink);
		list->head->llink = NULL;
	}
	--list->non;
}

void remove_e(struct List *list)
{
	if(list->head == NULL)
		return;
	else if((list->head)->rlink == NULL)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail = list->tail->llink;
		free(list->tail->rlink);
		list->tail->rlink = NULL;
	}
	list->non--;
}

void remove_m(struct List *list, int data)
{
	if(list->head == NULL)
		return;
	else if(list->head->data == data && list->head->rlink == NULL)
	{
		free(list->head);
		list->head = NULL;
		list->tail = NULL;
		list->non--;
	}

	else if(list->head->data == data)
	{
		list->head = list->head->rlink;
		free(list->head->llink);
		list->head->llink = NULL;
		list->non--;
	}

	else
	{
		if(list->tail->data == data)
		{
			list->tail = list->tail->llink;
			free(list->tail->rlink);
			list->tail->rlink = NULL;
		}

		int i=1;
		struct node *temp = list->head;
		for(;i<(list->non);++i)
		{
			if(temp->data == data)
			{
				temp = temp->llink;
				struct node *x = temp->rlink;
				temp->rlink = temp->rlink->rlink;
				temp->rlink->llink = temp;
				free(x);
				list->non--;
				return;
			}
			temp = temp->rlink;
		}		
	}
}