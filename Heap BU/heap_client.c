#include"heap.h"

void main()
{
    int array[max];
    int n,ch=1;
    printf("\nEnter the number of elements\n");
    scanf("%d", &n);
    readArray(array, n);

    while(ch)
    {
        printf("\nEnter your choice :\n1.Display\n2.Sort\n3.Quit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("\n");
                    displayArray(array, n);
                    printf("\n");
                    break;
            case 2: printf("\n");
                    sort(array, n);
                    printf("\n");
                    break;
            default: ch = 0;
        }
    }
}