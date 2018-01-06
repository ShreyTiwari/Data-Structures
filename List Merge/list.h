#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};

struct List
{
	struct node *head;
};

void insert(struct List *list, int data);
void diplay(struct List *list);
void merge(struct List *list1, struct List *list2, struct List *list3);
void deleteList(struct List *list);
