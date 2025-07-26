#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,*a,i;
	int c,x;
	printf("enter the size of the array");
	scanf("%d",&n);
	a=(int*) malloc (sizeof (int));
	printf("enter the elements in asecnding order\n");
	for(i=0;i<n;i++)
	{
		printf("enter the element no %d \t:",i+1);
	scanf("%d",a+i);
}
for(i=0;i<n;i++)
{
	printf("%d \t",*(a+i));
}
free(a);
}
