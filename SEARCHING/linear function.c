#include<stdio.h>
#include<stdlib.h>
void linear(int *a,int n,int m);
int main()
{
	int n,*a,i;
	int m,k,x;
	printf("enter the size of the array");
	scanf("%d",&n);
	a=(int*) malloc (n* sizeof (int));
	printf("enter the elements in asecnding order\n");
	for(i=0;i<n;i++)
	{
		printf("enter the element for pos %d \t:",i+1);
	scanf("%d",a+1);
}
printf("enter the element you want to search");
scanf("%d",&x);
linear(a,n,x);
}
void linear(int *a,int n,int x)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(x==*a)
		{
			flag=1;
			printf("present at pos %d",i+1);
}
}
if(flag!=1)
{
	printf("not present");
}
free(a);
}
