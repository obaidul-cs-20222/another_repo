#include<stdio.h>
#include<stdlib.h>

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = { 0 };
 
  
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
      for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
    
    int m = getMax(arr, n);
 
    for ( exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 

void print(int arr[], int n)
{
    for ( i = 0; i < n; i++)
       printf("%d",&a[i]);
}
 

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(arr) / sizeof(arr[0]);
     
     
      radixsort(arr, n);
    print(arr, n);
    return 0;
}




































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

        radixsort(arr, n);

        for(i=0;i<n;i++)
		{
			printf("\t%d\t",arr+i);		
		}
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