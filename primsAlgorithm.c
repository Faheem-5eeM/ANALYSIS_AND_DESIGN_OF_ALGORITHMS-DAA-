#include<stdio.h>
#include<stdlib.h>
int i,j,n,u,v,min,mincost = 0, cost[10][10],visited[10] = {0},a,b,ne=1;
void prims(int);
void prims(int n)
{
     visited[1] = 1;
     while(ne < n)
     {
          for(i = 1, min =999;i<=n;i++)
          {
               for(j = 1;j<=n;j++)
               {
                    if (visited[i] && !visited[j] && cost[i][j] < min)
                    {
                          min = cost[i][j];
                          a = u =i;
                          b = v =j;
                    }
               }
          }
          if(visited[u]==0 || visited[v]==0)
          {
               printf("\n%d. Edge (%d,%d) = %d",ne++,a,b,min);
               mincost = mincost + min;
               visited[b] = 1;
          }
          cost[a][b] = cost[b][a] = 999;
          
     }
     printf("\nMinimum cost - %d", mincost);
}

int main()
{
      printf("\nPRIMS ALGORITHM - FOR FINDING MINIMUM SPANNING TREE:\n\n");
      printf("\nEnter no of nodes:\n");
      scanf("%d",&n);

      printf("\nEnter the cost adjacency matrix:\n");
      for(i=1;i<=n;i++)
      {
           for(j=1;j<=n;j++)
           {
                scanf("%d",&cost[i][j]);
                if(cost[i][j]==0)
                {
                     cost[i][j] = 999;
                }
           }
      }

      printf("\nGiven Adjacency matrix is :\n");
      for(i=1;i<=n;i++)
      {
           for(j=1;j<=n;j++)
           {
                printf("%d\t",cost[i][j]);
           }
           printf("\n");
      }      

      prims(n);
      return 0;

}