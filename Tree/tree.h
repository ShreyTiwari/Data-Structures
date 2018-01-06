#include<stdio.h>
#include<stdlib.h>

struct node
{	
	int data;
	struct node *left;
	struct node *right;
};

struct tree
{
	struct node *root;
};

void initialize(struct tree *t);
void inOrder(struct tree *t);
void inOrderPrint(struct node *x);
void preOrder(struct tree *t);
void preOrderPrint(struct node *x);
void postOrder(struct tree *t);
void postOrderPrint(struct node *x);
void insert(struct tree *t, int data);
void insertAt(struct node *temp, int data);
void limits(struct tree *t);
void search(struct tree *t, int data);
int leaves(struct tree *t);
int nodes(struct tree *t);
void delete(struct tree *t, int data);
struct node* rdelete(struct node *root, int data);