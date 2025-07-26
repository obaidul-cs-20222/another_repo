#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE node;
node *CREATENODE(int);  
void traversal(); 
void insertbeginning(int);
void insertend(int);
node *start;  


void insertbeginning(int item)
{
	node *p;
	p=CREATENODE(item);
	if(start==NULL)
	{
		start=p;
	}
	else
	p->next=start;
	start=p;
}
void insertend(int item)
{
	node *p,*q;
	p=CREATENODE(item);
	if(p==NULL)
	{
		start=p;
	}
	else
	{
		q=start;
		while(q->next!=NULL)
		{
			q=q->next;
		}
	q->next=p;
	}
}
void traversal()
{
	node *p,*r,*q;
	p=start;
	printf ("\n here is your list \n");
	while(p!=NULL)
	{
		printf("%d\t\t",p->info);
		p=p->next;
	}
	
}


node *CREATENODE(int item)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL; 
	p->info=item;
	return(p);
}

	int main()
	{
	
	int n,i,j,item=0,t;
	printf("\n length\n");
scanf("%d",&n);	printf("\n item\n");
for(i=0;i<n*2;i+=2)
{
	scanf("%d",&t);
	item=t;
	for(j=1;j<n;j+=2)
	{
		scanf("%d",&t);
	}
  
  if(t==0)
  {
  	insertbeginning(item);
  }else
  {
  	insertend(item);
  }
}
traversal();
}
   
