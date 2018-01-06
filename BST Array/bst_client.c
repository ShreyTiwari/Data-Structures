#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[100];
	int op, data;
	for(int i = 0; i<100; ++i)
	{
		a[i] = 0;
	}

	while(1)
	{
		printf("1.insert\n");
		printf("2.inorder\n");
		printf("3.preorder\n");
		printf("4.postorder\n");
		printf("Enter your choice\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1: printf("Enter the data to be inserted\n");
				scanf("%d", &data);
				insert(a, data);
				break;

			case 2: inorder(a,0);
				break;

			case 3: preorder(a,0);
				break;

			case 4: postorder(a,0);
				break;

			default: exit(0);
		}
	}
}
