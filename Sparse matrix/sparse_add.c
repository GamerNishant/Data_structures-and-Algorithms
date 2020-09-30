#include<stdio.h>
#define size 10

struct sparse
{
   int nrows;
   int ncols;
   int nz;
   int row[size];
   int col[size];
   int value[size];
};
typedef struct sparse Sparse;

//Convert normal matrix into sparse  
void convert_to_Sparse(Sparse* x)
{
   int i,j,a,m,n;
   printf("Enter number of rows and column of matrix\n");
   scanf("%d%d",&x->nrows,&x->ncols);
   printf("Enter elements of matrix (row by row):\n");
   m=0;
   for(i=0;i<x->nrows;i++)
   {
      for(j=0;j<x->ncols;j++)
      {
         scanf("%d",&a);
         if(a!=0)
         {
            x->row[m]=i;
            x->col[m]=j;
            x->value[m]=a;
            m++;
         }
      }
   }
   x->nz=m;
}

//add 2 sparse matrix
Sparse Add_Sparse(Sparse a,Sparse b)
{
   Sparse c;
   int i,j,k;
   i=0;
   j=0;
   k=0;
   while(i<a.nz && j<b.nz)
   {
      // Check whether row and col of 2 matrix are equal or not
      if(a.row[i]==b.row[j] && a.col[i]==b.col[j])
      {
         //check sum of value of 2 sparse matrix is 0 or not
         if(a.value[i]+b.value[j]!=0)
         {
            c.row[k]=a.row[i];
            c.col[k]=a.col[i];
            c.value[k]=a.value[i]+b.value[j];
            k++;
         }
         i++;
         j++;
      }
      else if(a.row[i]<b.row[j] || a.row[i]==b.row[j] && a.col[i]<b.col[j])
      {
         c.row[k]=a.row[i];
         c.col[k]=a.col[i];
         c.value[k]=a.value[i];
         k++;
         i++;
      }
      else
      {
         c.row[k]=b.row[j];
         c.col[k]=b.col[j];
         c.value[k]=b.value[j];
         k++;
         j++;
      }
   }
   //copying remaining elements from Sparse
   while(i<a.nz)
   {
      c.row[k]=a.row[i];
      c.col[k]=a.col[i];
      c.value[k]=a.value[i];
      k++;
      i++;  
   }
   while(j<b.nz)
   {
      c.row[k]=b.row[j];
      c.col[k]=b.col[j];
      c.value[k]=b.value[j];
      k++;
      j++;
   }
   c.ncols=a.ncols;
   c.nrows=a.nrows;
   c.nz=k;
   return(c);
}
/*Funtion to display the sparse matrices*/
void Display_Sparse(Sparse e)
{  int i;
   printf("Row\tcol\tvalue\n");
   for(i = 0; i< e.nz; i++)
   { 
         printf("%d\t%d\t%d\n", e.row[i],e.col[i],e.value[i]);   
   }
   // printf("%d\n",e.nz );
}

int main()
{
   Sparse a,b,c;
   printf("For 1st matrix:\n");
   convert_to_Sparse(&a);
   printf("For 2nd matrix:\n");
   convert_to_Sparse(&b);
   c=Add_Sparse(a,b);
   printf("Matrix A :\n");
   Display_Sparse(a);
   printf("Matrix B :\n");
   Display_Sparse(b);
   printf("Sum of A and B :\n");
   Display_Sparse(c);
   return 0;
}
