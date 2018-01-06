#include<stdio.h>
#include"bst.h"

void insert(int* arr, int data)
{
	int i = 0;
	while(arr[i] != 0)
	{
		if(arr[i] > data)
		{
			i = 2 * i + 1;
		}
		else
		{
			i = 2 * i + 2;
		}
	}
	arr[i] = data;
}

void inorder(int* arr, int i)
{
	if(arr[i] != 0)
	{
		inorder(arr, 2 * i + 1);
		printf("%d ", arr[i]);
		inorder(arr, 2 * i + 2);	
	}
}
void preorder(int* arr, int i)
{
	if(arr[i] != 0)
	{
		printf("%d ", arr[i]);
		preorder(arr, 2 * i + 1);
		preorder(arr, 2 * i + 2);
	}
}

void postorder(int* arr, int i)
{
	if(arr[i] != 0)
	{
		
		postorder(arr, 2 * i + 1);
		postorder(arr, 2 * i + 2);
		printf("%d ", arr[i]);
	}
}