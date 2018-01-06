#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct tree
{
    struct node *root;
};

struct stack
{
    struct node *array[100];
    int top;
};

struct stack1
{
    int array[100];
    int top;
};

void initialize(struct tree *t);

struct node* buildTree(char c[]);

void infix(struct tree *t);
void postfix(struct tree *t);
void prefix(struct tree *t);

int evaluate(char c[]);