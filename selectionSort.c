#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[],int n)
{
       int min, i , j;
       for(i=0;i<n-1;i++)
       {
            min = i;
            for(j=i+1;j<n;j++)
            {
                 if(arr[j] < arr[min])
                 {
                     min = j;
                 }
            }
            swap(&arr[min],&arr[i]);
       }
}

void generateRandomNo(int n)
{
      FILE*file = fopen("selectionSORT.txt","w");
      srand(time(NULL));
      for(int i=0;i<n;i++)
      {
           fprintf(file,"%d\n",rand());
      }
      fclose(file);
}

int main()
{
     int n =35000;
     int*numbers = (int*)malloc(n*sizeof(int));
     generateRandomNo(n);

     FILE*file = fopen("selectionSORT.txt","r");
     for(int i=0;i<n;i++)
     {
           fscanf(file,"%d",&numbers[i]);
     }
     fclose(file);

     clock_t start = clock();
     selectionSort(numbers,n);
     clock_t end = clock();

     double elapsed_time = (double) (end - start)/CLOCKS_PER_SEC;

     printf("No of time required to sort %d elements using selection sort is %.10f : ",n,elapsed_time);

     free(numbers);

}
