#include"queue.h"

void main()
{
	struct queue q;	
	initialize(&q);
	int ch = 1;
	int data, y;
	while(ch)
	{
		printf("\n1-Display\n2-Enqueue\n3-Dequeue\n");
		printf("Enter your choice : \n");
		
		scanf("%d", &ch);

		switch(ch)
		{
			case 1: printf("\n");
				display(&q);
				printf("\n");
				break;
			case 2: printf("Enter the data : ");
				scanf("%d", &data);
				enqueue(&q, data);
				printf("\n");
				break;
			case 3: y = dequeue(&q);
				if(y!=-1)
				printf("\nThe element removed is : %d\n", y);
				break;	
			default : ch = 0;
		}
	}
}
