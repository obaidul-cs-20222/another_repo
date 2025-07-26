#include<stdio.h>
#include<stdlib.h>


void merge(int *arr,int lb,int mid,int ub)	
{	
	int *b,i,j,k;
	b=(int*)malloc((ub+1)*sizeof(int));
	for(i=lb;i<=ub;i++)
	{
		*(b+i)=*(arr+i);
	}
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(*(b+i)<*(b+j))
		{
			*(arr+k)=*(b+i);
			i++;
			k++;
		}
		else
		{
			*(arr+k)=*(b+j);
			j++;
			k++;
		}
	}
	while(i<=mid)
	{
		*(arr+k)=*(b+i);
		i++;
		k++;
	}
	while(j<=ub)
	{
		*(arr+k)=*(b+j);
		j++;
		k++;
	}
}


void merge_sort(int *arr,int lb,int ub)		
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(arr,lb,mid);
		merge_sort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}



int main()
{
    int n,*arr,i;
        
        printf("\n how many elements you want to insert:\t");
        scanf("%d",&n);

        arr=(int*)malloc(n*sizeof(int));	
		printf("\nEnter the elements:\t");
		for(i=0;i<n;i++)
		{
			scanf("%d",arr+i);		
		}

          

            merge_sort(arr,0,n-1);
			
  
  
        for(i=0;i<n;i++)
		{
			printf("\t%d\t",*(arr+i));		
		}
               free(arr);
}