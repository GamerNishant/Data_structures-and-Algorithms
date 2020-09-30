#include<stdio.h>
#include<stdlib.h>
//size of array
const int size=10;
//Index counter for array
int counter=-1;

//functions prototype
void Insert(int* ,int );
void Delete(int* ,int );
void Search(int* ,int );
void Display(int*);
void Findminimum(int*);
void Findmaximum(int* );

int main()
{
	int arr[size];
	int n;
	int a;
	while(1)
	{
		//choices for user
		printf("\nFor Insert press 1\n");
		printf("For Delete press 2\n");
		printf("For Search press 3\n");
		printf("For Display List press 4\n");
		printf("For Findminimum press 5\n");
		printf("For Findmaximum press 6\n");
		printf("For Exit press 7\n");
		printf("Enter your choice: \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				printf("Enter number to Insert\n");
				scanf("%d",&a);
				Insert(arr,a);
				Display(arr);
				break;
			}
			case 2 :
			{
				printf("Enter position of number to Delete\n");
				scanf("%d",&a);
				Delete(arr,a);
				Display(arr);
				break;
			}
			case 3:
			{
				printf("Enter number to Search\n");
				scanf("%d",&a);
				Search(arr,a);
				break;
			}
			case 4:
			{
				Display(arr);
				break;
			}
			case 5:
			{
				Findminimum(arr);
				break;
			}
			case 6:
			{
				Findmaximum(arr);
				break;
			}
			case 7:
			{
				exit(0);
			}
			default:
			{
				printf("Enter valid choice\n");
			}
		}
	}
}

//for Insert item
void Insert(int* arr,int a)
{
	if(counter<size-1)
	{
		counter++;
		arr[counter]=a;
	}
	else
	{
		printf("No Space in the list\n");
	}
}

//for Delete item
void Delete(int* arr,int pos)
{
	if(pos>-1 && pos<=counter)
	{
		arr[pos]=arr[counter];
		counter--;
	}
	else printf("No Element\n");
}

//for search
void Search(int* arr,int a)
{
	int i;
	int n=0;
	for(i=0;i<=counter;i++)
	{
		if(arr[i]==a)
		{
			printf("Element found at pos: %d \n",i);
			n++;
		}
	}
	if(n==0) printf("Element not found\n");
}

//for Display
void Display(int* arr)
{
	int i;
	printf("List :\n");
	for(i=0;i<=counter;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//for minimum
void Findminimum(int* arr)
{
	int i;
	int minimum;
	for(i=0;i<=counter;i++)
	{
		if(i==0) minimum=arr[i];
		else if(arr[i]<minimum) minimum=arr[i];
	}
	printf("%d\n",minimum);
}

//for max
void Findmaximum(int* arr)
{
	int i;
	int maximum;
	for(i=0;i<=counter;i++)
	{
		if(i==0) maximum=arr[i];
		else if(arr[i]>maximum) maximum=arr[i];
	}
	printf("%d\n",maximum );
}