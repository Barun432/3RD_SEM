// array Representatiomn of Binary tree.
#include <stdio.h>
void create(int a[], int i, int item)
{
    int ch;
    int val;
    a[i] = item;
    printf("\n Do you want to create left child for %d(1/0)", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\n Enter the left child: ");
        scanf("%d", &val);
        create(a, 2 * i, val);
    }

    printf("\n Do you want  to create right child for %d ( 1/0)", item);
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\n Enter the  right child: ");
        scanf("%d", &val);
        create(a, 2 * i + 1, val);
    }
}
void main()
{
    int a[100], item;
    int i;
    for (i = 0; i < 100; i++)
        a[i] = -1;

    printf("\n Enter the Root node : ");
    scanf("%d", &item);
    create(a, 1, item);

    // for printing the  Tree ELement
    printf("\n TREE :");
    for (i = 1; i <= 16; i++)
    {
        if (a[i] == -1)
            printf("- ");
        else
            printf("%d \t", a[i]);
    }
}
