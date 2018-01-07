#include"queue.h"

void main()
{
	struct queue q;
	initialize(&q);
	int ch = 1;
	int data, pri;
	while(ch)
	{
		printf("\n1.Insert\n2.Remove\n3.Display\nEnter your choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("\nEnter the element to be inserted followed by its priority :\n");
				scanf("%d %d", &data, &pri);
				insert(&q, data, pri);
				break;
			case 2: printf("The element removed was :  %d\n", delete(&q));
				break;
			case 3: display(&q);
				break;
			default : ch = 0;
		}
	}
}
