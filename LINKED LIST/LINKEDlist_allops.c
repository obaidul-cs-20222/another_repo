#include<stdio.h>
#include<stdlib.h>
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE node;
node *CREATENODE();  
void traversal(); 
void insertbeginning();
void insertend();
void insertafter(int);
void insertbefore(int);
void deletebeginnig();
void deletelast();
int deletenode(int);
node *start;  


void insertbeginning()
{
	node *p;
	p=CREATENODE();
	if(start==NULL)
	{
		start=p;
	}
	else
	p->next=start;
	start=p;
}
void insertend()
{
	node *p,*q;
	p=CREATENODE();
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
void insertafter(int key)
{
	node *p,*q,*r;
	p=CREATENODE(); 
	if (start== NULL)
	{
		printf ("list is empty :");
		start =p;
	}
	else
	{
		q=start;
		while (q!=NULL && q->info!=key)
		{
			r=q;
			q=q->next;
		}
		if (q!=NULL)
		{
			p->next=q->next;
			q->next=p;
		}
		else
		{
			printf("No such node is found :");
		}
	}
}
void insertbefore(int key)
{
	node *p,*q,*r;
	p=CREATENODE();
	q=start;
	while(q!=NULL && q->info!=key)
	{
		r=q;
		q=q->next;
	}
if(q!=NULL)
{
	r->next=p;
	p->next=q;
}
}
void deletebeginnig()
{
	node *p,*q;
	if(start==NULL)
	{
		printf("empty list");
	}
	else
	{
		p=start;
		start=p->next;
		free(p);
	}
}
void deletelast()
{
	node *p,*q;
	p=start;
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
q->next=NULL;
free(p);
}
int deletenode(int key)
{
	node *p,*q;
	int temp;
	if (start==NULL)
	{
		printf("No such node to delete:");
		exit(1);
		
	}
	else
	{
		p=start;
		while(p!=NULL && p->info!=key)
		{
			q=p;
			p=p->next;
		}
		if (p!=NULL) 
		{
			q->next=p->next;
			temp=p->info;
		}
		else if (p==start)
		{
			start=p->next;
		}
		else
		{
			printf("\n Element not found ");

		}
		free(p);
	}
	return(temp);
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
void reversetraversal()
{
	node *p,*r,*q;
	p=start;
	q=p->next;
	p->next=NULL;
	while(q!=NULL)
	{
		r=q->next;
		q->next=p;
		p=q;
		q=r;
	}
	start=p;
	 printf("\n\n your list in reverse order\n");
		while(p!=NULL)
	{
		printf("%d\t\t",p->info);
		p=p->next;
	}
}

node *CREATENODE()
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->next=NULL; 
	printf ("\n Enter the information :");
	scanf("%d", &p->info);
	return(p);
}
int main()
{
		int n,k,d;
	node *p,*q;
	start=NULL;
	printf("\n Want to create a list :");
	printf("how many node :");
	scanf("%d", &n);
	while(n!=0)
	{
		p=CREATENODE();
		if (start==NULL)
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
		n--;
	}
	char c;
	while(1)
	{
		printf("\na for isertion\n b for deletion\nc for traversal");
		scanf("%c",&c);
		switch(c=getchar())
	{
				case 'a':
				{
				
					do
				{	printf("\n press 1 for insert a node in the  begining of the list\npress  2 for insert a node at the end of the list\npress 3 for insert a node before a particular element\npress 4  for insert a node after a particular node\n 5 to rerutn to the main menu");
					
						scanf("%d",&n);
						switch(n)
					{
						case 1:
							insertbeginning();
							break;
							case 2:
								 insertend();
break;
case 3:
printf("enter the before");
scanf("%d",&k);
insertbefore(k);
break;
case 4:
	printf("entert the after");
	scanf("%d",&d);
	insertafter(d);
	break;
			case 5:
			break;		}
						
					}while(n!=5);
			}
			break;
				
				
				case 'b':
					{
						do
						{
							printf("\n\n press 6 to delete a node at the begining  \npress 7 to delete a node at the end  \n press 8.to delete a particular node\n press 9 to return to the main menu\n");
							scanf("%d",&n);
							switch(n)
							{
									case 6:            
					 deletebeginnig(); 
                    break;
                    case 7:
                    deletelast();
                    break;
                    case 8:
					printf("\n\n enter the node you want to delete");
					scanf("%d",&d);
					printf ("%d is the deleted node ",deletenode(d));
											break;	
																							
								case 9:
									break;
							}
						}while(n!=9);
					}break;
					case 'c':
						{
							do
							{
								printf("\n\npress 10 for traversal  press 11 for reverse traversal press 12 to exit\n\n");
								scanf("%d",&n);
								switch(n)
								{
									case 10 :
					traversal();
					break;
				
					case 11:
				 reversetraversal(); 
			break;
    case 12:
	break;
	
								}
							} while(n!=12);
						}
	default:
		exit(0);
		
	}
	}
}
