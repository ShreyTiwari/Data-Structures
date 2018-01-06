#include"list.h"

void main()
{
	struct List list;
	initialize(&list);
	int choice,ele,index;
	do
	{
		printf("\n1.Insert At The Beginning\n2.Insert At The End\n3.Insert At A Random Position\
			\n4.Remove From The Beginning\n5.Remove From The End\n6.Remove A Specific Element\n7.Display The List\
			\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter the element to be inserted : ");
				scanf("%d", &ele);
				insert_b(&list, ele);
				printf("\n");
				break;
			case 2: printf("Enter the element to be inserted : ");
				scanf("%d", &ele);
				insert_e(&list, ele);
				printf("\n");
				break;
			case 3: printf("Enter the element to be inserted : ");
				scanf("%d", &ele);
				printf("Enter the position : ");
				scanf("%d", &index);
				insert_m(&list, ele, index);
				printf("\n");
				break;
			case 4: remove_b(&list);
				printf("\n");
				break;
			case 5: remove_e(&list);
				printf("\n");
				break;
			case 6: printf("Enter the element to be deleted : ");
				scanf("%d", &ele);
				remove_m(&list, ele);
				printf("\n");
				break;
			case 7: printf("The list is : \n");
				display(&list);
				printf("\n");
				break;
		}
	}while(choice<8 && choice>0);
}
