#include<stdio.h>

#define size 5

struct queue
{
    int Q[size];
    int front;
    int rear;
};

typedef struct queue Queue;

int isEmpty(Queue q)
{
    if(q.rear==q.front) return 1;
    else return 0;
}

int isFull(Queue q)
{
    if(q.front==(q.rear+1)%size) return 1;
    else return 0;
}

void Insert(Queue* q,int x)
{
    q->rear=(q->rear+1)%size;
    q->Q[q->rear]=x;
}

int Delete(Queue* q)
{
    int x;
    q->front=(q->front+1)%size;
    x=q->Q[q->front];
    return x;
}

void Display(Queue q)
{
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        i=(i+1)%size;
    }while(i!=(q.rear+1)%size);
    printf("\n\n");
}

int main()
{
    int n;
    int a;
    Queue q1;
    q1.front=0;
    q1.rear=0;
    while(1)
    {
        printf("Press 1 to Insert\n");
        printf("Press 2 to Delete\n");
        printf("Press 3 to Display\n");
        printf("Press 4 to Exit\n\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
                if(isFull(q1)) printf("Queue is full\n\n");
                else
                {
                    printf("Enter Number to Insert\n");
                    scanf("%d",&a);
                    Insert(&q1,a);

                }
                break;
            }
            case 2:
            {
                if(isEmpty(q1)) printf("Queue is Empty\n\n");
                else printf("Deleted number is: %d\n\n",Delete(&q1));
                break;
            }
            case 3:
            {
                if(isEmpty(q1)) printf("Queue is Empty\n\n");
                else Display(q1);
                break;
            }
            case 4:
            {
                return 0;
            }
            default: printf("Enter valid choice\n\n");
        }
    }
}