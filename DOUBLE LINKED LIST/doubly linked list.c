#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};

void createDLL(struct node **,int);
void printDLL(struct node *);
struct node *getNode(int);

int main()
{
  
  struct node *start=NULL;
  int ch,item;
  do
  {
     printf("\n\t1. Create \n\t 2. Print \n\t 3. Exit \nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
	{
		case 1:
			printf("\nEnter the item:");
			scanf("%d",&item);
			createDLL(&start,item);	
			break;

		case 2:
			printDLL(start);
			break;

		case 3:
			break;

		default:
 			printf("Enter an appropriate choice");
			break;
	}

  }while(ch!=3);

  return 0;
}


void createDLL(struct node **start,int item)
{

  if((*start)==NULL)
   {	
  	*start=getNode(item);
   }
  else
   {
	struct node *p,*q;
        q=getNode(item);	
	p=*start;
	while(p->next!=NULL)
	   p=p->next;
	p->next=q;
        q->prev=p;
    }	




}

struct node *getNode(int item)
{
  struct node *p;
  p=(struct node *) malloc(sizeof(struct node));
  p->data=item;
  p->prev=NULL;
  p->next=NULL;
  return p;
}


void printDLL(struct node *start)
{
	struct node *p;
	p=start;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);

	printf("\nElements in reverse order:");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->prev;
	}


}

