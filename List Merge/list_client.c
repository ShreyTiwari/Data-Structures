#include"list.h"

void main()
{
	struct List list1, list2, list3;
	list1.head = NULL;
	list2.head = NULL;
	list3.head = NULL;
	int ele;
	char ch;
	while(1)
	{
		printf("Enter the element of list one : ");
		scanf("%d", &ele);
		insert(&list1, ele);
		scanf("%c", &ch);
		printf("Do you wanna continue inserting ?[y/n] ");
		scanf("%c", &ch);
		__fpurge(stdin);
		//fflush(stdin);    for windows. 

		if(ch == 'n')
			break;
	}

	printf("\n");

	while(1)
	{
		printf("Enter the element of list two : ");
		scanf("%d", &ele);
		insert(&list2, ele);
		scanf("%c", &ch);
		printf("Do you wanna continue inserting ?[y/n] ");
		scanf("%c", &ch);
		__fpurge(stdin);
		//fflush(stdin);    for windows. 

		if(ch == 'n')
			break;
	}
	
    printf("\nThe lists are : \n");
	display(&list1);
	display(&list2);

	merge(&list1, &list2, &list3);
	printf("\nThe merged list is : \n");
	display(&list3);
	
	
	deleteList(&list1);
	deleteList(&list2);
	deleteList(&list3);
	printf("\n\t\tThank You\n");
}
