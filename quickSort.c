#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int*a,int*b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

int partition(int arr[],int low, int high)
{
      int pivot = arr[low];
      int i = low+1;
      int j = high;

      while(1)
      {
            while(i<=j && arr[i] <= pivot)
              i++;
            while(i<=j && arr[j] >= pivot)
              j--;
            if(i>j)
               break;
            swap(&arr[i],&arr[j]);
      }
      swap(&arr[low],&arr[j]);
      return j;
}

void quickSort(int arr[],int low, int high)
{
      if(low < high)
      {
           int pivotPos = partition(arr,low,high);
           quickSort(arr,low, pivotPos-1);
           quickSort(arr,pivotPos+1,high);
      }
}

void generateRandomNo(int n)
{
      FILE*file = fopen("quickSort.txt","w");
      srand(time(NULL));
      for(int i=0;i<n;i++)
      {
           fprintf(file,"%d\n",rand());
      }
      fclose(file);
}

int main()
{
      int n = 80200;
      generateRandomNo(n);
      int *numbers = (int *)malloc(n * sizeof(int));

      FILE*file = fopen("quickSort.txt","r");
      for(int i=0;i<n;i++)
      {
           fscanf(file,"%d",&numbers[i]);
      }
      fclose(file);
      clock_t  start = clock();
      quickSort(numbers,0,n-1);
      clock_t end = clock();

      double elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;

      printf("No of time taken to execute %d elements using quick sort is : %.6f",n,elapsed_time);

      free(numbers);

    
}