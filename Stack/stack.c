#include<stdio.h>

//size of stack
#define size 10

struct stack
{
	int arr[size];
	int top;
};

typedef struct stack Stack;

//push function
void Push(Stack* s,int a)
{
	//checking whether stack is full or not
	if(s->top==size-1) printf("Stack is full\n\n");
	else
	{
		s->top++;
		s->arr[s->top]=a;
		printf("\n\n");
	}
}

//pop function
void Pop(Stack* s)
{
	//checking whether stack is empty or not
	if(s->top==-1) printf("Stack is empty\n");
	else
	{
		printf("Deleted number is %d\n\n",s->arr[s->top]);
		s->top--;
	}
}

//display function
void Display(Stack s)
{
	int i;
	//checking whether stack is empty or not
	if(s.top==-1) printf("Stack is empty\n\n");
	else
	{
		printf("Stack is: \n");
		for(i=s.top;i>=0;i--)
		{
			printf("%d\n",s.arr[i]);
		}
		printf("\n\n");
	}
}

int main()
{
	Stack s;
	s.top=-1;
	int n;
	int a;
	while(1)
	{
		//choices for user
		printf("Press 1 for Push\n");
		printf("Press 2 for Pop\n");
		printf("Press 3 for Display\n");
		printf("Press 4 for Exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				printf("Enter a number to Push\n");
				scanf("%d",&a);
				Push(&s,a);
				break;
			}
			case 2:
			{
				Pop(&s);
				break;
			}
			case 3:
			{
				Display(s);
				break;
			}
			case 4:
				return(0);
			default:
				printf("Enter a valid choice\n");
		}
	}
}