#include<stdio.h>
#include<stdlib.h>
//size of array
#define size 10
//Index counter for array
int counter=-1;

//function prototype
int get_index(int* , int ,int);
void Insert(int*,int);
void Delete(int* ,int );
void Search(int* ,int );
void Display(int*);


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
				printf("%d\n",arr[0]);
				break;
			}
			case 6:
			{
				printf("%d\n",arr[counter]);
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

//To get index oint get_index(int* arr,int a,int r);f number
int get_index(int* arr,int a,int r)
{
	int i;
	for(i=0;i<=r;i++)
	{
		if(a<=arr[i])
		{
			return i;
		}
	}
}

//for Insert item
void Insert(int* arr,int a)
{
	int i;
	//for index of new item
	int index=-1;
	if(counter==-1)
	{
		counter++;
		arr[counter]=a;
	}
	else
	{
		index=get_index(arr,a,counter);
		if(index==-1)
		{
			counter++;
			arr[counter]=a;
		}
		else if(counter!=size-1)
		{
			for(i=counter+1;i>index;i--)
			{
				arr[i]=arr[i-1];
			}
			arr[index]=a;
			counter++;
		}
		else if(counter==size-1)
		{
			printf("No Space in the list\n");
		}
	}
}

//for Delete item
void Delete(int* arr,int pos)
{
	int i;
	if(pos>-1 && pos<=counter)
	{
		// arr[pos]=arr[counter];
		for(i=pos;i<=counter;i++)
		{
			arr[i]=arr[i+1];
		}
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