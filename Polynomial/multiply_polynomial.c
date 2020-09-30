#include<stdio.h>
#define size 20
struct polynomial
{
	int coef;
	int expo;
};

typedef struct polynomial Polynomial;

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

int addition(Polynomial p1[],Polynomial p2[],int t1,int t2)
{
	Polynomial p3[size];
	int i=0;
	int j=0;
	int k=0;
	while(i<t1 && j<t2)
	{
		if((p1[i].expo) == (p2[j].expo))
		{
			p3[k].coef = p2[j].coef + p1[i].coef;
			p3[k].expo = p1[i].expo;
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
		else
		{
			p3[k].expo = p1[i].expo;
			p3[k].expo = p1[i].expo;
			k++;
			i++;
		}
	}
	while(i<t1)
	{
		p3[k].expo = p1[i].expo;
		p3[k].coef = p1[i].coef;
		i++;
		k++;
	}
	while(j<t2)
	{
		p3[k].expo = p2[j].expo;
		p3[k].coef = p2[j].coef;
		j++;
		k++;
	}
	
	for(i=0;i<k;i++)
	{
		p2[i].coef = p3[i].coef;
		p2[i].expo = p3[i].expo;
	}
	
	return k;
}


int multiply(Polynomial p1[],Polynomial p2[],Polynomial p3[],int t1,int t2)
{
	Polynomial p4[size],p5[size];
	int i=0;
	int k=0;
	
	while(i<t1)
	{
		int j=0;
		while(j<t2)
		{
			p4[j].coef = (p1[i].coef)*(p2[j].coef);
			p4[j].expo = (p1[i].expo)+(p2[j].expo);
			j++;
		}
		k = addition(p4,p5,j,k);
		i++;
	}
	for(i=0;i<k;i++)
	{
		p3[i].coef = p5[i].coef;
		p3[i].expo = p5[i].expo;
	}
	return k;
	
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
	int i,j,k;
	printf("Enter no. of terms in 1st polynomial : ");
	scanf("%d",&i);
	printf("\n");
	printf("Enter no.of terms in 2nd polynomial : ");
	scanf("%d",&j);
	printf("\n First polynomial \n");
	input(p1,i);
	printf("\n Second polynomial \n");
	input(p2,j);
	k = multiply(p1,p2,p3,i,j);
	printf("\n Resultant polynomial \n");
	display(p3,k);
	
	return 0;
}
