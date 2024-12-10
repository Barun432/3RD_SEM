#include<stdio.h>
#include<stdlib.h>

void bubble(int arr[],int n){
     for(int i=0;i<n;i++){
         for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                // swap(arr[j],arr[j+1]);
                 int temp = arr[j];  
        arr[j] = arr[j + 1];  
        arr[j + 1] = temp;  
            }
         }
     }
}

 int main(){
   
  int n;
  printf("Enter the array element  size:");
  scanf("%d",&n);
  int arr[n];
   printf("enter the array element ");
   for(int i=0;i<n;i++){
   scanf("%d",&arr[i]);
   }
      bubble(arr,n);
      printf(" sorted array: \n");
     for(int i=0;i<n;i++){
    printf("%d", arr[i]);
}
      
 }