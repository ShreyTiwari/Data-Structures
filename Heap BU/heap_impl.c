#include"heap.h"

void readArray(int array[], int n)
{
    printf("Enter the elements:\n");
    for(int i=1; i<=n ; i++)
    {
        scanf("%d", &array[i]);
    }
}

void displayArray(int array[], int n)
{
    printf("The elements are:\n");
    for(int i=1; i<=n ; i++)
    {
        printf("%d  ", array[i]);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int array[], int n, int pos)
{
    int i = pos;
    int j = 2*pos;

    while(j<=n)
    {
        if( j<n && array[j+1]>array[j] )
            ++j;
        if( array[i]<array[j] )
        {
            swap(&array[i], &array[j]);
            i = j;
            j = 2*i;
        }
        else
            break;
    }
}

void sort(int array[], int n)
{
    for(int i=n/2; i>=1; --i)
        heapify(array, n, i);

    for(int i = n; i>=1 ; --i)
    {
        swap(&array[1], &array[i]);
        heapify(array, i-1, 1);
    }
}