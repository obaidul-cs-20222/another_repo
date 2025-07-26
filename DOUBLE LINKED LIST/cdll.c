#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
void printcdll(struct node *);
void begin_cdll(struct node **,int);
void end_cdll(struct node **,int);
void delbeg(struct node **);
void delend(struct node **);
struct node *getnode(int);
int main()
{
	struct node *start= NULL;
  int ch,item;
   do
  {
     printf("\n\t1.INSERTION AT THE BEGINNING OF THE LIST \n\t 2.INSERTION AT THE END OF THE LIST\n\t 3.PRINT THE LIST \n\t 4.DELETE THE FIRST NODE OF THE LIST\n\t 5.DELETE THE LAST NODE OF THE LIST \n\t 6. EXIT\nENTER YOUR CHOICE:");
     scanf("%d",&ch);
     switch(ch)
	{
		case 1:
			printf("\nEnter the item:");
			scanf("%d",&item);
			begin_cdll(&start,item);	
			break;

		case 2:
			printf("\nEnter the item:");
			scanf("%d",&item);
			 end_cdll(&start,item);
			break;
			

		case 3:
			printcdll(start);
			break;

	case 4:
		delbeg(&start);
		break;
		
		case 5:
		delend(&start);
		break;
		
		
		case 6:
			break;
			
		default:
 			printf("Enter an appropriate choice");
			break;
	}

  }while(ch!=6);

  return 0;
}

void begin_cdll(struct node **start,int item)
{
	  if((*start)==NULL)
   {	
  	*start=getnode(item);
  	(*start)->next=*start;
  	(*start)->prev=*start;
  }
   else
   {
   	struct node *p,*q;
   	q=(*start)->prev;
   	p=getnode(item);
   	p->next=*start;
   	p->prev=q;
   	q->next=(*start)->prev=p;
   	*start=p;
	   
}
}

void end_cdll(struct node **start,int item)
{
	 if((*start)==NULL)
   {	
  	*start=getnode(item);
  	(*start)->next=*start;
  	(*start)->prev=*start;
  } 
  else
  {
  
   struct node *p,*q;
   p=(*start)->prev;
   q=getnode(item);
   q->next=*start;
   q->prev=p;
   p->next=q;
   (*start)->prev=q;
}
}

void printcdll(struct node *start)
{
	struct node *temp;
	temp=start;
 
    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("\t\t%d ", temp->data);
        temp = temp->next;
    }
    printf("\t\t%d ", temp->data);
 
    printf("\nTraversal in reverse direction \n");
    struct node *q = start->prev;
    temp = q;
    while (temp->prev != q)
    {
        printf("\t\t%d ", temp->data);
        temp = temp->prev;
    }
    printf("\t\t%d ", temp->data);
}
struct node *getnode(int item)
{
	struct node *p;
	p=(struct node*) malloc(sizeof(struct node));
	p->data=item;
	p->next=NULL;
	p->prev=NULL;
	return p;
}


void delbeg(struct node **start)
{
	struct node *p,*q;
	p=(*start)->prev;
	q=(*start)->next;
	p->next=q;
	q->prev=p;
	free((*start));
	*start=q;
}

void delend(struct node **start)
{
	struct node *p,*q;
	p=(*start)->prev;
	q=p->prev;
	q->next=*start;
	(*start)->prev=q;
	free(p);
}
