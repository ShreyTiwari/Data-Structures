#include<stdio.h>
#include<stdlib.h>

struct node
{
    int power;
    int coeff;
    struct node *link;
};

struct list
{
    struct node *head;
    int length;
};

void initialize(struct list *list);
void insert(struct list *list);
void add(struct list *list, int c, int p);