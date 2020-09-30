#include<stdio.h>
#include<string.h>

//size of stack
#define size 1000

struct stack
{
   int arr[size];
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
int Pop(Stack* s)
{
   //checking whether stack is empty or not
   if(s->top==-1) return 0;
   else
   {
      s->top--;
      return s->arr[s->top+1];
   }
}
//to get value of operand
int value(char c)
{
   switch(c)
   {
      case 'a': return 2;
      case 'b': return 5;
      case 'c': return 10;
      case 'd': return 15;
   }
}
//to confirm whether term is operand or not
int isOperand(char c)
{
   if(c<='d' && c>='a') return 1;
   else return 0;
}

//to confirm whether term is operator or not
int isOperator(char c)
{
   if(c=='+' || c=='-' || c=='/' || c=='*') return 1;
   else return 0;
}

int evaluate(int a, int b, char k)
{
   if(k =='+') return (a+b);
   else if(k =='-') return (a-b);
   else if(k =='/') return (a/b);
   else if(k =='*') return (a*b);
}

int main()
{
   char str[size];
   Stack s;
   s.top=-1;
   int i,u;
   int j;
   int k;
   printf("Use only lowercase alphabet\na=2, b=5, c=10, d=15\nEnter expression:\n");
   scanf("%s",str);
   for(i=0;i<strlen(str);i++)
   {
      if(isOperand(str[i])) Push(&s,value(str[i]));
      else if(isOperator(str[i]))
      {
         u=Pop(&s);
         j=Pop(&s);
         k=evaluate(j,u,str[i]);
         Push(&s,k);
      }
      else
      {
         printf("Not a valid input\n");
         return 0;
      }
   }
   printf("%d\n",s.arr[s.top]);
}