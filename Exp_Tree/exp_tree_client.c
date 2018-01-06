#include"exp_tree.h"

void main()
{
    struct tree t;
    initialize(&t);

    char c[100];
    printf("\nEnter the valid postfix expression :  ");
    gets(c);

    t.root = buildTree(c);

    printf("\nThe Infix form is : \n");
    infix(&t);

    printf("\nThe Postfix form is : \n");
    postfix(&t);

    printf("\nThe Prefix form is : \n");
    prefix(&t);

    printf("\n\nThe answer is : %d\n", evaluate(c));
}