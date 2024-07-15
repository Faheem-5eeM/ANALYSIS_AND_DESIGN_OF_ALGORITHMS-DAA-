#include<stdio.h>
int max(int a,int b)
{
     if(a>b)
        return a;
    else 
        return b;
}

int knapsack(int W,int val[],int wt[],int n)
{
     int i,w;
     int K[n+1][W+1];
     for(i=0;i<=n;i++)
     {
         for(w=0;w<=W;w++)
         {
               if(i==0||w==0)
               {
                   K[i][w] = 0;
               }
               else if(wt[i-1]<=w)
               {
                     K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);
               }
               else
                   K[i][w] = K[i-1][w];
         }
     }
     return K[n][W];
}

int main()
{
      int val[10], W,n,wt[10];
      printf("\nEnter no of Items:\n");
      scanf("%d",&n);
      printf("\nEnter the Value and its Weight for %d items:\n",n);
      for(int i=0;i<n;i++)
      {
                scanf("%d%d",&val[i],&wt[i]);
      }
      printf("\nEnter the Size of KnapSack:\n");
      scanf("%d",&W);
      printf("\nProfit of %d items is : %d ",n,knapsack(W,val,wt,n));
      return 0;

}

