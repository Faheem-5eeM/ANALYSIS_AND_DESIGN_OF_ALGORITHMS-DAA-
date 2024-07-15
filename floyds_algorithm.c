#include<stdio.h>
int min(int a,int b)
{
     if(a<b)
     {
         return a;
     }
     else
     {
         return b;
     }
}

void floyds(int p[10][10],int n)
{
      int i,j,k;
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               for(k=1;k<=n;k++)
               {
                   if(i==j)
                   {
                       p[i][j] = 0;
                   }
                   else
                   {
                       p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
                   }
               }
          }
      }
}

void main()
{
      int i,j,k,n,p[10][10],e,u,v,w;
      printf("\nEnter no of vertices:\n");
      scanf("%d",&n);
      printf("\nEnter the no of edges:\n");
      scanf("%d",&e);

      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               p[i][j] = 999;
          }
      }

      for(i=1;i<=e;i++)
      {
           printf("\nEnter the end vertices of %d with weight: ",i);
           scanf("%d %d %d",&u,&v,&w);
           p[u][v] = w;
      }

      printf("\nInput Matrix is:\n");
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               printf("%d\t",p[i][j]);
          }
          printf("\n");
      }

      floyds(p,n);
      printf("\nTransitive Matrix is :\n");
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               printf("%d\t",p[i][j]);
          }
          printf("\n");
      }
      
      printf("\nShortest Path's are:\n");
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               if(i!=j)
               {
                   printf("\n%d,%d -> %d",i,j,p[i][j]);
               }
          }
      }
      
}