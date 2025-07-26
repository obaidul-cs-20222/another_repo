#include <stdio.h>
int main()
{
	int a[20],t,i,min,n,k,j=0;
	printf("\n Enter the number of element :");
	scanf("%d", &n);
	printf("\n Enter the element into array:");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n The input array....: ");
	for(i=0;i<n;i++)
	{
		printf("%d,", a[i]);
	}
	for(k=0;k<n;k++)
	{
	
		min=a[k];
		for(i=k+1;i<n;i++)
		{
			if (min>a[i])
			{
				min=a[i];
				j=i;
			}
		}	
	printf("\n Min =%d",min);
	if(k!=j)
	{
	t=a[k];
	a[k]=min;
	a[j]=t;
}
}
	printf("\n The input array....: ");
	for(i=0;i<n;i++)
	{
		printf("%d,", a[i]);
	}
}
