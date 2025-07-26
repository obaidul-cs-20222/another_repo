#include <stdio.h>
#include <stdlib.h>

void arraytree(int *, int);
// void linkedtree(int *, int);

int main()
{

    int n, ch, *a;
    printf("\nhow many elements you want to enter:\t");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("\nenter the elements:\t");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nenter 1 for array implementation:\nenter 2 for linked representation:\nenter 3 for exit:\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:

        for (int i = 0; i < n; i++)
        {
            arraytree(a, i);
        }

        break;

    case 2:
        // linkedtree(a, n);
        break;

    default:
        break;
    }

    printf("\ntree is :\t");
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf("\t%d", a[i]);
    }
    free(a);

    return 0;
}

void arraytree(int *a, int i)
{
    int item;
    if (i != 0)
    {
        item = a[i];
        if (i % 2 == 0)
        {
            arraytree(a, 2 * i + 1);
        }
        else
        {
            arraytree(a, 2 * i);
        }
    }
    else
        arraytree(NULL, 0);
}