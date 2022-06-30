#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define max 10000
void insertion_sort(int arr[],int n)
{
 int i,key,j;
 for(i=1;i<n;i++)
 {
  key=arr[i];
  j=i-1;
 while(j>=0 && arr[j]>key)
  {
    arr[j+1]=arr[j];
     j=j-1;
   }
  arr[j+1]=key;
 }
}

void printarr(int arr[],int n)
{
 int i;
 printf("Sorted elements are:");
 for(i=0;i<n;i++)
 printf(" %d",arr[i]);
}

int main()
{
 int n;
double time_taken,clocks_per_sec=1000000;
clock_t start,end;
printf("Enter the size of the array:");
scanf("%d",&n);
int a[n];
printf("Enter the elements:");
 for(int i=0;i<n;i++)
        a[i] = rand()%100;
start=clock();
insertion_sort(a,n);
end=clock();
printarr(a,n);
time_taken=(end-start)/clocks_per_sec;
printf("\nTime taken for sorting %d elements is %f " ,n,time_taken);
return 0;
}
