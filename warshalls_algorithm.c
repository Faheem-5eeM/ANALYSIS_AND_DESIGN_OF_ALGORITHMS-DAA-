#include<stdio.h>
int max(int a,int b)
{
     if(a>b)
     {
         return a;
     }
     else
     {
         return b;
     }
}

void warshals(int p[10][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    {
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               {
                  p[i][j] = max(p[i][j],p[i][k]&&p[k][j]);
               }
          }
      }
    }
}

void main()
{
      int i,j,k,n,p[10][10] = {0},e,u,v,w;
      printf("\nEnter no of vertices:\n");
      scanf("%d",&n);
      printf("\nEnter the no of edges:\n");
      scanf("%d",&e);


      for(i=1;i<=e;i++)
      {
           printf("\nEnter the end vertices of %d: ",i);
           scanf("%d %d",&u,&v);
           p[u][v] = 1;
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

      warshals(p,n);
      printf("\nTransitive Matrix is :\n");
      for(i=1;i<=n;i++)
      {
          for(j=1;j<=n;j++)
          {
               printf("%d\t",p[i][j]);
          }
          printf("\n");
      }
      
}