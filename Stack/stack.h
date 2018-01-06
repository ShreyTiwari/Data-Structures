#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MS 20

struct Stack
{
	char a[MS];
	int sp;
};

void initialize(struct Stack *stack);
char peek(struct Stack *stack);
void push(struct Stack *stack, int data);
char pop(struct Stack *stack);
void display(struct Stack *stack);
void inspect(struct Stack *stack);
int precedence(char c);
void postfix(struct Stack *stack);

