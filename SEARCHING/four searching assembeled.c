#include<stdio.h>
#include<stdlib.h>
void linear(int *a,int n,int x);
void binary(int *a,int n,int x);
int main()
{
int n,*a,i;
	int c,x,t;
	printf("ENTER THE LENGTH OF THE ARRAY\t:");
	scanf("%d",&n);
	a=(int*) malloc (n* sizeof (int));
	printf("PLEASE ENTER THE ELEMENTS IN ASCENDING ORDER\n");
	for(i=0;i<n;i++)
	{
		printf("ENTER THE ELEMENT NO %d \t:",i+1);
	scanf("%d",a+i);
}
do
{
	printf("\n\nSELECT YOUR DESIRED SEARCHING METHOD\n");
	printf("\nPRESS 1 for ITERATIVE LINEAR SEARCH\nPRESS 2 FOR RECURSIVE LINEAR SEARCH\nPRESS 3 FOR LINEAR BINARY SEARCH\nPRESS 4 FOR RECURSIVE BINARY SEARCH\nPRESS 5 FOR EXIT\n");
scanf("%d",&c);
switch(c)
{

	case 1:
		printf("YOU HAVE CHOOSEN ITERATIVE LINEAR SEARCH\n");
		printf("ENTER THE ELEMENT YOU WANT TO SEARCH \t:");
        scanf("%d",&x);
	linear(a,n,x);
			break;
	
		case 2:
		printf("YOU HAVE CHOOSEN RECURSIVE LINEAR SEARCH\n");
		printf("ENTER THE ELEMENT YOU WANT TO SEARCH \t:");
         scanf("%d",&x);
         t=linear_recursive(a,x,n);
		if(t==-1)
				printf("\nELEMENT NOT FOUND IN ARRAY\n");
				else
				printf("\nELEMENT FOUND AT POSITION %d\n",t+1);
		break;	
	
		case 3:
		printf("YOU HAVE CHOOSEN ITERATIVE BINARY SEARCH \n ");
		printf("ENTER THE ELEMENT YOU WANT TO SEARCH \t:");
        scanf("%d",&x);
		binary(a,n,x);
		break;	
	
		case 4:
		printf("YOU HAVE CHOOSEN RECURSIVE BINARY SEARCH\n ");
		printf("ENTER THE ELEMENT YOU WANT TO SEARCH \t:");
        scanf("%d",&x);
		t=binary_recursive(a,0,n-1,x);
		if(t==-1)
				printf("\nELEMENT NOT FOUND IN THE ARRAY\n");
				else
				printf("\nELEMENT FOUND AT POSITION %d\n",t+1);
		break;
		
		case 5:
			break;
			
		default:
 			printf("ENTER AN APPROPRIATE CHOICE\n");
			break;
}
}
while(c!=5);
free(a);
}
void linear(int *a,int n,int x)
{
	int i;
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(*(a+i)==x)
		{
			flag=1;
			printf("ELEMENT FOUND AT POSITION %d\n",i+1);
}
}
if(flag==0)
{
	printf("ELEMENT NOT FOUND IN THE ARRAY \n");
}
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
 	printf("ELEMENT FOUND AT POSITION %d",m+1);
 	
	 found=1;
	 break;
 }
}
 if(found!=1)
 printf("ELEMENT NOT FOUND IN THE ARRAY\n");
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
	     return binary_recursive(a,m+1,r,x);                  
		else
		 return binary_recursive(a,l,m-1,x);
}

