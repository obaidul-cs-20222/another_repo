#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
struct node *getnode(int item)
{
  struct node *p;
  p=(struct node *) malloc(sizeof(struct node));
  p->data=item;
  p->prev=NULL;
  p->next=NULL;
  return p;
}
void sortedDLL(struct node **start,int item)
{
struct node *p,*q,*temp;
temp=getnode(item);
if(*start==NULL)
{
*start=temp;
}
else
{
q=NULL;
p=*start;	
while(item>p->data)
{
q=p;
p=p->next;
if(p==NULL)
break;
}
if(q==NULL)
{
temp->next=*start;
(*start)->prev=temp;
*start=temp;
}
else if(q!=NULL && p==NULL)
{
q->next=temp;
temp->prev=q;
}
else
{
q->next=temp;
temp->prev=q;
temp->next=p;
p->prev=temp;
}
}
}
void printDLL(struct node *start)
{
struct node *p;
p=start;
printf("\n HERE IS YOUR SORTED DOUBLY LINKED LIST:\n");

while(p!=NULL)
{
printf("\t%d",p->data);
p=p->next;
}
}
void midDLL(struct node *start)
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
printf("\nTHE VALUE OF THE MIDDLE NODE IN THE SORTED DOUBLY LINKED LIST IS %d AT POSITON %d",q->data,(m+1)/2);
}
void main()
{
struct node *start=NULL;
int i=1,ch,item;
do
{
printf("\n\nPRESS 1 FOR INSERTION\nPRESS 2 FOR DISPLAY THE SORTED LINKED LIST\nPRESS 3 FOR THE MID VALUE OF THE SORTED DOUBLY LINKED LIST\nPRSS 4 FOR EXIT\n");
printf("\nENTER YOUR CHOICE\t:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n ENTER THE VALUE OF THE NODE at pos %d:",i);
scanf("%d",&item);
sortedDLL(&start,item); i++;
break;
case 2:
printDLL(start);
break;
case 3:
midDLL(start);
break;
case 4:
exit(0);	
break;
default :
printf("\n ENTER AN APPROPRIATE CHOICE\n");
}
}
while(ch!=4);
free(start);
}

