#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, key, j, *a;
    printf("enter the no of elements:\t");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int));
    printf("enter the values:\t");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("\narray after selection sort:\t");

    for (i = 0; i < n; i++)
        printf("\t%d", a[i]);
}
