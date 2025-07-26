 #include<stdio.h>
 #include<stdlib.h>
 void bubblesort(int *a, int n);
 int bubblerecur(int *a,int lb,int ub);
 void modbubblesort(int *a,int n);
 int modbubblerecur(int *a,int lb,int ub);
 void insertionsort(int *a,int n);
 int insertionrecur(int *a,int lb,int ub);
 void selectionsort(int *a,int n);
 int selectionrecur(int *a,int lb,int ub);



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
       	   	bubblerecur(a,1,n);
       	   	printf("\nThe sorted array using recursive bubble sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }				  
       	   	break;
       	   	
       	   	case 3:
       	   		modbubblesort(a,n);
       	   	break;
				  
				  case 4:
				  modbubblerecur(a,1,n);
				  printf("\nThe sorted array using recursive modified bubble sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }				  
				  break;
				  
				  case 5:
				  selectionsort(a,n);
				  break;
				  
				  case 6:
				  	selectionrecur(a,1,n);
				  	printf("\nThe sorted array using recursive selection sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }				  
				  break;
				  
				  case 7:
				  insertionsort(a,n);
				  break;
				  
				  case 8:
				  insertionrecur(a,1,n);	
				  printf("\nThe sorted array using recursive insertion sort  is  :\n");
    for (i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }				  
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
		for( j=0;j<n-i;j++)
{
	if( a[j]>a[j+1])
	{
		int swap=a[j];
		a[j]=a[j+1];
		a[j+1]=swap;
	}
	}
	}
	printf("\nThe sorted array using bubble sort  is  :\n");
    for ( i =0; i <n; i++) 
      {
		  printf("\t%d  ", *(a+i)); 
    printf("\t"); 
   }

	
}

int bubblerecur(int *a,int lb,int ub)
{
	int j,i,swap;
	if(lb>ub)
	{
		return 0;
	}
	else
	{
		for(j=0;j<(ub-lb);j++)
		{
		if( a[j]>a[j+1])
	{
		swap=a[j];
		a[j]=a[j+1];
		a[j+1]=swap;
	}	
	
	
		}
		bubblerecur(a,lb+1,ub);
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


int modbubblerecur(int *a,int lb,int ub)
{ int i,j,swap,flag;
	if(lb>ub)
	{
		return 0;
	}
	else
	{
		for(j=0;j<ub-lb;j++)
		{
		if( a[j]>a[j+1])
	{
		swap=a[j];
		a[j]=a[j+1];
		a[j+1]=swap;
	int flag=1;
	}	
	
	if (flag==0)
	return 0;
	
		}
		modbubblerecur(a,lb+1,ub);
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

int selectionrecur(int *a,int lb,int ub)
{
   int m,i,j;
	if(lb>ub)
	{
     return 0;
		}else
	 m=a[lb];
	for(j=lb+1;j<ub;j++)
	{
		if (a[j] < a[m]) 
          {
			  m=j; 
}

 int  temp=a[i];
 a[i]=a[m];
 a[m]=temp;
}	 
	selectionrecur(a,lb+1,ub);

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


int insertionrecur(int *a,int lb,int ub)
{
	int i,j;
	
	if(lb>ub)
	return 0;
	else
	{
		int key=a[lb];
		int j=lb-1;
		while (j >= 0 && a[j] > key) { 
            a[j + 1] =a[j]; 
            j = j - 1; 
        } 
        a[j + 1] = key; 
        insertionrecur(a,lb+1,ub);
	}
	
}


