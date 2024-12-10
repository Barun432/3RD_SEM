#include<stdio.h>
#include<stdlib.h>
   int partition( int arr[], int s , int e){
     int pivot = arr[s];
       int start=s;
       int end =e;
       while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;

        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
       }
       swap(arr[s],arr[end]);
       return end;
   }

  void quicksort(int arr[], int s , int e){
    // base  case
    if(s<=e)
    return;
    // partition krenge
    int p = partition(arr,s,e);

    // left part sort karo
    quicksort(arr,s,p-1);
    // right part wla sort kro
    quicksort(arr,p+1,e);
  }

 int main(){
     int n;
      printf("Enter the array size :");
      scanf("%d",&n);
      int arr[n];
       printf("Enter the array elemnent:");
       for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
       }
        quicksort(arr,0,n-1);
   printf("sorted array :\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
 return 0;
 }