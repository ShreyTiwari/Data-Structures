#include<stdio.h>

struct node
{
	struct node *llink;
	int data;
	struct node *rlink;
};

struct List
{
	struct node *head;
	struct node *tail;
	int non;
};

void insert_b(struct List *list, int data);
void initialize(struct List *list);
void insert_e(struct List *list, int data);
void insert_m(struct List *list, int data, int position);
void display(struct List *list);
void remove_b(struct List *list);
void remove_e(struct List *list);
void remove_m(struct List *list, int data);
