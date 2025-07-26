#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};typedef struct node NODE; 


void anypos(int,int);
void createDLL(int);
void printDLL();
NODE *getNode(int);
int linear(int);
NODE *start;
int main()
{
  
  start=NULL;
  int ch,item,m=1,k,t,pos;
  do
  {
     printf("\n\t1. CREATE \n\t 2.INSERTION AT ANY POSITION \n\t 3.LINEAR \n\t4.PRINT\n\t5 EXIT \nENTER YOUR CHOICE:");
     scanf("%d",&ch);
     switch(ch)
	{
		case 1:
			printf("\nENTER THE ITEM ON POSITION %d:",m);
			scanf("%d",&item);
			createDLL(item);
			m++	;
			break;

			case 2:
			printf("\nENTER THE POSITION\n");
			scanf("%d",&pos);
			printf("\nENTER THE ITEM\n");
			scanf("%d",&item);
			anypos(item,pos);
			break;
        
		case 3:

printf("ENTER THE ELEMENT YOU WANT TO SEARCH");
			scanf("%d",&k);
			t=linear(k);
			if(t==-1)
			{
				printf("\nNOT PRESENT IN THE LIST\n");
							}
							else
							{
								printf("\nPRESENT AT POSITION %d\n",t);
							}
			break;



case 4:
			printDLL();
			break;

case 5:
	break;
	
		default:
 			printf("ENTER AN APPROPRIATE CHOICE");
			break;
	}

  }while(ch!=5);

  return 0;
}
void anypos(int item,int pos)
{
	NODE *p,*temp;
	int i;
	temp=getNode(item);
	if(start==NULL)
	{
		printf("\nAS THE LIST IS EMPTY THE NEW ELEMENT %d WILL BE INSERTED AT THE BEGINNING",item);
		start=temp;
	}
	else
	{
		if(pos==1)
		{
			temp->next=start;
			start->prev=temp;
			start=temp;
			printf("\nNEW ELEMENT %d IS INSERTED AT POSITION  %d",item,pos);
		}
		else
		{
			p=start;
			for(i=1;i<pos-1;i++)
			{
				if(p!=NULL)
				p=p->next;
				
				else
				break;
			}
			if(p==NULL)
			{
				printf("\nINVALID POSITION");
			}
			else if(p->next==NULL)
			{
				p->next=temp;
				temp->prev=p;
				printf("\nNEW ELEMENT  %d IS INSERTED AT POSITION %d",item,pos);
			}
			else
			{
				temp->next=p->next;
				temp->prev=p;
				(p->next)->prev=temp;
				p->next=temp;
				printf("\nNEW ELEMENT %d IS INSERTED AT POSITION  %d",item,pos);
			}
		}
	}
}
NODE *getNode(int item)
{
  NODE *p;
  p=(NODE*) malloc(sizeof(NODE));
  p->data=item;
  p->prev=NULL;
  p->next=NULL;
  return p;
}
void printDLL()
{
	struct node *p;
	p=start;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d ",p->data);

	


}

void createDLL(int item)
{

  if((start)==NULL)
   {	
  	start=getNode(item);
   }
  else
   {
	struct node *p,*q;
        q=getNode(item);	
	p=start;
	while(p->next!=NULL)
	   p=p->next;
	p->next=q;
        q->prev=p;
    }	




}
int linear(int k)
{
 int c=1;
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		if(p->data==k)
		{
			return c;
			}
			else
		c=c+1;
		p=p->next;
	}
	return -1;
}

