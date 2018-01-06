#include"poly.h"

void main()
{
    struct list list1, list2;
    initialize(&list1);
    initialize(&list2);

    printf("Polynomial One:\n");
    insert(&list1);
    printf("\nPolynomial Two: \n");
    insert(&list2);

    printf("\nResult:\n");
    candD(&list1, &list2);
}