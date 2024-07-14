#include<stdio.h>
#include<stdlib.h>
int i,j,u,v,a,b,min,n,ne = 1;
int cost[10][10], mincost = 0,parent[10];
int find(int);
int uni(int , int);
int main()
{
       printf("KRUSKALS ALGORITHM - FOR FINDING MINIMUM SPANNING TREE:\n\n");
       printf("\nEnter no of vertices:\n");
       scanf("%d",&n);
       printf("\nEnter the Adjacency Matrix:\n");
       for(i=1;i<=n;i++)
       {
            for(j=1;j<=n;j++)
            {
                 scanf("%d",&cost[i][j]);
                 if(cost[i][j] == 0)
                 {
                     cost[i][j] = 999;
                 }
            }
       }
       printf("\n******FINAL MST******\n");
       printf("\n The Edges of Minimum cost spanning Tree are :\n");

       while(ne < n)
       {
            for(i=1,min = 999;i<=n;i++)
            {
                  for(j=1;j<=n;j++)
                  {
                        if(cost[i][j] < min)
                        {
                              min = cost[i][j];
                              a = u = i;
                              b = v = j;
                        }
                  }
            }
            u = find(u);
            v = find(v);
            if(uni(u,v))
            {
                 printf("\n%d. Edge ( %d , %d) is : %d",++ne,a,b,min);
                 mincost = mincost + min;
            }
            cost[a][b] = cost[b][a] = 999;
       }
       printf("\nMinimum Spanning Treee cost is : %d",mincost);

}

int find(int i)
{
      while(parent[i])
      {
          i = parent[i];
      }
      return i;
}
int uni(int i,int j)
{
     if(i != j)
     {
          parent[j] = i;
          return 1;
     }
     return 0;
}