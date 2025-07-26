#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*a,i;
	int m,x;
	printf("enter the size of the array");
	scanf("%d",&n);
	a=(int*) malloc (n* sizeof (int));
	printf("enter the elements in asecnding order\n");
	for(i=0;i<n;i++)
	{
		printf("enter the element for pos %d \t:",i+1);
	scanf("%d",&a[i]);
}
printf("enter the element you want to search");
scanf("%d",&m);
	for(i=0;i<=n;i++)
	{
		if(m==a[i])
		{
			x=1;
			printf("present at pos %d",i+1);
}
}
if(x==0)
{
	printf("not present");
}
free(a);
}
