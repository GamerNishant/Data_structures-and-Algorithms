#include<stdio.h>

//size of stack
#define size 10

struct stack
{
	char arr[size];
	int top;
};

typedef struct stack Stack;

//push function
void Push(Stack* s,int a)
{
	s->top++;
	s->arr[s->top]=a;
}

//pop function
char Pop(Stack* s)
{
	char x;
	x=s->arr[s->top];
	s->top--;
	return x;
}

int isOperand(char c)
{
   if(c<='z' && c>='a') return 1;
   else return 0;
}

int ISP(char c)
{
	switch(c)
	{
		case '+': return 2;
		case '-': return 2;
		case '*': return 4;
		case '/': return 4;
		case '(': return 0;
		// case ')': return ;
		default: return -1;
	}
}
int OSP(char c)
{
	switch(c)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 3;
		case '/': return 3;
		case '(': return 5;
		case ')': return 0;
		default: return -1;
	}
}

int isEmpty(Stack s)
{
	if(s.top==-1) return 1;
	else return 0;
}

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
	char str[size];
	char postfix[size];
	Stack s;
	s.top=-1;
	int i=0;
	int j=0;
	printf("Use only lowercase alphabet\n");
    scanf("%s",str); 
    while(str[i]!='\0')
    {
    	if(isOperand(str[i]))
    	{
    		postfix[j++]=str[i++];
    	}
    	else if(isEmpty(s) && str[i]!=')')
    	{
    		Push(&s,str[i]);
    		i++;
    	}
    	else
    	{
    		if(OSP(str[i])==ISP(s.arr[s.top]))
	    	{
	    		Pop(&s);
	    		i++;
	    	}
	    	else if(ISP(s.arr[s.top])>OSP(str[i]))
	    	{
	    		//Pop(&s);
	    		postfix[j++]=Pop(&s);
	    	}
	    	else if(ISP(s.arr[s.top])<OSP(str[i]))
	    	{
	    		Push(&s,str[i]);
	    		i++;
	    	}
    	}
    	//Display(s);
    }
    while(s.top!=-1)
    {
    	postfix[j++]=Pop(&s);
    }
    postfix[j]='\0';
    printf("%s\n",postfix);
}