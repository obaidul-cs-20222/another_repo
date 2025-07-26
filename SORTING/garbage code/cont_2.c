#include<stdio.h>
#include<stdlib.h>
void countsort(int *a, int n);
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
	countsort(*a,n-1);
		/*printf("\nThe sorted array using count sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }*/
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
    }printf("\n\nthe maximum no is \n\n%d",max);
}
