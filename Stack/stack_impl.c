#include"stack.h"

void initialize(struct Stack *stack)
{
	stack->sp = -1;
}

char peek(struct Stack *stack)
{
	if(stack->sp == -1)
		return -1;
	else
		return(stack->a[stack->sp]);
}

void display(struct Stack *stack)
{
	if(stack->sp == -1)
		return;
	else
	{
		for(int i = 0; i<=stack->sp; i++)
		{
			printf("%c", stack->a[i]);
		}
		printf("\n");
	}
}

char pop(struct Stack *stack)
{
	if(stack->sp == -1)
		return -1;
	else
		return(stack->a[stack->sp--]);
}

void push(struct Stack *stack, int data)
{
	if(stack->sp == MS)
		return;
	else
		stack->a[++stack->sp] = data;
}

void inspect(struct Stack *stack)
{
	struct Stack x;
	initialize(&x);

	for(int i = 0; i<=stack->sp; i++)
	{
		if(stack->a[i] == '(' || stack->a[i] == '[' || stack->a[i] == '{')
			push(&x, stack->a[i]);			

		else if(stack->a[i] == ')' && peek(&x) == '(')
			pop(&x);
		else if(stack->a[i] == '}' && peek(&x) == '{')
			pop(&x);
		else if(stack->a[i] == ']' && peek(&x) == '[')
			pop(&x);
	}
	if(x.sp == -1)
		printf("Valid\n");
	else
		printf("Invalid\n");
}

void postfix(struct Stack *stack)
{
	struct Stack x,y;
	initialize(&x);
	initialize(&y);
	for(int i=0; i<=stack->sp; i++)
	{
		if(stack->a[i] == '(')
			push(&x, stack->a[i]);
		else if(stack->a[i] == ')')
		{
			while( peek(&x)!='(' )
			{
				push(&y, pop(&x));
			}
			pop(&x);
		}
		else if( (stack->a[i]>='a' && stack->a[i]<='z') || (stack->a[i]>='A' && stack->a[i]<='Z') )
			push(&y, stack->a[i]);
		else
		{
			if(peek(&x) == -1)
				push(&x, stack->a[i]);
			else if(precedence(stack->a[i]) > precedence(peek(&x)))
				push(&x, stack->a[i]);
			else
			{
				while(!(precedence(stack->a[i]) > precedence(peek(&x))))
					push(&y, pop(&x));
				push(&x, stack->a[i]);
			}
		}
	}
	while(peek(&x) != -1)
	{
		push(&y, pop(&x));
	}
	display(&y);
}

int precedence(char c)
{
	if(c=='*' || c=='/')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return 0;
}