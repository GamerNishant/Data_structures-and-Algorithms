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

void Display_Sparse(Sparse e)
{  int i;
   printf("Row\tcol\tvalue\n");
   for(i = 0; i< e.nz; i++)
   { 
         printf("%d\t%d\t%d\n", e.row[i],e.col[i],e.value[i]);   
   }
}

Sparse Transpose(Sparse a)
{
   Sparse b;
   b.ncols=a.nrows;
   b.nrows=a.ncols;
   b.nz=a.nz;
   int c[a.ncols];
   int t[a.ncols];
   int i;
   for(i=0;i<a.nz;i++)
   {
      c[i]=0;
   }
   for(i=0;i<a.nz;i++)
   {
      c[a.col[i]]=c[a.col[i]]+1;
   }
   t[0]=0;
   for(i=1;i<a.ncols;i++)
   {
      t[i]=t[i-1]+c[i-1];
   }
   for(i=0;i<a.nz;i++)
   {
      b.row[t[a.col[i]]]=a.col[i];
      b.col[t[a.col[i]]]=a.row[i];
      b.value[t[a.col[i]]]=a.value[i];
      t[a.col[i]]=t[a.col[i]]+1;
   }
   return b;
}

int main()
{
   Sparse a,b;
   convert_to_Sparse(&a);
   b=Transpose(a);
   printf("Given Matrix :\n");
   Display_Sparse(a);
   printf("Transpose of given Matrix :\n");
   Display_Sparse(b);
   return 0;
}