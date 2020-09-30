#include<stdio.h>
//max size for row and column of matrix
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

//Read matrix in normal form and store it in sparse matrix form  
void readMatrix(struct sparse* x)
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
   printf("\n");
}
//Take sparse matrix as argument and print it in form 0f normal matrix  
void printMatrix(struct sparse a)
{
   int i,j,k=0;
   if(a.nz==-1) printf("Matrix is empty\n");
   else
   {
      for(i=0;i<a.nrows;i++)
      {
         for(j=0;j<a.ncols;j++)
         {
            if(a.row[k]==i && a.col[k]==j)
            {
               printf("%d ",a.value[k]);
               k++;
            }
            else printf("0 ");
         }
         printf("\n");
      }
   }
   printf("\n\n");
}

//Display sparse matrix
void Display_Sparse(Sparse e)
{  int i;
   printf("Row\tcol\tvalue\n");
   for(i = 0; i< e.nz; i++)
   { 
         printf("%d\t%d\t%d\n", e.row[i],e.col[i],e.value[i]);   
   }
}

//take sparse matrix as argument,compute transpose using counting sort method and return transpose
struct sparse Transpose(struct sparse a)
{
   struct sparse b;
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
//take 2 sparse matrix as argument and return product of these matrix
struct sparse Multiply(struct sparse a, struct sparse b)
{
   struct sparse c;
   int k=0,i=0,j,total=0,a_row,b_row,x,y;
   //check whether matrixs can be multiplied or not
   if(a.ncols!=b.nrows)
   {
      c.nz=-1;
      return c;
   }
   c.nrows=a.nrows;
   c.ncols=b.ncols;
   b=Transpose(b);
   while(i<a.nz)
   {
      a_row=a.row[i];
      j=0;
      while(j<b.nz)
      {
         b_row=b.row[j];
         
         x=i;
         y=j;
         total=0; 
         while(x<a.nz && a.row[x]==a_row && b.row[y]==b_row)
         {
            if(a.col[x]<b.col[y])
            {
               x++;
            }
            else if(a.col[x]>b.col[y])
            {
               y++;
            }
            else
            {
               total+=a.value[x]*b.value[y];
               x++;
               y++;
            }
         }
         
         if(total!=0)
         {
            c.row[k]=a_row;
            c.col[k]=b_row;
            c.value[k]=total;
            k++;
         }
         while(j<b.nz && b.row[j]==b_row)
         {
            j++;
         }
      }
      while(i<a.nz && a.row[i]==a_row)
      {
            i++;
      }
   }
   c.nz = k;
   return c;

}

int main()
{
   struct sparse a,b,c;
   printf("For 1st matrix:\n");
   readMatrix(&a);
   printf("For 2nd matrix:\n");
   readMatrix(&b);
   c=Multiply(a,b);
   printf("Matrix A :\n");
   printMatrix(a);
   printf("Matrix B :\n");
   printMatrix(b);
   printf("Product of A and B :\n");
   printMatrix(c);
   return 0;
}