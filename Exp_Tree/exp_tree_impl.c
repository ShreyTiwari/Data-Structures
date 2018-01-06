#include"exp_tree.h"

void initialize(struct tree *t)
{
    t->root = NULL;
}

void rinfix(struct node *p)
{
    if(p == NULL)
        return;
    else
    {
        rinfix(p->left);
        printf("%c  ",p->data);
        rinfix(p->right);
    }
}
void infix(struct tree *t)
{
    if(t->root == NULL)
        printf("There are no elements present in the tree.");
    else
        rinfix(t->root);
}

void rpostfix(struct node *p)
{
    if(p == NULL)
        return;
    else
    {
        rpostfix(p->left);
        rpostfix(p->right);
        printf("%c  ",p->data);
    }
}

void postfix(struct tree *t)
{
    if(t->root == NULL)
        printf("There are no elements present in the tree");
    else
        rpostfix(t->root);
}


void rprefix(struct node *p)
{
    if(p == NULL)
        return;
    else
    {
        printf("%c  ",p->data);
        rprefix(p->left);
        rprefix(p->right);
    }
}

void prefix(struct tree *t)
{
    if(t->root == NULL)
        printf("There are no elements present in the tree");
    else
        rprefix(t->root);
}



int isNumber(char c)
{
    if(c>='0' && c<='9')
        return 1;
    else
        return 0;
}

void push(struct stack *s, struct node *temp)
{
    s->array[++s->top] = temp;
}

struct node* pop(struct stack *s)
{
    return(s->array[s->top--]);
}

struct node* buildTree(char c[])
{
    int i = 0;

    while(c[i] != '\0')
        i++;

    if(i == 0)
        return NULL;
    else
    {
        struct stack s;
        s.top = -1;

        int j = 0;
        for(;j<i;j++)
        {
            struct node *x = (struct node*)malloc(sizeof(struct node));
            x->data = c[j];
            if(isNumber(c[j]))
            {
                x->left = x->right = NULL;
            }
            else
            {
                struct node *b = pop(&s);
                struct node *a = pop(&s);
                x->left = a;
                x->right = b;
            }
            push(&s, x);
        }
        return pop(&s);
    }
}
void push1(struct stack1 *s, int data)
{
    s->array[++s->top] = data;
}
int pop1(struct stack1 *s)
{
    return s->array[s->top--];
}

int evaluate(char c[])
{
    struct stack1 s;
    s.top = -1;
    
    int i =0,res;
    while(c[i] != '\0')
    {
        if(isNumber(c[i]))
            push1(&s, c[i]-'0');
        else
        {
            int b = pop1(&s);
            int a = pop1(&s);
            switch(c[i])
            {
                case '*': res = a*b;
                            break;
                case '+': res = a+b;
                            break;
                case '-': res = a-b;
                            break;
                case '/': res = a/b;
            }
            push1(&s, res);
        }
        i++;
    }
    return pop1(&s);
}

/*
Other way of writting evaluate function.....recursive : 

int eval(struct tree *t)
{
    if(t->root == NULL)
    {
        printf("There are no elements present in the tree.");
        return;
    }
    else
    {
        return evaluate(t->root);
    }
}

int evaluate(struct node *temp)
{
    if(temp->right == NULL && temp->left == NULL)
        return temp->data - '0';

    else
    {
        switch(temp->data)
        {
            case '*' : return( evaluate(temp->left) * evaluate(temp->right) );
            case '/' : return( evaluate(temp->left) / evaluate(temp->right) );
            case '+' : return( evaluate(temp->left) + evaluate(temp->right) );
            case '-' : return( evaluate(temp->left) - evaluate(temp->right) );
        }
    }
}

*/