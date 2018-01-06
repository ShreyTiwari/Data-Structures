#include<stdio.h>
#include"list.h"

void main()
{
	struct BE list;
	list.head = NULL;
	int choice,ele,index;
	do
	{
		printf("1.Insert At End\
		      \n2.Insert At Beginning\
		      \n3.Insert At A Random Spot\
		      \n4.Delete From Beginning\
		      \n5.Delete From A Random Spot\
		      \n6.Delete From End\
		      \n7.Display The List\
		      \n8.Reverse The List\
		      \n9.Delete The List\
		      \nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted : ");
				scanf("%d", &ele);
				insert_e(&list, ele);
				printf("\n");
				break;
			case 2: printf("Enter the element to be inserted : ");
				scanf("%d", &ele);
				insert_b(&list, ele);
				printf("\n");
				break;
			case 4: remove_b(&list);
				printf("\n");
				break;
			case 7: printf("The list is : \n");
				display(&list);
				printf("\n");
				break;
			case 9: deleteList(&list);
				printf("\n");
				break;
			case 5: printf("Enter the element to be deleted : ");
				scanf("%d",&ele);
				remove_m(&list, ele);
				printf("\n");
				break;
			case 6: remove_e(&list);
				printf("\n");
				break;
			case 8: reverse(&list);
				printf("\n");
				break;
			case 3: printf("Enter the element to be inserted followed by the index :\n");
				scanf("%d %d", &ele, &index);
				insert_m(&list, ele, index);
				printf("\n");
				break;
		}
	}while(choice<10 && choice>0);
}

