#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int count,board[10];
int Queens(int,int);
int place(int,int);
int print(int);
int main()
{
     int i,j,n;
     printf("\nN- QUEENS PROBLEM USING BACKTRACKING:\n\n");
     printf("\nEnter no of Queens\n");
     scanf("%d",&n);
     Queens(1,n);
     return 0;
}

int print(int n)
{
     int i,j;
     printf("\nSOLUTION %d:\n\n\n\n",++count);
     for(i=1;i<=n;i++)
     {
         printf("\t%d",i);
     }
     printf("\n");
     for(i=1;i<=n;i++)
     {
         printf("\n\n%d",i);
         for(j=1;j<=n;j++)
         {
             if(board[i] == j)
             {
                printf("\tQ");
             }
             else
             {
                printf("\t-");
             }
         }
     }
}

int place(int row,int column)
{
     int i,j;
     for(i=1;i<=row-1;i++)
     {
         if(board[i]==column)
         {
            return 0;
         }
         else 
         {
            if(abs(board[i]-column)==abs(i-row))
            {
                return 0;
            }
         }
     }
     return 1;
}


int Queens(int row,int n)
{
     int i,j,column;
     for(column=1;column<=n;column++)
     {
          if(place(row,column))
          {
              board[row] = column;
              if(row==n)
              {
                   print(n);
              }
              else
              {
                 Queens(row+1,n);
              }
          }
     }
}