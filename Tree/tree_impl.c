#include"tree.h"

void initialize(struct tree *t)
{
	t->root = NULL;
}

void insert(struct tree *t, int data)
{
	if(t->root == NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = temp->right = NULL;
		t->root = temp;
	}
	else
	{
		insertAt(t->root, data);
	}
}

void insertAt(struct node *temp, int data)
{
	if((temp)->data == data)
		return;

	struct node *x = (struct node*)malloc(sizeof(struct node));
	x->data = data;
	x->left = x->right = NULL;

	if(temp->right == NULL && temp->left == NULL)
	{
		if(data > temp->data)
			temp->right = x;
		else
			temp->left = x;	
	}
	else if(temp->left == NULL && temp->data > data)
	{
		temp->left = x;
	}
	else if(temp->right == NULL && temp->data < data)
	{
		temp->right = x;
	}
	else
	{
		if(data > (temp)->data)
			insertAt((temp)->right, data);
		else
			insertAt((temp)->left, data);
	}
}

/*

void insert(struct tree *t, int data)
{
	if(t->root == NULL)
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = temp->right = NULL;
		t->root = temp;
	}
	else
	{
		
		if(data > t->root->data)
			insertAt(&(t->root->right), data);
		else
			insertAt(&(t->root->left), data);
	}
}

void insertAt(struct node **temp, int data)
{
	if(*temp == NULL)
	{
		struct node *x = (struct node*)malloc(sizeof(struct node));
		x->data = data;
		x->left = x->right = NULL;
		*temp = x;	
	}
	else if((*temp)->data == data)
		return;
	else
	{
		if(data > (*temp)->data)
			insertAt(&((*temp)->right), data);
		else
			insertAt(&((*temp)->left), data);
	}
}

*/

void inOrder(struct tree *t)
{
	if(t->root == NULL)
	{
		printf("\nThere are no elements present in the tree.\n");
		return;
	}
	else
	{
		printf("\n");
		inOrderPrint(t->root);
		printf("\n");
	}
}

void inOrderPrint(struct node *x)
{
	if(x == NULL)
		return;
	else
	{
		inOrderPrint(x->left);
		printf("%d	",x->data);
		inOrderPrint(x->right);
	}
}

void preOrder(struct tree *t)
{
	if(t->root == NULL)
	{
		printf("\nThere are no elements present in the tree.\n");
		return;
	}
	else
	{
		printf("\n");
		preOrderPrint(t->root);
		printf("\n");
	}	
}

void preOrderPrint(struct node *x)
{
	if(x == NULL)
		return;
	else
	{
		printf("%d	",x->data);
		preOrderPrint(x->left);
		preOrderPrint(x->right);
	}
}

void postOrder(struct tree *t)
{
	if(t->root == NULL)
	{
		printf("\nThere are no elements present in the tree.\n");
		return;
	}
	else
	{
		printf("\n");
		postOrderPrint(t->root);
		printf("\n");
	}	
}

void postOrderPrint(struct node *x)
{
	if(x == NULL)
		return;
	else
	{
		postOrderPrint(x->left);
		postOrderPrint(x->right);
		printf("%d	",x->data);
	}
}

void limits(struct tree *t)
{
	if(t->root == NULL)
	{
		printf("\nThere are no elements present in the tree.\n");
		return;
	}
	else
	{
		int max, min;
		struct node *p = t->root;
		max = min = p->data;
		while(p!=NULL)
		{
			max = p->data;
			p = p->right;
		}
		
		p = t->root;
		while(p!=NULL)
		{
			min = p->data;
			p = p->left;
		}

		printf("\nThe minimum value is : %d\nThe maximum value is : %d\n", min, max);
	}
}



void search(struct tree *t, int data)
{
	int x = rsearch(t->root, data);
	if(x == 1)
		printf("\nElement found !!!\n");
	else
		printf("\nNot found :(\n");
}


int rsearch(struct node *p, int data)
{
	if(p == NULL)
		return 0;
	else if(data == p->data)
		return 1;
	else 
	{
		if(data > p->data)
			return rsearch(p->right, data);
		else 
			return rsearch(p->left, data);
	}
}


int leaves(struct tree *t)
{
	return rleaves(t->root);
}


int rleaves(struct node *p)
{
	if(p == NULL)
		return 0;
	else if(p->right == NULL && p->left == NULL)
		return 1;
	else
		return rleaves(p->right) + rleaves(p->left);
}



int nodes(struct tree *t)
{
	return rnodes(t->root);
}


int rnodes(struct node *p)
{
	if(p == NULL)
		return 0;
	else if(p->right == NULL && p->left == NULL)
		return 1;
	else
		return (1 + rnodes(p->right) + rnodes(p->left));
}


void delete(struct tree *t, int data)
{
	 t->root = rdelete(t->root, data);
}

struct node* rdelete(struct node *root, int data)
{
	if(root == NULL) return root;
	else if(data > root->data) root->right = rdelete(root->right, data);
	else if(data < root->data) root->left = rdelete(root->left, data);
	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			free(root);
			root = NULL;
		}
		else if(root->left == NULL)
		{
			struct node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			struct node *temp = root;
			root = root->left;
			free(temp);
		}
		else
		{
			root->data = min(root->right);
			root->right = rdelete(root->right, root->data);
		}
	}
	return root;
}

int min(struct node *p)
{
	while(p->left!=NULL)
		p = p->left;
	return(p->data);
}
