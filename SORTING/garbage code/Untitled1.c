 #include<stdio.h>
 #include<stdlib.h>
 void bubblesort(int *a, int n);
 void modbubblesort(int *a,int n);
 void insertionsort(int *a,int n);
 void selectionsort(int *a,int n);
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
	   do
	   {
	   	printf("\n\t1.Bubble Sort\n\t2.Modified Bubble Sort\n\t3.Selection Sort\n\t4.Insertion Sort\n\t5.Merge Sort\n\t6.Quick Sort\n\t7.Heap Sort\n\t8.Count Sort\n\t9.Radix Sort\n\t10.Exit \nEnter your choice:");
	   scanf("%d",&ch);
       switch(ch)
       {
       	   case 1:
       	   	bubblesort(a,n);
       	   	break;
       	   	
       	   	case 2:
       	   	modbubblesort(a,n);
       	   	break;
       	   	
       	   	case 3:
       	   	selectionsort(a,n);	
       	   	break;
				  
				  case 4:
				  insertionsort(a,n);
				  break;
				  
				  case 5:
				  break;
				  
				  case 6:
				  break;
				  
				  case 7:
				  break;
				  
				  case 8:
				  break;
				  
				  case 9:
				  break;
				  
				  case 10:
				  break;
				  
				  	default:
 			printf("Enter an appropriate choice");
			break;	
	   }
       
	   }while(ch!=10);
	      
  return 0; 
  
free(a);
}


void bubblesort(int *a,int n)
{
	int i,swap,j;
for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i;j++)
{
	if( a[j]>a[j+1])
	{
		swap=a[j];
		a[j]=a[j+1];
		a[j+1]=swap;
	}
	}
	}
	printf("\nThe sorted array using bubble sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }

	
}



void modbubblesort(int *a,int n)
{
	int i,swap,flag,j;
for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i;j++)
{
	if( a[j]>a[j+1])
	{
		swap=a[j];
		a[j]=a[j+1];
		a[j+1]=swap;
		flag=1;
	}
	}
	if(flag==0)
	break;
	}
	printf("\nThe sorted array using modified bubble sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }

	
}

void selectionsort(int *a,int n)
{
int i,m,j,temp;
    for (i = 0; i < n-1; i++) 
    { 
        
        m=i; 
        for (j = i+1; j < n; j++) 
        {
		    if (a[j] < a[m]) 
          {
			  m=j; 
}
}
 temp=a[i];
 a[i]=a[m];
 a[m]=temp;
 }
 printf("\nThe sorted array using selection sort is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 	
}
}


void insertionsort(int *a,int n)
{
int  i, key, j;
    for (i = 0; i<n; i++)
	 { 
        key = a[i]; 
        j = i - 1; 
          while (j >= 0 && a[j] > key) { 
            a[j + 1] =a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = key; 
    } 
    printf("\nThe sorted array using insertion sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
}
}
