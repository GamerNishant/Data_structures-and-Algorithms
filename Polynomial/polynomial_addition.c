#include<stdio.h>
#define size 20
struct polynomial{
	int coef;
	int expo;
};

typedef struct polynomial Polynomial;

int addpolynomial(Polynomial p1[] , Polynomial p2[] , Polynomial p3[] , int t1 , int t2)
{
	int i=0;
	int j=0;
	int k=0;
	
	while(i<t1 && j<t2)
	{
		if(p1[i].expo == p2[j].expo)
		{
			p3[k].expo = p1[i].expo;
			p3[k].coef = p1[i].coef + p2[j].coef; 
			i++;
			j++;
			k++;
		}
		
		else if(p1[i].expo < p2[j].expo)
		{
			p3[k].expo = p2[j].expo;
			p3[k].coef = p2[j].coef;
			k++;
			j++;
		}
		else{
			p3[k].expo = p1[i].expo;
			p3[k].coef = p1[i].coef;
			k++;
			i++;	
		}
	}
	while(i<t1)
	{
		p3[k].expo = p1[i].expo;
		p3[k].coef = p1[i].coef;
		k++;
		i++;
	}
	while(j<t2){
		p3[k].expo = p2[j].expo;
		p3[k].coef = p2[j].coef;
		k++;
		j++;
	}
	return k;
}

void input(Polynomial p[],int t)
{
	int i;
	printf("Enter the Coefficient : ");
	for(i=0;i<t;i++)
	{
		scanf("%d",&p[i].coef);
	}
	printf("Enter the Exponent : ");
	for(i=0;i<t;i++)
	{
		scanf("%d",&p[i].expo);
	}
}

void display(Polynomial p[],int t)
{
	int i;
	for(i=0;i<t;i++)
	{
		// printf("Coefficient(%d) : %d\n",i+1,p[i].coef);
		// printf("Exponent(%d) : %d\n",i+1,p[i].expo);
		printf("(%d)x^%d ",p[i].coef,p[i].expo);
	}
	printf("\n");
}
int main()
{
	
	Polynomial p1[size],p2[size],p3[size];
	int t1,t2,t3;
	printf("Enter no. of terms in 1st polynomial : ");
	scanf("%d",&t1);
	printf("Enter no. of terms in 2nd polynomial : ");
	scanf("%d",&t2);
	printf("\n 1st polynomial \n");
	input(p1,t1);
	printf("\n 2nd polynomial \n");
	input(p2,t2);
	t3 = addpolynomial(p1,p2,p3,t1,t2);
	display(p3,t3);
	
	return 0;
}
