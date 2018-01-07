#include"queue.h"

void main()
{
	int ch=1, data, pri;
	struct queue q;
	initialize(&q);

	while(ch)
	{
		printf("\nEnter your choice : \n");
		printf("1.Insert\n2.Delete\n3.Display\n");
		scanf("%d", &ch);
		
		switch(ch)
		{
			case 1: printf("Enter the data followed by its priority :\n");
				scanf("%d %d", &data, &pri);
				insert(&q, data, pri);
				break;
			case 2: delete(&q);	
				break;
			case 3: display(&q);
				break;
			default: printf("\nThank You!!!\n");
					ch = 0; 
		}
	}
}
