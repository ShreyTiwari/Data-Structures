#include"stack.h"

void main()
{
	int ch,n;
	char ele[100],x;
	struct Stack stack;
	initialize(&stack);
	
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Peep\n4.Display\n5.Inspect\n6.Convert to postfix.\nEnter your choice :	  ");	
		scanf("%d", &ch);
		__fpurge(stdin);
		switch(ch)
		{
			case 1: printf("Enter the expression : ");
				gets(ele);
				__fpurge(stdin);
				for(int i=0; i<strlen(ele); i++)
					push(&stack, ele[i]);
				__fpurge(stdin);
				printf("\n");
				break;
			case 2: printf("%c was popped.\n", pop(&stack));
					printf("\n");
				break;
			case 3: x = peek(&stack);
				if(x == -1)
					printf("Stack is empty.\n");
				else
					printf("The top of the stack is : %c\n", x);
				printf("\n");
				break;
			case 4: display(&stack);
					printf("\n");
				break;
			case 5: inspect(&stack);
					printf("\n");
				break;
			case 6: postfix(&stack);
					printf("\n");
				break;
			default: printf("\nThank You!!!\n");
				 exit(0);	
		}
	}
}
