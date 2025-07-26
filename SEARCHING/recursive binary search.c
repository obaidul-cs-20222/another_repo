#include<stdio.h>
#include<stdlib.h>
int binary_recursive(int *a,int l,int r,int x);
int main()
{
	int n,*a,i;
	int t,c,x;
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
t=binary_recursive(a,0,n-1,x);
				if(t==-1)
				printf("\nElement not found in the array");
				else
				printf("\nElement found at position %d",t+1);

}
int binary_recursive(int *a,int l,int r,int x)
{
	int m;
	m=(l+r)/2;
	if(r<l)
		  return -1;
		 if(*(a+m)==x)
	     return m;
		else if(*(a+m)<x)
	     return binary_recursive(a,m+1,l,x);                  
		else
		 return binary_recursive(a,l,m-1,x);
}

	

