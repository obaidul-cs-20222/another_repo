#include<stdio.h>
#include<stdlib.h>
void countsort(int *a, int n);
int main()
{
    int n,i,*a,ch; 
     do
	 {
	  printf("\nEnter the no. of value:\t"); 
	  scanf("%d",&n);
	  if(n<=0)
	  {
	  	printf("Please enter a positive value");
	  }
	   
	   }
	   while(n<=0);
	  
	   a=(int*) malloc (n* sizeof (int));
       printf("Enter the elements:\t");
	for(i=0;i<n;i++)
	{
        
	scanf("%d",a+i);
    }
	countsort(a,n-1);
		free(a);
   return 0;
	}
	

void countsort(int *a, int n)
{
    int i,j;
    int max;
    max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
        {
            max=a[i];
        }
    }//printf("\n\nthe maximum no is \n\n%d",max);
    

    int *c;
    c=(int*) malloc (n* sizeof (max+1));
    for(i=0;i<max+1;i++)
    {
        c[i]=0;
    }
    for(i=0;i<=n;i++)
    {
        c[a[i]]++;
    }
    
    
    i=0;
    j=0;

    while(i<max+1)
    {
        if(c[i]>0)
        {
            a[j]=i;
            c[i]--;
            j++;
        }
        else
        i++;
    }
printf("\n\n the sorted array using count sort is\n\n");
for(j=0;j<=n;j++)
{
    printf("\t%d\t",a[j]);
}
free(c);
  
}
