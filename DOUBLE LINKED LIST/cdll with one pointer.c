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
			printf("\nENTER THE ITEM:");
			scanf("%d",&item);
			begin_cdll(&start,item);	
			break;

		case 2:
			printf("\nENTER THE ITEM:");
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
 			printf("ENTER AN APPROPRIATE CHOICE");
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
   	struct node *p;
   	p=getnode(item);
   	(p->prev)=(*start)->prev;
   	(p->next)=*start;
   	((*start)->prev)->next=p;
   	((*start)->prev)=p;
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
  
   struct node *p;
   p=getnode(item);
   ((*start)->prev)->next=p;
	p->prev=(*start)->prev;
	p->next=*start;
	(*start)->prev=p;
	}
}





void delbeg(struct node **start)
{
	struct node *p;
	p=*start;
	(p->next)->prev=p->prev;
	(p->prev)->next=p->next;
	*start=(*start)->next;
	free(p);
}

void delend(struct node **start)
{
	struct node *p;
	p=(*start)->prev;
	(p->prev)->next=p->next;
	(p->next)->prev=p->prev;
	free(p);
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


void printcdll(struct node *start)
{
	struct node *temp;
	temp=start;
 
    printf("\nCIRCULAR DOUBLY LINKED LIST IN FORWARD DIRECTION \n");
    while (temp->next != start)
    {
        printf("\t\t%d ", temp->data);
        temp = temp->next;
    }
    printf("\t\t%d ", temp->data);
 
    printf("\nCIRCULAR DOUBLY LINKED LIST IN REVERSE DIRECTION  \n");
    struct node *q = start->prev;
    temp = q;
    while (temp->prev != q)
    {
        printf("\t\t%d ", temp->data);
        temp = temp->prev;
    }
    printf("\t\t%d ", temp->data);
}
