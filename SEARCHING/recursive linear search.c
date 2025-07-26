#include<stdio.h>
#include<stdlib.h>
int linear_recursive(int *a,int x,int n);
int main()
{
		int n,*a,i;
	int c,x;
	printf("enter the size of the array");
	scanf("%d",&n);
	a=(int*) malloc (n* sizeof (int));
	printf("enter the elements in asecnding order\n");
	for(i=0;i<n;i++)
	{
		printf("enter the element no %d \t:",i+1);
	scanf("%d",a+i);
}
printf("enter the element you want to search");
scanf("%d",&x);
c=linear_recursive(a,x,n);
if(c==-1)
				printf("\nElement not found in the array");
				else
				printf("\nElement found at position %d",c+1);

}

int linear_recursive(int *a,int x,int n)
{
	if(n<0)
	return -1;
	else if(*(a+n)==x)
	return n;
	else
	return linear_recursive(a,x,n-1);

}
