#include<stdlib.h> 
#include<stdio.h> 
  
#define Max_size 10

int min(int x, int y) { return (x<y)? x :y; } 
  

int merge(int* arr,int left,int mid,int right,int size)
{
	int arr2[size];
	int i;
	int j;
	int k;

	//copying elements from arr to arr2
	for(i=left;i<=right;i++)
	{
		arr2[i]=arr[i];
	}
	i=left;
	j=mid+1;
	k=left;

	//checking each element
	while(i<=mid && j<=right)
	{
		if(arr2[i]>=arr2[j])
		{
			arr[k]=arr2[j];
			j++;
			k++;
		}
		else
		{
			arr[k]=arr2[i];
			i++;
			k++;
		}
	}

	while(i<=mid)
	{
		arr[k]=arr2[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		arr[k]=arr2[j];
		k++;
		j++;
	}
}
  
void mergeSort(int* arr,int size) 
{ 
   int curr_size;

   int left_start; 
   for (curr_size=1; curr_size<=size-1; curr_size = 2*curr_size) 
   { 
       for (left_start=0; left_start<size-1; left_start += 2*curr_size) 
       { 
           int mid = min(left_start + curr_size - 1, size-1); 
           int right_end = min(left_start + 2*curr_size - 1, size-1); 
           merge(arr, left_start, mid, right_end,size); 
       } 
       for(int i=0;i<size;i++)
	    {
	    	printf("%d ",arr[i]);
	    }
	    printf("\n");
   } 
} 
   
/* Driver program to test above functions */
int main() 
{ 
    int arr[Max_size]; 
    int i;
    int size;
    printf("Enter size of array: \n");
    scanf("%d",&size);
    printf("Enter elements of array\n");
    for(i=0;i<size;i++)
    {
    	scanf("%d",&arr[i]);
    } 
    mergeSort(arr,size); 
    printf("\n");
    return 0;
}
