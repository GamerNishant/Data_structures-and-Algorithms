#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node* next;
};
typedef struct Node node;

node* Insert(node* s,int a)
{
   node* p;
   node* r;
   node* q=s;
   p=(node*)malloc(sizeof(node));
   p->data=a;
   if(s==NULL)
   {
      s=p;
      p->next=NULL;
   }
   else
   {
      while(q!=NULL && q->data <= a)
      {
         r=q;
         q=q->next;
      }
      if(q==s)
      {
         p->next=s;
         s=p;
      }
      else if(q!=NULL)
      {
         p->next=r->next;
         r->next=p;
      }
      else
      {
         r->next=p;
         p->next=NULL;
      }
   }
   return s;
}

node* Delete(node* s,int a)
{
   node* p=s;
   node* q;
   while(p->next!=NULL && p->data!=a && p->next->data <= a)
   {
      q=p;
      p=p->next;
   }
   if(p->data==a)
   {
      if(p==s)
      {
         s=s->next;
      }
      else
      {
         q->next=p->next;
      }
      free(p);
   }
   return s;
}

void Display(node* s)
{
    node* p;
    if(s==NULL) printf("List is Empty\n");
    else
    {
        p=s;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    } 
}

int Count_node(node* s)
{
    node* p;
    int Count=0;
    p=s;
    while(p!=NULL)
    {
        p=p->next;
        Count++;
    }
    return Count;
}

int Search(node* s,int a)
{
    node* q=s;
    int count=1;
    while(q->next!=NULL && q->data!=a && q->next->data <= a )
    {
        q=q->next;
        count++;
    }
    if(q->data==a) return count;
    else return 0;
}

int main()
{
    int n,a,b;
    node* start;
    start=NULL;
    while(1)
    {
        printf("Enter 1 to Insert\n");
        printf("Enter 2 to Delete a node\n");
        printf("Enter 3 to Display List\n");
        printf("Enter 4 to Count Nodes\n");
        printf("Enter 5 to Search value\n");
        printf("Enter 6 to Exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
               printf("Enter value to Insert\n");
               scanf("%d",&a);
               start=Insert(start,a);
               break;
            }
            case 2:
            {
               if(start==NULL) printf("List is Empty\n");
               else
               {
                  printf("Enter value to Delete\n");
                  scanf("%d",&a);
                  start=Delete(start,a);
               }
               break;
            }
            case 3:
            {
               Display(start);
               printf("\n");
               break;
            }
            case 4:
            {
               printf("Number of nodes %d\n\n",Count_node(start));
               break;
            }
            case 5:
            {
               if(start==NULL) printf("List is Empty\n");
               else
               {
                  printf("Enter value to Search\n");
                  scanf("%d",&a);
                  b=Search(start,a);
                  if(b) printf("Number is Present at %d node\n\n",b);
                  else printf("Not Present\n\n");
               }
               break;
            }
            case 6: return 0;
            default : printf("Enter valid choice\n\n");
        }
    }
}