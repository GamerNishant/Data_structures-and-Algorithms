#include<stdio.h>
#include<string.h>

//Max_size of stack
#define Max_size 1000

struct stack
{
	char arr[Max_size];
	int top;
};

typedef struct stack Stack;

//push function
void Push(Stack* s,char a)
{
	s->top++;
	s->arr[s->top]=a;
}

//pop function
int Pop(Stack* s)
{
	//checking whether stack is empty or not
	if(s->top==-1) return 0;
	else
	{
		s->top--;
	}
	return 1;
}

int main(int argc, char **argv)
{
	char exp[Max_size];
	int size;
	int a;
	int i;
	Stack s;
	s.top=-1;
	printf("Enter expression\n");
	scanf("%s",exp);
	size=strlen(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(') Push(&s,exp[i]);
		else if(exp[i]==')')
		{
			a=Pop(&s);
			if(!a)
			{
				printf("string is not balanced\n");
				return 0;
			}
		}
	}
	if(s.top==-1)
	{
		printf("string is balanced\n");
	}
	else
	{
		printf("string is not balanced\n");
	}
	return 0;
}