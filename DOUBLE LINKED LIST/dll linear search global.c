#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
}; 


void anypos(int,int,struct node **);
void createDLL(struct node **,int);
void printDLL(struct node *);
void delfirst(struct node **);
void dellast(struct node *);
void middel(struct node *);
struct node *getNode(int);
int linear(int,struct node *);
struct node *start;
int main()
{
  
  struct node *start=NULL;
  int ch,item,m=1,k,t,pos;
  do
  {
     printf("\n\t1. CREATE \n\t 2.INSERTION AT ANY POSITION \n\t 3.LINEAR \n\t4.PRINT\n\t5. DELETE THE FIRST NODE\n\t6. DELETE THE LAST NODE\n\t7.DELETE THE MIDDLE NODE\n\t8.FOR EXIT \nENTER YOUR CHOICE:");
     scanf("%d",&ch);
     switch(ch)
	{
		case 1:
			printf("\nENTER THE ITEM ON POSITION %d:",m);
			scanf("%d",&item);
			createDLL(&start,item);
			m++	;
			break;

			case 2:
			printf("\nENTER THE POSITION\n");
			scanf("%d",&pos);
			printf("\nENTER THE ITEM\n");
			scanf("%d",&item);
			anypos(item,pos,&start);
			break;
        
		case 3:

printf("ENTER THE ELEMENT YOU WANT TO SEARCH");
			scanf("%d",&k);
			t=linear(k,start);
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
			printDLL(start);
			break;

case 5:
	delfirst(&start);
	break;
	
	case 6:
		dellast(start);
		break;
		 
		 case 7:
		 	 middel(start);
			  break;
	
	case 8:
		break;
		
		default:
 			printf("ENTER AN APPROPRIATE CHOICE");
			break;
	}

  }while(ch!=8);

  return 0;
}
void anypos(int item,int pos,struct node **start)
{
	struct node *p,*temp;
	int i;
	temp=getNode(item);
	if((*start)==NULL)
	{
		printf("\nAS THE LIST IS EMPTY THE NEW ELEMENT %d WILL BE INSERTED AT THE BEGINNING",item);
		*start=temp;
	}
	else
	{
		if(pos==1)
		{
			temp->next=*start;
			(*start)->prev=temp;
			*start=temp;
			printf("\nNEW ELEMENT %d IS INSERTED AT POSITION  %d",item,pos);
		}
		else
		{
			p=*start;
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
struct node *getNode(int item)
{
  struct node *p;
  p=(struct node*) malloc(sizeof(struct node));
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
int linear(int k,struct node *start)
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

void delfirst(struct node **start)
{
	struct node *q;
	q=*start;
	(q->next)->prev=NULL;
	*start=q->next;
	free(q);
}


void dellast(struct node *start)
{
	struct node *q;
	q=start;
	while(q->next!=NULL)
	{
		q=q->next;
	}
(q->prev)->next=NULL;
free(q);
}

void middel(struct node *start)
{
struct node *p,*q;
int m=1;
p=start;
q=start;
while(p->next!=NULL)
{
if(m%2==0)
{
q=q->next;
}
p=p->next;
m=m+1;
}
(q->prev)->next=q->next;
(q->next)->prev=q->prev;
free(q);
}
