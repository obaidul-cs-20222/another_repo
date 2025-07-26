#include<stdio.h>
#include<stdlib.h>
int main()
{

int n,i,*a,ch; 
     do
	 {
	  printf("\nEnter the no. of value:"); 
	  scanf("%d",&n);
	  if(n<=0)
	  {
	  	printf("Please enter a positive value");
	  }
	   
	   }
	   while(n<=0);
	  
	   a=(int*) malloc (n* sizeof (int));
	for(i=0;i<n;i++)
	{
		printf("Enter the element no %d \t:",i+1);
	scanf("%d",a+i);
    }

mergesort(a,0,n-1);
}

int mergesort(int *a,int lb,int ub,int n)
{
	if(lb>=ub)
     return;
     else
     {
     	int mid=(lb+ub)/2;
     	mergesort(a,lb,mid,n);
     	mergesort(a,mid+1,ub,n);
     	merge(a,0,mid,ub,n);
	 }
}


int merge(int *a,int lb, int mid, int ub)
{
 int i=lb,j=mid+1,k=1;  int n=ub,c[n],b[n];
while(i<=mid && j<=n)
{
	if(a[i]<b[j])
	{
		c[k]=a[i];
		i=i+1;
	}
	else
	{
		c[k]=a[j];
		j=j+1;
	}
     k=k+1;
     
}

if(i<j)
{
	for(j=i;j<=mid;j++)
	{
		c[k]=b[j];
		k++;
	}
}
else
{
	for(i=j;i<=n;i++)
	{
	c[k]=b[i];
	k++;
	}
}
printf("the sorted array is \n\n");

for(k=0;k<=n;k++)
{
	printf("%d",&c[k]);
}
}


