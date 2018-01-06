#include"tree.h"

void main()
{
	int ch, data;
	struct tree t;
	initialize(&t);

	while(ch)
	{
		
		printf("1.Insert\n2.Display(inorder)\n3.Display(preorder)\n4.Display(postorder)\n5.Limits\n6.Search\n7.No of external nodes\n8.No of nodes\n9.Delete");
		printf("\nEnter your choice :  ");
		scanf("%d", &ch);
	
		switch(ch)
		{
			case 1: printf("Enter the data : ");
				scanf("%d", &data);
				insert(&t, data);
				printf("\n");
				break;
			case 2: inOrder(&t);
				printf("\n");
				break;
			case 3: preOrder(&t);
				printf("\n");
				break;
			case 4: postOrder(&t);
				printf("\n");
				break;
			case 5: limits(&t);
				printf("\n");
				break;
			case 6: printf("Enter the element to be searched.\n");
				scanf("%d", &data);
				search(&t, data);
				printf("\n");
				break;
			case 7: data = leaves(&t);
				if(data == 0)
					printf("\nThere are no nodes present in the tree.\n");
				else
					printf("\nThe number of leaves are : %d\n", data);
				printf("\n");
				break;
			case 8: data = nodes(&t);
				if(data == 0)
					printf("\nThere are no nodes present in the tree.\n");
				else
					printf("\nThe number of nodes are : %d\n", data);
				printf("\n");
				break;
			case 9: printf("Enter the data to be deleted : ");
				scanf("%d", &data);
				delete(&t, data);
				printf("\n");
				break;
			default: printf("\nThank You!!!\n");
				ch = 0;
		}
	}
}