#include"poly.h"

void initialize(struct list *list)
{
    list->head = NULL;
    list->length = 0;
}

void add(struct list *list, int c, int p)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->coeff = c;
    temp->power = p;
    temp->link = NULL;

    if(list->head == NULL)
    {
        list->head = temp;
        list->length++;
        return;
    }

    else
    {
        struct node *p = list->head;

        while(p->link != NULL)
            p = p->link;
        
        p->link = temp;
        list->length++;
        return;
    }
}

void insert(struct list *list)
{
    int n;
    int c, p;
    printf("Enter the length of the polynomial:  ");
    scanf("%d", &n);

    for(int i =0; i<n; ++i)
    {
        printf("\nEnter the coeff and power of the element: ");
        scanf("%d %d", &c, &p);
        add(list, c, p);
    }
}

void candD(struct list *list1, struct list *list2)
{
    int e1, e2;
    struct node *p1, *p2;
    for(int i = 0; i<list1->length; ++i)
    {
        for(int j = 0; j<list2->length; ++j)
        {
            e1 = i;
            e2 = j;

            p1 = list1->head;
            p2 = list2->head;

            while(e1>0)
            {
                p1 = p1->link;
                e1--;
            }

            while(e2>0)
            {
                p2 = p2->link;
                e2--;
            }

            printf("%dX^%d  +   ",p1->coeff * p2->coeff, p1->power + p2->power);            
        }
    }
    printf("0\n\n");
}