#include<stdio.h>
#include<stdlib.h>
void binary(int *a,int n,int x);
int main()
{
	int n,*a,i;
	int x;
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
binary(a,n,x);
}
void binary(int *a,int n,int x)
{
	int l,r,m,found;
l=0;
r=n-1;
	while (l<=r) 
	{
         m=(l+r) / 2;
          if (a[m] > x)
{
r=m-1;
}else
	if(x>a[m])
	{
		l=m+1;
	}
		 else
		  if (a[m] == x)
 {
 	printf("found at positon %d",m+1);
 	
	 found=1;
	 break;
 }
}
 if(found!=1)
 printf("element is not present");
  free(a);
}

