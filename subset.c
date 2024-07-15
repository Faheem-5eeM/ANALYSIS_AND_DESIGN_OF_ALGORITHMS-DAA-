#include<stdio.h>
int set[20],s[20], count = 0,sum = 0,d,n,flag =0;
void display(int);
int subset(int,int);
void main()
{
     printf("\nEnter the no of elements is set:\n");
     scanf("%d",&n);
     printf("\nEnter the set elements :\n");
     for(int i=0;i<n;i++)
     {
         scanf("%d",&s[i]);
     }
     printf("\nEnter the SUM value :\n");
     scanf("%d",&d);
     subset(0,0);

     if(flag == 0)
     {
         printf("\nThere is no solution\n");
     }
}

int subset(int sum,int i)
{
     if(sum == d)
     {
         display(count);
         flag = 1;
         return 1;
     }

     if(sum>d || i>=n)
     {
        return 0;
     }

     else
     {
         set[count] = s[i];
         count++;
         subset(s[i]+sum,i+1);
         count--;
         subset(sum,i+1);
     }

}

void display(int count)
{
     int i;
     printf("\t {");
     for(i=0;i<count;i++)
     {
         printf("%d ,",set[i]);
     }
     printf("}");
}