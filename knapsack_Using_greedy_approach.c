#include<stdio.h>
int main()
{
     int i,j,n;
     float capacity,ratio[20],profit[20],weight[20],totalVal = 0,temp;
     printf("\nEnter no of Items :\n");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
              printf("\nEnter the weight and profit for item [%d]: ",i+1);
              scanf("%f %f",&weight[i],&profit[i]);
     }

     printf("\nEnter the Knapscak Capacity:\n");
     scanf("%f",&capacity);

     for(i=0;i<n;i++)
     {
         ratio[i] = profit[i]/weight[i];
     }

     for(i=0;i<n;i++)
     {
        for(j=i+1;j<n;j++)
        if(ratio[i] < ratio[j])
        {
             temp = profit[j];
             profit[j] = profit[i];
             profit[i] = temp;

             temp = weight[j];
             weight[j] = weight[i];
             weight[i] = temp;

             temp = ratio[j];
             ratio[j] = ratio[i];
             ratio[i] = temp;
        }
     }        

     for(i=0;i<n;i++)
     {
         if(weight[i]>capacity)
         {
           break;
         }
         else
         {
             totalVal = totalVal + profit[i];
             capacity = capacity - weight[i];
         }
     }
     if(i<n)
     {
          totalVal = totalVal + (ratio[i]*capacity);
     }
     printf("The profit of %d items is : %f",n,totalVal);

     return 0;
}