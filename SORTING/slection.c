#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m, temp, *a, i, n, j, swap;
	printf("enter the elements:\t");
	scanf("%d", &n);
	a = (int *)malloc(sizeof(int));
	printf("enter the values:\t");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (i = 0; i < n - 1; i++)
	{

		m = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[m])
			{
				m = j;
			}
		}
		temp = a[i];
		a[i] = a[m];
		a[m] = temp;
	}

	printf("\narray after selection sort:\t");

	for (i = 0; i < n; i++)
		printf("\t%d", a[i]);
}
