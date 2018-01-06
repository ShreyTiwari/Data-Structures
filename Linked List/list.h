#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct BE
{
	struct node *head;
	//struct node *tail;
};

void insert_e(struct BE *list, int data);
void insert_b(struct BE *list, int data);
void insert_m(struct BE *list, int data, int index);
void remove_b(struct BE *list);
void remove_m(struct BE *list, int data);
void remove_e(struct BE *list);
void display(struct BE *list);
void deleteList(struct BE *list);
void reverse(struct BE *list);